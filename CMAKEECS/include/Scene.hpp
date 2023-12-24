/*
** EPITECH PROJECT, 2023
** Scene.hpp
** File description:
** Scene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_
    #include "Systems.hpp"

    class Scene {
        public:
            Scene(std::string _name, std::shared_ptr<sf::RenderWindow> window, sf::Event &event);
            ~Scene();
            Entity create_entity() {
                Entity e = registry->create_entity();
                registry->add_component(e, Id(e.get_id()));
                return e;
            }
        public:
            std::string name;
            std::shared_ptr<Registry> registry;

    };

#endif /* !SCENE_HPP_ */
