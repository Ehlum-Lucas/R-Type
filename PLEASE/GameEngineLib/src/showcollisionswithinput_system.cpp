/*
** EPITECH PROJECT, 2024
** showcollisionswithinput_system.cpp
** File description:
** showcollisionswithinput_system
*/

#include "Systems.hpp"

void showcollisionswithinput_system(Registry &r)
{
    auto &shows = r.get_components<ShowCollisionsWithInput>();
    auto &boxcolliders = r.get_components<BoxCollider>();

    for (size_t i = 0; i < shows.size(); ++i) {
        auto &show = shows[i];

        if (show) {
            if (show.value().released && sf::Keyboard::isKeyPressed(show.value().input)) {
                show.value().released = false;
                for (size_t j = 0; j < boxcolliders.size(); ++j) {
                    if (boxcolliders[j]) {
                        boxcolliders[j].value().draw = show.value().showed;
                    }
                }
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