/*
** EPITECH PROJECT, 2024
** showcollisionswithinput_system.cpp
** File description:
** showcollisionswithinput_system
*/

/**
 * @file showcollisionswithinput_system.cpp
 * @brief This file contains the implementation of the `showcollisionswithinput_system` function.
 */

#include "Systems.hpp"

/**
 * The function iterates through a collection of ShowCollisionsWithInput components and updates the
 * visibility of associated BoxCollider components based on keyboard input.
 * 
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class.
 */

void showcollisionswithinput_system(Registry &r)
{
    auto &shows = r.get_components<ShowCollisionsWithInput>();
    auto &boxcolliders = r.get_components<BoxCollider>();

    for (size_t i = 0; i < shows.size(); ++i) {
        auto &show = shows[i];

        if (show) {
            for (size_t j = 0; j < boxcolliders.size(); ++j) {
                if (boxcolliders[j]) {
                    boxcolliders[j].value().draw = show.value().showed;
                }
            }
            if (show.value().released && sf::Keyboard::isKeyPressed(show.value().input)) {
                show.value().released = false;
                if (show.value().showed) {
                    show.value().showed = false;
                } else {
                    show.value().showed = true;
                }
            }
            if (!show.value().released && !sf::Keyboard::isKeyPressed(show.value().input)) {
                show.value().released = true;
            }
        }
    }
}