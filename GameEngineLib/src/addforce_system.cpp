/*
** EPITECH PROJECT, 2024
** addforce_system.cpp
** File description:
** addforce_system
*/

/**
 * @file addforce_system.cpp
 * @brief This file contains the implementation of the `addforce_system` function.
 */

#include "Systems.hpp"

/**
 * The function iterates through a collection of entities and applies a force to their positions based
 * on certain conditions.
 * 
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class.
 */

void addforce_system(Registry &r)
{
    auto &addforces = r.get_components<AddForce>();
    auto &positions = r.get_components<Position>();
    auto &boxcolliders = r.get_components<BoxCollider>();

    for (size_t i = 0; i < addforces.size() && i < positions.size() && i < boxcolliders.size(); ++i) {
        auto &addforce = addforces[i];
        auto &position = positions[i];
        auto &boxcollider = boxcolliders[i];

        if (addforce && position && boxcollider) {
            if (!addforce.value().processing && boxcollider.value().collide && sf::Keyboard::isKeyPressed(addforce.value().input)) {
                addforce.value().processing = true;
                addforce.value().key_was_pressed = true;
                addforce.value().start_x = position.value().x;
                addforce.value().start_y = position.value().y;
            }
            if (addforce.value().key_was_pressed) {
                if (addforce.value().processing && addforce.value().direction == "y" && addforce.value().force < 0 && (position.value().y + addforce.value().force) > (addforce.value().start_y - addforce.value().end_point)) {
                    position.value().y += addforce.value().force;
                } else if (addforce.value().processing) {
                    addforce.value().processing = false;
                } else if (boxcollider.value().collide) {
                    addforce.value().processing = false;
                    addforce.value().key_was_pressed;
                }
            }
        }
    }
}
