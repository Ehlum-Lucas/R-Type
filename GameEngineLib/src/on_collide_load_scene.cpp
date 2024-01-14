/*
** EPITECH PROJECT, 2024
** on_collide_load_scene.cpp
** File description:
** on_collide_load_scene
*/

/**
 * @file on_collide_load_scene.cpp
 * @brief This file contains the implementation of the `on_collide_load_scene_system` function.
 */

#include "Systems.hpp"

/**
 * The function checks for collisions between box colliders and returns the name of the scene to load
 * if a collision occurs.
 * 
 * @param r The parameter `r` is a reference to an object of type `Registry`. It is being used to
 * access and manipulate the components stored in the registry.
 * 
 * @return a std::string.
 */

std::string on_collide_load_scene_system(Registry &r)
{
    auto &oncollideloadcenes = r.get_components<OnCollideLoadScene>();
    auto &boxcolliders = r.get_components<BoxCollider>();
    auto &positions = r.get_components<Position>();

    for (size_t i = 0; i < oncollideloadcenes.size() && i < boxcolliders.size(); ++i) {
        auto &oncollideloadcene = oncollideloadcenes[i];
        auto &boxcollider1 = boxcolliders[i];

        if (oncollideloadcene && boxcollider1) {

            for (size_t j = 0; j < boxcolliders.size() && j < positions.size(); ++j) {
                auto &boxcollider2 = boxcolliders[j];
                auto &position = positions[j];

                if (boxcollider2 && i != j && oncollideloadcene.value().tag == boxcollider2.value().tag) {
                    boxcollider2.value().collider->setPosition(position.value().x + boxcollider2.value().origin_x, position.value().y + boxcollider2.value().origin_y);
                    if (boxcollider1.value().collider->getGlobalBounds().intersects(boxcollider2.value().collider->getGlobalBounds())) {
                        return oncollideloadcene.value().scene_name;
                    }
                }

            }
        }
    }
    return "";
}
