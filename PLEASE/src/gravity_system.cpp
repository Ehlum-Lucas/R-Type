/*
** EPITECH PROJECT, 2023
** gravity_system.cpp
** File description:
** gravity_system
*/

#include "Registry.hpp"

void gravity_system(Registry &r)
{
    auto &gravities = r.get_components<Gravity>();
    auto &positions = r.get_components<Position>();

    for (size_t i = 0; i < gravities.size(); ++i) {
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