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
    auto &musics = r.get_components<Music>();

    for (std::size_t i = 0; i < sounds.size(); ++i)
    {
        auto &sound = sounds[i];

        // Spawn sound
        if (sound)
        {
            if (sound.value().sound->getStatus() != sf::Sound::Playing && !sound.value().played)
            {
                sound.value().sound->play();
                if (!sound.value().loop)
                    sound.value().played = true;
            }
        }
    }
    for (std::size_t i = 0; i < musics.size(); ++i)
    {
        auto &music = musics[i];

        if (music)
        {
            if (music.value().music->getStatus() != sf::SoundSource::Playing)
            {
                music.value().music->play();
                if (!music.value().loop)
                    music.value().played = true;
            }
        }
    }
}