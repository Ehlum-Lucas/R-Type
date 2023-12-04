/*
** EPITECH PROJECT, 2023
** Client.hpp
** File description:
** Client
*/

#include "Object.hpp"

class Client 
{
    public:

        Client(const std::string& host, const std::string& port): _io_service(), _socket(_io_service, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0)), _resolver(_io_service), _query(asio::ip::udp::v4(), host, port), _receiver_endpoint(*_resolver.resolve(_query)), _window(sf::VideoMode::getFullscreenModes()[0], "SFML Window", sf::Style::Fullscreen)
        {
            send_message("HELLO");
        }

        void parse_message(std::string message)
        {
            std::string type, id, x, y, status;
            std::istringstream iss(message);

            std::string token;
            while (std::getline(iss, token, ';')) {
                std::istringstream tokenStream(token);

                std::getline(tokenStream, type, ':');
                std::getline(tokenStream, id, ':');
                std::getline(tokenStream, x, ':');
                std::getline(tokenStream, y, ':');
                std::getline(tokenStream, status, ':');

                bool is_object_exists = false;
                for (const auto& object : _objects) {
                    if (object->get_id() == std::stoi(id)) {
                        is_object_exists = true;
                        object->set_position(sf::Vector2f(std::stoi(x), std::stoi(y)));
                        break;
                    }
                }

                if (!is_object_exists) {
                    _objects.push_back(std::make_shared<Object>(type, id, x, y, status));
                }
            }
        }

        void run() 
        {
            std::string response;

            std::thread receive_thread([this, &response]() {
                for (;;) {
                    response = receive_message();
                }
            });

            while (_window.isOpen()) {
                sf::Event event;
                while (_window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                        _window.close();
                    }
                    
                }
                std::string message = "";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    message += "u";
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    message += "d";
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    message += "l";
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    message += "r";
                }

                if (!message.empty()) {
                    send_message(message);
                }

                if (!response.empty()) {
                    // std::cout << response << std::endl;
                    parse_message(response);
                    response = "";
                }

                _window.clear(sf::Color::Black);


                for (auto object : _objects) {
                    object->draw(_window);
                }

                _window.display();
            }

            receive_thread.join();
        }

        std::string receive_message() 
        {
            char buf[1024];
            asio::ip::udp::endpoint sender_endpoint;
            size_t len = _socket.receive_from(asio::buffer(buf), sender_endpoint);
            return std::string(buf, len);
        }

        void send_message(const std::string& message) 
        {
            _socket.send_to(asio::buffer(message), _receiver_endpoint);
        }

    private:
        asio::io_service _io_service;
        asio::ip::udp::socket _socket;
        asio::ip::udp::resolver _resolver;
        asio::ip::udp::resolver::query _query;
        asio::ip::udp::endpoint _receiver_endpoint;
        sf::RenderWindow _window;
        std::vector<std::shared_ptr<Object>> _objects;
};