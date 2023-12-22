/*
** EPITECH PROJECT, 2023
** GameEngine.hpp
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
    #define GAMEENGINE_HPP_
    #include "Scene.hpp"
    #include <asio.hpp>
    #include "ServerClient.hpp"
    #define scene get_scene_by_name
    #define ONLINE 5372
    #define OFFLINE 4863

    class GameEngine {
        public:
            GameEngine() {}
            ~GameEngine() {
                if (_online) {
                    _socket->close();
                    if (!_host) {
                        if (io_context_thread_.joinable()) {
                            io_context_thread_.join();
                        }
                        _io_context_c.stop();
                    }
                }
            }
            void setWindow(std::string const &title, int framerate, bool fullscreen, int width = 800, int height = 800) {
                if (fullscreen) {
                    sf::VideoMode fullscreenMode = sf::VideoMode::getFullscreenModes()[0];
                    _window = std::make_shared<sf::RenderWindow>(fullscreenMode, title, sf::Style::Fullscreen);
                } else {
                    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
                }
                _window->setFramerateLimit(framerate);
            }

            void update();

            void create_scene(std::string const &name) {_scenes.push_back(std::make_shared<Scene>(name, _window, _event));}
            void load_scene(std::string const &name) {
                for (auto it = _scenes.begin(); it != _scenes.end(); ++it) {
                    if ((*it)->name == name) {
                        current_scene = *it;
                        return;
                    }
                }
            }
            std::shared_ptr<Scene> get_scene_by_name(std::string const &name) {
                for (auto it = _scenes.begin(); it != _scenes.end(); ++it) {
                    if ((*it)->name == name) {
                        return *it;
                    }
                }
                return current_scene;
            }

            void create_prefab(std::string name) {
                for (auto it = _scenes.begin(); it != _scenes.end(); ++it) {
                    (*it)->registry->_prefabs[name] = std::vector<std::any>();
                }
            }

            void add_component_to_prefab(std::string name, std::any component) {
                for (auto it = _scenes.begin(); it != _scenes.end(); ++it) {
                    (*it)->registry->_prefabs[name].push_back(component);
                }
            }

            void hostOnlineGame(std::string const &ip, std::string const &port) {
                _host = true;
                _ip = ip;
                _port = port;
                _online = true;
                _socket = std::make_shared<asio::ip::udp::socket>(_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), std::stoi(_port)));
                _timer = std::make_shared<asio::steady_timer>(_io_context, std::chrono::milliseconds(1000/60));
                std::cout << "Server starting on port " << _port << std::endl;
                start_receive_host();
                start_send_host();
            }

            void joinOnlineGame(std::string const &ip, std::string const &port) {
                _host = false;
                _ip = ip;
                _port = port;
                _online = true;
                _socket = std::make_shared<asio::ip::udp::socket>(_io_context_c, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0));
                _server_endpoint = asio::ip::udp::endpoint(asio::ip::address::from_string(ip), std::stoi(port));
                _timer = std::make_shared<asio::steady_timer>(_io_context_c, std::chrono::milliseconds(1000/60));
                start_receive_join();
                start_send_join();
                io_context_thread_ = std::thread([this] {_io_context_c.run(); });
            }

            void start_send_host();
            void start_receive_host();
            void start_send_join();
            void start_receive_join();

        private:
            std::shared_ptr<sf::RenderWindow> _window;
            sf::Event _event;
            std::vector<std::shared_ptr<Scene>> _scenes;
            bool _host = false;
            bool _online = false;
            std::string _ip = "";
            std::string _port = "";
            std::shared_ptr<asio::ip::udp::socket> _socket;
            asio::ip::udp::endpoint _remote_endpoint;
            std::array<char, 1024> _recv_buffer;
            std::shared_ptr<asio::steady_timer> _timer;
            asio::io_context _io_context;
            asio::io_context _io_context_c;
            std::shared_ptr<asio::io_service> _io_service;
            std::shared_ptr<asio::ip::udp::resolver> _resolver;
            std::shared_ptr<asio::ip::udp::resolver::query> _query;

            std::thread io_context_thread_;

            std::vector<ServerClient> _clients;
            bool _created = false;
            bool _connected = false;
            std::vector<std::string> _received_messages;
            std::vector<std::string> _to_send_messages;
            std::string _type;
            std::chrono::steady_clock::time_point _lastMessageTime;
            asio::ip::udp::endpoint _server_endpoint;
        public:
            std::shared_ptr<Scene> current_scene;

    };

#endif /* !GAMEENGINE_HPP_ */
