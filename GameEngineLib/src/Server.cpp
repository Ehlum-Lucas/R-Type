/*
** EPITECH PROJECT, 2023
** Server.cpp
** File description:
** Server
*/

/**
 * @file Server.cpp
 * @brief This file contains the implementation of the `Server` class.
 */

#include "Server.hpp"

/**
 * The Server constructor initializes a UDP socket and a timer, and starts receiving and sending
 * messages.
 * 
 * @param io_context The `io_context` parameter is an object that provides the I/O functionality for
 * the server. It is responsible for managing asynchronous I/O operations, such as reading and writing
 * data from and to sockets.
 * @param port The "port" parameter is the port number on which the server will listen for incoming UDP
 * messages.
 */

Server::Server(asio::io_context& io_context, short port): _socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)), _timer(io_context, std::chrono::milliseconds(1000/60))
{
    std::cout << "Server starting on port " << port << std::endl;
    message = "";
    start_receive();
    start_send();
}

/**
 * The `start_receive()` function is responsible for asynchronously receiving messages from clients,
 * processing the messages, and updating the server's state accordingly.
 * 
 * @return The function `start_receive()` does not have a return type, so it does not return anything.
 */

void Server::start_receive() 
{
    _socket.async_receive_from(asio::buffer(_recv_buffer), _remote_endpoint, [this](std::error_code ec, std::size_t bytes_transferred) {
        if (!ec) {
            std::string message(_recv_buffer.data(), bytes_transferred);
            std::cout << "Received: " << message << " from " << _remote_endpoint.address().to_string() << ":" << _remote_endpoint.port() << std::endl;

            // Check if th1e client is already in the list
            auto cl = std::find_if(_clients.begin(), _clients.end(), [this](const ServerClient& client) {
                return client.getEndpoint() == _remote_endpoint;
            });

            // If the client is not in the list, add it
            if (cl == _clients.end()) {
                _clients.push_back(ServerClient(_remote_endpoint));

                // Print all client endpoints
                std::cout << "Current client endpoints:\n";
                for (const ServerClient& client : _clients) {
                    std::cout << client.getEndpoint().address().to_string() << ":" << client.getEndpoint().port() << "\n";
                }
            }

            for (auto it = _clients.begin(); it != _clients.end();) {
                if (it->getEndpoint() == _remote_endpoint) {
                    if (message == "OK") {
                        it->connected = true;
                        std::cout << "CLIENT CONNECTED" << std::endl;
                    }
                }
                ++it;
            }

            // Reset the timer for the client
            auto it = std::find_if(_clients.begin(), _clients.end(), [this](const ServerClient& client) {
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
}

/**
 * The start_send() function sends game updates to all connected clients at a rate of 60 updates per
 * second.
 */

void Server::start_send() 
{
    _timer.async_wait([this](std::error_code ec) {
        if (!ec) {
            // Send game update to all clients...
            for (auto& client : _clients) {
                if (client.connected) {
                    if (message != "") {
                        _socket.send_to(asio::buffer(message), client.getEndpoint());
                    }
                } else {
                    std::string id = "YOU ARE p" + std::to_string(_clients.size());
                    std::string client_type = "p" + std::to_string(_clients.size());
                    client.type = client_type;

                    _socket.send_to(asio::buffer(id), client.getEndpoint());
                }
            }

            // Reset the timer
            _timer.expires_after(std::chrono::milliseconds(1000/60));
            start_send();
        }
    });
}