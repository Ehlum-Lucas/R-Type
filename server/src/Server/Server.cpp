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
    _game.setup();
    start_receive();
    start_send();
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

            if (message.find("MASTER") != std::string::npos) {
                std::size_t colonPos = message.find(":");
                std::size_t semicolonPos = message.find(";");

                if (colonPos != std::string::npos && semicolonPos != std::string::npos && semicolonPos > colonPos + 1) {
                    std::string level = message.substr(colonPos + 1, semicolonPos - colonPos - 1);
                    _game.run_level(level);
                }
            }

            _inputs_list.push_back(message);

            // Check if th1e client is already in the list
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
                _game.create_player(get_client_type());
                client.created = true;
            }
        }
    }
    _game.update(_inputs_list);
}

void Server::start_send() 
{

    _timer.async_wait([this](std::error_code ec) {
        if (!ec) {

            game();

            std::vector<std::string> serialized = _game.get_serialized();

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
            _timer.expires_after(std::chrono::milliseconds(1000/60));
            start_send();
        }
    });
}