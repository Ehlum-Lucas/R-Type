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

            /// +++

            // for (auto& client : _clients) {
            //     if (client.getEndpoint() == _remote_endpoint) {
            //         if (message == "OK") {
            //             client.connected = true;
            //             std::cout << "CLIENT CONNECTED" << std::endl;
            //         }
            //         if (message == "QUIT") {
            //             std::cout << "CLIENT QUIT" << std::endl;
            //             _game.delete_player(client.entity_id);
            //         }
            //     }
            // }

            if (message.find("MASTER") != std::string::npos) {
                std::size_t colonPos = message.find(":");
                std::size_t semicolonPos = message.find(";");

                if (colonPos != std::string::npos && semicolonPos != std::string::npos && semicolonPos > colonPos + 1) {
                    std::string level = message.substr(colonPos + 1, semicolonPos - colonPos - 1);
                    _in_room = false;
                    _game.run_level(level);
                }
            }

            _inputs_list.push_back(message);

            // Check if th1e client is already in the list
            auto cl = std::find_if(_clients.begin(), _clients.end(), [this](const Client& client) {
                return client.getEndpoint() == _remote_endpoint;
            });

            // If the client is not in the list, add it
            if (cl == _clients.end()) {
                _clients.push_back(Client(_remote_endpoint));

                // Print all client endpoints
                std::cout << "Current client endpoints:\n";
                for (const Client& client : _clients) {
                    std::cout << client.getEndpoint().address().to_string() << ":" << client.getEndpoint().port() << "\n";
                }
            }

            /// +++

            for (auto it = _clients.begin(); it != _clients.end();) {
                if (it->getEndpoint() == _remote_endpoint) {
                    if (message == "OK") {
                        it->connected = true;
                        std::cout << "CLIENT CONNECTED" << std::endl;
                    }
                    if (message == "QUIT") {
                        std::cout << "CLIENT QUIT" << std::endl;
                        it->quit = true;
                        _game.delete_player(it->entity_id);
                        _clients.erase(it);
                        continue;
                    }
                }
                ++it;
            }

            if (_clients.size() == 0) {
                _game.reset();
                std::cout << "RESET" << std::endl;
                next_entity_id = 1;
                next_client_type = 1;
            }

            // Reset the timer for the client
            auto it = std::find_if(_clients.begin(), _clients.end(), [this](const Client& client) {
                return client.getEndpoint() == _remote_endpoint;
            });
            if (it != _clients.end()) {
                it->lastMessageTime = std::chrono::steady_clock::now();
            }

            start_receive();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
    });

    // if (_clients.size() > 0 && !_in_room) {
    //     std::cout << "Starting timer..." << std::endl;
    //     // Check if any client has not sent a message for 5 seconds
    //     std::shared_ptr<asio::steady_timer> timer = std::make_shared<asio::steady_timer>(_socket.get_executor());
    //     timer->expires_after(std::chrono::seconds(10));
    //     timer->async_wait([this, timer](std::error_code ec) {
    //         if (!ec) {
    //             std::cout << "Checking for inactive clients..." << std::endl;
    //             auto currentTime = std::chrono::steady_clock::now();
    //             for (auto it = _clients.begin(); it != _clients.end();) {
    //                 auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - it->lastMessageTime);
    //                 if (elapsedTime >= std::chrono::seconds(10)) {
    //                     std::cout << "Client leave" << std::endl;
    //                     // Perform any necessary cleanup for the client
    //                     // ...
    //                     _game.delete_player(it->entity_id);
    //                     it = _clients.erase(it);
    //                 } else {
    //                     ++it;
    //                 }
    //             }
                    // if (_clients.size() == 0) {
                    //     _game.reset();
                //  next_entity_id = 1;
                    // }
    //         }
    //     });
    // }
}

void Server::game()
{

    for (auto &client : _clients) {
        if (client.connected == false) {
            if (!client.created) {
                client.entity_id = _game.create_player(get_client_type());
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
                if (client.quit) {
                    continue;
                }
                if (client.connected) {
                    // std::cout << "SERIALIZED STRING: " << serializedString << std::endl;
                    _socket.send_to(asio::buffer(serializedString), client.getEndpoint());
                } else {
                    std::string id = "YOU ARE p" + std::to_string(_clients.size());
                    std::string client_type = "p" + std::to_string(_clients.size());
                    client.type = client_type;

                    // std::cout << "Sending: " << id << std::endl;
                    _socket.send_to(asio::buffer(id), client.getEndpoint());
                }
            }

            // Reset the timer
            _timer.expires_after(std::chrono::milliseconds(1000/60));
            start_send();
        }
    });
}