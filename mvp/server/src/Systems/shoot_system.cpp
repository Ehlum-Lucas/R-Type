/*
** EPITECH PROJECT, 2023
** shoot_system.cpp
** File description:
** shoot_system
*/

#include "Systems.hpp"

void shoot_system (Registry &r) {

    auto &positions = r.get_components<Position>();
    auto &ids = r.get_components<Id>();
    auto &types = r.get_components<Type>();
    auto &shoots = r.get_components<Shoot>();

    for (size_t i = 0; i < positions.size() && i < ids.size() && i < types.size() && i < shoots.size(); ++i) {
        auto &pos = positions[i];
        auto const &id = ids[i];
        auto &type = types[i];
        auto &shoot = shoots[i];

        if (pos && id && shoot && shoot.value().shoot && shoot.value().is_shooting && shoot.value().time >= shoot.value().delay) {
            shoot.value().time = 0;
            shoot.value().is_shooting = false;
            Entity bullet = r.create_entity();
            r.add_component(bullet, Position{pos.value().x + 100, pos.value().y + 50});
            r.add_component(bullet, Velocity{30, 0});
            r.add_component(bullet, Drawable{true});
            r.add_component(bullet, Controllable{false});
            r.add_component(bullet, Type{"b"});
            r.add_component(bullet, Id{bullet.get_id()});
            r.add_component(bullet, Size{10, 10});
        }
        if (shoot && shoot.value().time < shoot.value().delay) {
            shoot.value().time += 1;    
        } else if (shoot && shoot.value().time >= shoot.value().delay) {
            // shoot.value().is_shooting = false;
            // shoot.value().shooted = false;
        }
    }
}
