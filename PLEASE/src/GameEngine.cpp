/*
** EPITECH PROJECT, 2023
** GameEngine.cpp
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

void GameEngine::start_send_host()
{
    _timer->async_wait([this](std::error_code ec) {
        if (!ec) {
            for (auto& client : _clients) {
                std::cout << "I SEND SOMETHING TO " << client.getEndpoint().address().to_string() << ":" << client.getEndpoint().port() << std::endl;
                _socket->send_to(asio::buffer("TA GRAND MERE LA REINE DES PUTES"), client.getEndpoint());
            }
            _timer->expires_after(std::chrono::milliseconds(1000/60));
            start_send_host();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
    });
}

void GameEngine::start_receive_host()
{
    _socket->async_receive_from(asio::buffer(_recv_buffer), _remote_endpoint, [this](std::error_code ec, std::size_t bytes_transferred) {
        if (!ec) {
            std::string message(_recv_buffer.data(), bytes_transferred);
            std::cout << "Received_server: " << message << " from " << _remote_endpoint.address().to_string() << ":" << _remote_endpoint.port() << std::endl;

            // Check if th1e client is already in the list
            auto cl = std::find_if(_clients.begin(), _clients.end(), [this](const ServerClient& client) {
                return client.getEndpoint() == _remote_endpoint;
            });

            if (cl == _clients.end()) {
                _clients.push_back(ServerClient(_remote_endpoint));

                // // Print all client endpoints
                // std::cout << "Current client endpoints:\n";
                // for (const ServerClient& client : _clients) {
                //     std::cout << client.getEndpoint().address().to_string() << ":" << client.getEndpoint().port() << "\n";
                // }
            }
            for (auto it = _clients.begin(); it != _clients.end();) {
                if (it->getEndpoint() == _remote_endpoint) {
                    if (message == "133") {
                        // it->connected = true;
                        std::cout << "CLIENT CONNECTED" << std::endl;
                    }
                }
                ++it;
            }

            auto it = std::find_if(_clients.begin(), _clients.end(), [this](const ServerClient& client) {
                return client.getEndpoint() == _remote_endpoint;
            });
            if (it != _clients.end()) {
                it->lastMessageTime = std::chrono::steady_clock::now();
            }

            start_receive_host();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
    });
}

void GameEngine::start_send_join()
{
    _timer->async_wait([this](std::error_code ec) {
        if (!ec) {
            _socket->send_to(asio::buffer("133"), _server_endpoint);
            _timer->expires_after(std::chrono::milliseconds(1000/60));
            start_send_join();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
    });
}

void GameEngine::start_receive_join()
{
    _socket->async_receive_from(asio::buffer(_recv_buffer), _server_endpoint, [this](std::error_code ec, std::size_t bytes_transferred) {
        if (!ec) {
            std::string message(_recv_buffer.data(), bytes_transferred);
            std::cout << "Received_client: " << message << " from " << _server_endpoint.address().to_string() << ":" << _server_endpoint.port() << std::endl;

            // _lastMessageTime = std::chrono::steady_clock::now();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
        start_receive_host();
    });
}

void GameEngine::update()
{
    if (_online) {
        if (_host) {
            _io_context.run();
        } else {
            while (_window->isOpen()) {
                _window->clear(sf::Color::Black);
                while (_window->pollEvent(_event)) {
                    if (_event.type == sf::Event::Closed) {
                        _window->close();
                    }
                    quit_system(*current_scene->registry.get());
                    controller_system(*current_scene->registry.get());
                    std::string scene_name = onclickloadscene_system(*current_scene->registry.get());
                    if (scene_name != "") {
                        load_scene(scene_name);
                        continue;
                    }
                }
                spawn_with_input_system(*current_scene->registry.get());
                position_system(*current_scene->registry.get());
                gravity_system(*current_scene->registry.get());
                collide_system(*current_scene->registry.get());
                draw_system(*current_scene->registry.get());
                _window->display();
            }
        }
    } else if (!_online) {
        while (_window->isOpen()) {
            _window->clear(sf::Color::Black);
            while (_window->pollEvent(_event)) {
                if (_event.type == sf::Event::Closed) {
                    _window->close();
                }
                quit_system(*current_scene->registry.get());
                controller_system(*current_scene->registry.get());
                std::string scene_name = onclickloadscene_system(*current_scene->registry.get());
                if (scene_name != "") {
                    load_scene(scene_name);
                    continue;
                }
            }
            spawn_with_input_system(*current_scene->registry.get());
            position_system(*current_scene->registry.get());
            gravity_system(*current_scene->registry.get());
            collide_system(*current_scene->registry.get());
            draw_system(*current_scene->registry.get());
            _window->display();

        }
    }
}
