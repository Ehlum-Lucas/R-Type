/*
** EPITECH PROJECT, 2023
** gravity_system.cpp
** File description:
** gravity_system
*/

#include "Registry.hpp"

/**
 * @file gravity_system.cpp
 * @brief This file contains the implementation of the `gravity_system` function.
 */

/**
 * The function applies gravity forces to positions based on their corresponding gravity components.
 * 
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class.
 */

void gravity_system(Registry &r)
{
    auto &gravities = r.get_components<Gravity>();
    auto &positions = r.get_components<Position>();

    for (std::size_t i = 0; i < gravities.size(); ++i) {
        auto &gravity = gravities[i];
        auto &pos = positions[i];

        if (gravity && pos) {
            if (gravity.value().direction == "y") {
                pos.value().y += gravity.value().gravity_force;
            } else if (gravity.value().direction == "x") {
                pos.value().x += gravity.value().gravity_force;
            }
        }
    }
}