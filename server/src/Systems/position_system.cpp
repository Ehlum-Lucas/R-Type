/*
** EPITECH PROJECT, 2023
** position_system.cpp
** File description:
** position_system
*/

#include "Systems.hpp"

void position_system (Registry &r) {
    auto &positions = r.get_components<Position>();
    auto &velocities = r.get_components<Velocity>();
    auto &controllables = r.get_components<Controllable>();

    for ( size_t i = 0; i < positions.size() && i < velocities.size(); ++i) {
        auto &pos = positions[i];
        auto const &vel = velocities[i];
        if (pos && vel) {
            pos.value().x += vel.value().vx;
            pos.value().y += vel.value().vy;
        }
    }
}
