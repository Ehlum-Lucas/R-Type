/*
** EPITECH PROJECT, 2023
** position_system.cpp
** File description:
** position_system
*/

/**
 * @file position_system.cpp
 * @brief This file contains the implementation of the `position_system` function.
 */

#include "Systems.hpp"

/**
 * The function updates the positions of entities based on their velocities.
 * 
 * @param r The parameter "r" is a reference to an object of type "Registry".
 */

void position_system (Registry &r) {
    auto &positions = r.get_components<Position>();
    auto &velocities = r.get_components<Velocity>();

    for ( size_t i = 0; i < positions.size() && i < velocities.size(); ++i) {
        auto &pos = positions[i];
        auto const &vel = velocities[i];

        if (pos && vel) {
            pos.value().x += vel.value().vx;
            pos.value().y += vel.value().vy;
    
        }
    }
}
