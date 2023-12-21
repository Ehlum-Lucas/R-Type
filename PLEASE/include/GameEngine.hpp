/*
** EPITECH PROJECT, 2023
** GameEngine.hpp
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
    #define GAMEENGINE_HPP_
    #include "Scene.hpp"
    #define scene get_scene_by_name
    #define ONLINE 5372
    #define OFFLINE 4863

    class GameEngine {
        public:
            GameEngine(std::string const &title, int const &mode, int framerate, bool fullscreen, int width = 800, int height = 800);
            ~GameEngine();

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

        private:
            std::shared_ptr<sf::RenderWindow> _window;
            sf::Event _event;
            std::vector<std::shared_ptr<Scene>> _scenes;
            // std::shared_ptr<Server> _server;
            // std::shared_ptr<Client> _client;
            int _mode;
            // asio::io_context _io_context;
        public:
            std::shared_ptr<Scene> current_scene;

    };

#endif /* !GAMEENGINE_HPP_ */
