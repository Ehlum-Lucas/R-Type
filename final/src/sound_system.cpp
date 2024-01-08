/*
** EPITECH PROJECT, 2023
** sound_system.cpp
** File description:
** sound_system
*/

#include "Systems.hpp"

/**
 * @file sound_system.cpp
 * @brief This file contains the implementation of the `sound_system` function.
 */

/**
 * The function applies sound forces to positions based on their corresponding sound components.
 *
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class.
 */

void sound_system(Registry &r)
{
    auto &sounds = r.get_components<Sound>();

    for (size_t i = 0; i < sounds.size(); ++i)
    {
        auto &sound = sounds[i];

        // Spawn sound
        if (sound)
        {
            if (sound.value().sound.getStatus() != sf::Sound::Playing)
            {
                sound.value().sound.setBuffer(sound.value().buffer);
                sound.value().sound.play();
            }
        }
    }
}