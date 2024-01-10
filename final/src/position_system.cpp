/*
** EPITECH PROJECT, 2023
** position_system.cpp
** File description:
** position_system
*/

#include "Systems.hpp"

/**
 * @file position_system.cpp
 * @brief This file contains the implementation of the `position_system` function.
 */

/**
 * The function updates the positions of entities based on their velocities.
 * 
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class.
 */

void position_system (Registry &r) {
    auto &positions = r.get_components<Position>();
    auto &velocities = r.get_components<Velocity>();

    for ( std::size_t i = 0; i < positions.size() && i < velocities.size(); ++i) {
        auto &pos = positions[i];
        auto const &vel = velocities[i];

        if (pos && vel) {
            pos.value().x += vel.value().vx;
            pos.value().y += vel.value().vy;
    
            // if (pos.value().x < 0  && type.value().type == "e") {
            //     r.delete_entity_by_id(id.value().id);
            // }
        }
    }
}
