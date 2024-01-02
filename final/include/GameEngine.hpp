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
    #include <any>
    #define scene get_scene_by_name

    class GameEngine {
        public:
            GameEngine() {}
            ~GameEngine() {}
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

            void add_prefab_to_a_scene(Registry& r, Entity &e, std::string prefab_name);

        private:
            std::shared_ptr<sf::RenderWindow> _window;
            sf::Event _event;
            std::vector<std::shared_ptr<Scene>> _scenes;
            InputGestion _inputGestion;

        public:
            std::shared_ptr<Scene> current_scene;


    };

#endif /* !GAMEENGINE_HPP_ */
