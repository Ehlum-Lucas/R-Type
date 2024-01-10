/*
** EPITECH PROJECT, 2023
** GameEngine.hpp
** File description:
** GameEngine
*/

/**
 * @file GameEngine.hpp
 * @brief This file contains the declaration of the `GameEngine` class.
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
                    _prefabs_serialized[name] = _prefabs_serialized_indice++;
                }
            }

            std::string get_prefab_name_with_id(int id)
            {
                for (auto it = _prefabs_serialized.begin(); it != _prefabs_serialized.end(); ++it) {
                    if (it->second == id)
                        return it->first;
                }
                return "";
            }

            int get_prefab_id_with_name(std::string name)
            {
                for (auto it = _prefabs_serialized.begin(); it != _prefabs_serialized.end(); ++it) {
                    if (it->first == name)
                        return it->second;
                }
                return -1;
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
                _timer = std::make_shared<asio::steady_timer>(_io_context, std::chrono::milliseconds(1000/30));
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
                _timer = std::make_shared<asio::steady_timer>(_io_context_c, std::chrono::milliseconds(1000/30));
                start_receive_join();
                start_send_join();
                io_context_thread_ = std::thread([this] {
                    try {
                        _io_context_c.run();
                    } catch (const std::exception& e) {
                        std::cerr << "Error in thread : " << e.what() << std::endl;
                    } 
                });
            }

            void start_send_host();
            void start_receive_host();
            void start_send_join();
            void start_receive_join();

            void on_new_player_load_prefab(std::string const &prefab_name) {
                _on_new_cient_prefab_name = prefab_name;
            }

            void set_player_atlas_texture(std::vector <std::string> const &textures) {
                for (auto texture : textures) {
                    _clients_atlas_texture[texture] = true;
                }
            }

            std::string get_available_player_skin() {
                for (auto &it : _clients_atlas_texture) {
                    if (it.second) {
                        it.second = false;
                        return it.first;
                    }
                }
                return "";
            }

            void serialize_game();
            void unserialize_game();

            bool is_a_component(std::string const &str);

            void set_player_skin_available(std::string const &skin) {
                _clients_atlas_texture[skin] = true;
            }

            void add_prefab_to_a_scene(Registry& r, Entity &e, std::string prefab_name);

            void create_texture(std::string const &path) {
                texturesLoader.set_texture(path);
                _textures[indice_texture++] = path;
            }

            int get_texture_indice(std::string const &path) {
                for (auto texture : _textures) {
                    if (texture.second == path)
                        return texture.first;
                }
                return -1;
            }

            std::string get_texture_path(int indice) {
                return _textures[indice];
            }

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

            std::string _on_new_cient_prefab_name = "";
            const int _max_client = 4;
            std::map<std::string, bool> _clients_atlas_texture;
            int _nb_clients = 0;

            std::map <int, std::string> _textures;
            int indice_texture = 0;

            bool _game_is_running = false;
            InputGestion _inputGestion;

            bool _controllable_sended = false;

            std::map<std::string, int> _prefabs_serialized;
            int _prefabs_serialized_indice = 0;

        public:
            std::shared_ptr<Scene> current_scene;
            size_t e_type = 10000001;


    };

#endif /* !GAMEENGINE_HPP_ */
