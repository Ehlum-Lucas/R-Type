/*
** EPITECH PROJECT, 2024
** sound_system.cpp
** File description:
** sound_system
*/

#include "Systems.hpp"

void sound_system(Registry &r)
{
    auto &sounds = r.get_components<PlaySound>();

    for (size_t i = 0; i < sounds.size(); i++) {
        auto &sound = sounds[i];

        if (sound && sound.value().music->getStatus() != sf::SoundSource::Playing)
        {
            sound.value().music->setVolume(sound.value().volume);
            sound.value().music->play();
            if (!sound.value().loop)
                sound.value().played = true;
        }
    }
}