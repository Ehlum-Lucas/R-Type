/*
** EPITECH PROJECT, 2023
** parralax_system.cpp
** File description:
** parralax_system
*/

#include "Systems.hpp"


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
