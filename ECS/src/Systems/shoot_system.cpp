/*
** EPITECH PROJECT, 2023
** bullet_system.cpp
** File description:
** bullet_system
*/

#include "Registry.hpp"
#include <tgmath.h> 

void shoot_system(Registry &r)
{
    auto &shoots = r.get_components<Shoot>();
    auto &positions = r.get_components<Position>();

    for (size_t i = 0; i < shoots.size() && i < positions.size(); ++i) {
        auto &shoot = shoots[i];
        auto &pos = positions[i];

        if (shoot && pos) {
            if (shoot.value().timer >= shoot.value().delay) {
                if (sf::Keyboard::isKeyPressed(shoot.value().input)) {
                    Entity bullet = r.create_entity();
                    r.add_component(bullet, Position(pos.value().x, pos.value().y));
                    float angleInRadians = shoot.value().angle * M_PI / 180.0f;
                    float velocityX = shoot.value().speed * cos(angleInRadians);
                    float velocityY = shoot.value().speed * sin(angleInRadians);
                    r.add_component(bullet, Velocity(velocityX, velocityY));
                    r.add_component(bullet, Size(shoot.value().width, shoot.value().height));
                    r.add_component(bullet, Sprite(shoot.value().texture_path, shoot.value().rotate));
                    r.add_component(bullet, Drawable());
                    r.add_component(bullet, BoxCollider("bullet"));
                    r.add_component(bullet, Id(bullet.get_id()));
                    shoot.value().timer = 0;
                }
            }
            shoot.value().timer++;
        }
    }
}