/*
** EPITECH PROJECT, 2024
** oncollidestop_system.cpp
** File description:
** oncollidestop_system
*/

/**
 * @file oncollidestop_system.cpp
 * @brief This file contains the implementation of the `oncollidestop_system` function.
 */

#include "Systems.hpp"

/**
 * The function checks for collisions between entities with box colliders and applies gravity to the
 * entity if a collision occurs.
 * 
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class. The `Registry` class is likely a container or manager class that holds and manages
 * the components of an entity-component system.
 */

void oncollidestop_system(Registry &r)
{
    auto &oncollidestops = r.get_components<OnCollideStop>();
    auto &boxcolliders = r.get_components<BoxCollider>();
    auto &positions = r.get_components<Position>();
    auto &gravitys = r.get_components<Gravity>();

    for (size_t i = 0; i < oncollidestops.size() && i < boxcolliders.size(); ++i) {
        auto &oncollidestop = oncollidestops[i];
        auto &boxcollider1 = boxcolliders[i];
        auto &position = positions[i];
        auto &gravity = gravitys[i];

        if (oncollidestop && boxcollider1 && gravity && position) {
            for (size_t j = 0; j < boxcolliders.size(); ++j) {
                auto &boxcollider2 = boxcolliders[j];

                if (boxcollider2 && i != j && oncollidestop.value().tag == boxcollider2.value().tag) {
                    if (boxcollider1.value().collider->getGlobalBounds().intersects(boxcollider2.value().collider->getGlobalBounds())) {
                        boxcollider1.value().collide = true;
                        if (gravity.value().direction == "y") {
                            position.value().y -= gravity.value().gravity_force;
                        } else {
                            position.value().x -= gravity.value().gravity_force;
                        }
                    } else {
                        boxcollider1.value().collide = false;
                    }
                }
            }
        }
    }
}