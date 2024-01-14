/*
** EPITECH PROJECT, 2023
** parralax_system.cpp
** File description:
** parralax_system
*/

/**
 * @file parralax_system.cpp
 * @brief This file contains the implementation of the `parralax_system` function.
 */

#include "Systems.hpp"

/**
 * The function `parralax_system` updates the positions of entities based on their velocities and
 * parralax values, resetting the position if necessary.
 * 
 * @param r The parameter `r` is a reference to a `Registry` object. It is used to access the
 * components stored in the registry.
 */

void parralax_system (Registry &r)
{
    auto &positions = r.get_components<Position>();
    auto &parralaxs = r.get_components<Parralax>();
    auto &velocities = r.get_components<Velocity>();

    for ( size_t i = 0; i < positions.size() && i < parralaxs.size() && velocities.size(); ++i) {
        auto &pos = positions[i];
        auto &parralax = parralaxs[i];
        auto &vel = velocities[i];

        if (pos && parralax && vel) {
            if (vel.value().vx > 0) {
                if (pos.value().x >= parralax.value().reset_pos) {
                    pos.value().x = parralax.value().start_pos_x;
                    pos.value().y = parralax.value().start_pos_y;
                }
            } else if (vel.value().vx < 0) {
                if (pos.value().x <= parralax.value().reset_pos) {
                    pos.value().x = parralax.value().start_pos_x;
                    pos.value().y = parralax.value().start_pos_y;
                }
            } else if (vel.value().vy < 0) {
                if (pos.value().y <= parralax.value().reset_pos) {
                    pos.value().x = parralax.value().start_pos_x;
                    pos.value().y = parralax.value().start_pos_y;
                }
            } else if (vel.value().vy > 0) {
                if (pos.value().y >= parralax.value().reset_pos) {
                    pos.value().x = parralax.value().start_pos_x;
                    pos.value().y = parralax.value().start_pos_y;
                }
            }
        }
    }
}
