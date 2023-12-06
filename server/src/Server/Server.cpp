/*
** EPITECH PROJECT, 2023
** Server.cpp
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(asio::io_context& io_context, short port): _socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)), _timer(io_context, std::chrono::milliseconds(1000/60))
{
    std::cout << "Server starting on port " << port << std::endl;
    start_server();
    start_receive();
    start_send();
}

void Server::setup_registry()
{
    _registry.register_component<Position>();
    _registry.register_component<Velocity>();
    _registry.register_component<Drawable>();
    _registry.register_component<Controllable>();
    _registry.register_component<Type>();
    _registry.register_component<Id>();

    int id = 1;
    float y = 45;
    float x = 300;
    std::random_device rd;
    std::mt19937 gen(rd());

    float min = 2000.0f;
    float max = 1000000.0f;

    std::uniform_real_distribution<float> distribution(min, max);

    for (int i = 0; i < 0; i++) {
        _enemies.push_back(_registry.create_entity());
    }

    for (auto& enemy : _enemies) {
        _registry.add_component(enemy, Position{distribution(gen), y});
        _registry.add_component(enemy, Velocity{-10, 0.0});
        _registry.add_component(enemy, Drawable{true});
        _registry.add_component(enemy, Controllable{false});
        _registry.add_component(enemy, Type{"e"});
        _registry.add_component(enemy, Id{enemy.get_id()});
        y += 200;
        if (y > 1000)
            y = 45;
        x += 110;
        id++;
    }
}

void Server::start_server()
{
    setup_registry();
}

void Server::start_receive() 
{
    _socket.async_receive_from(asio::buffer(_recv_buffer), _remote_endpoint, [this](std::error_code ec, std::size_t bytes_transferred) {
        if (!ec) {
            std::string message(_recv_buffer.data(), bytes_transferred);
            std::cout << "Received: " << message << " from " << _remote_endpoint.address().to_string() << ":" << _remote_endpoint.port() << std::endl;

            for (auto& client : _clients) {
                if (client.getEndpoint() == _remote_endpoint) {
                    if (message == "OK") {
                        client.connected = true;
                        std::cout << "CLIENT CONNECTED" << std::endl;
                    }
                }
            }
            _inputs = message;

            // Check if the client is already in the list
            auto it = std::find_if(_clients.begin(), _clients.end(), [this](const Client& client) {
                return client.getEndpoint() == _remote_endpoint;
            });

            // If the client is not in the list, add it
            if (it == _clients.end()) {
                _clients.push_back(Client(_remote_endpoint));

                // Print all client endpoints
                std::cout << "Current client endpoints:\n";
                for (const Client& client : _clients) {
                    std::cout << client.getEndpoint().address().to_string() << ":" << client.getEndpoint().port() << "\n";
                }
            }

            start_receive();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
    });
}

void Server::game()
{

    for (auto &client : _clients) {
        if (client.connected == false) {
            if (!client.created) {
                Entity player = _registry.create_entity();
                _players.push_back(player);
                _registry.add_component(player, Position{100, 100});
                _registry.add_component(player, Velocity{0.0, 0.0});
                _registry.add_component(player, Drawable{true});
                _registry.add_component(player, Controllable{true});
                _registry.add_component(player, Type{"p" + std::to_string(get_client_type())});
                _registry.add_component(player, Id{player.get_id()});
                client.created = true;
            }
        }
    }

    control_system(_registry, _inputs);
    _inputs = "";
    position_system(_registry);
}

void Server::start_send() 
{

    _timer.async_wait([this](std::error_code ec) {
        if (!ec) {

            game();

            std::vector<std::string> serialized = serialize_system(_registry);

            std::string serializedString;
            for (const auto& str : serialized) {
                serializedString += str + ";";
            }
            // std::cout << "Sending: " << serializedString << std::endl;
            // Send game update to all clients...
            for (auto& client : _clients) {
                if (client.connected) {
                    // std::cout << "SERIALIZED STRING: " << serializedString << std::endl;
                    _socket.send_to(asio::buffer(serializedString), client.getEndpoint());
                } else {
                    std::string id = "YOU ARE p" + std::to_string(_clients.size());
                    std::string client_type = "p" + std::to_string(_clients.size());
                    client.type = client_type;

                    std::cout << "Sending: " << id << std::endl;
                    _socket.send_to(asio::buffer(id), client.getEndpoint());
                }
            }

            // Reset the timer
            _timer.expires_after(std::chrono::milliseconds(1000/30));
            start_send();
        }
    });
}