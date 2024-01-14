/*
** EPITECH PROJECT, 2024
** boxcollider_system.cpp
** File description:
** boxcollider_system
*/

#include "Systems.hpp"

void boxcollider_system(Registry &r)
{
    auto &boxcolliders = r.get_components<BoxCollider>();
    auto &positions = r.get_components<Position>();

    for (size_t i = 0; i < boxcolliders.size() && i < positions.size(); ++i) {
        auto &boxcollider = boxcolliders[i];
        auto &position = positions[i];

        if (boxcollider && position) {
            boxcollider.value().collider->setOrigin(boxcollider.value().width / 2, boxcollider.value().height / 2);
            boxcollider.value().collider->setScale(1, 1);
            boxcollider.value().collider->setFillColor(boxcollider.value().color);
            boxcollider.value().collider->setPosition(position.value().x + boxcollider.value().origin_x, position.value().y + boxcollider.value().origin_y);
            if (boxcollider.value().draw)
                r._window->draw(*boxcollider.value().collider.get());
        }
    }
}