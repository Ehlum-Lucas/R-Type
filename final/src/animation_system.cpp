/*
** EPITECH PROJECT, 2023
** animation_system.cpp
** File description:
** animation_system
*/

#include "Registry.hpp"

/**
 * @file animation_system.cpp
 * @brief This file contains the implementation of the `animation_system` function.
 */

/**
 * The function `animation_system`
 *
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class.
 */

void animation_system(Registry &r)
{
    auto &animated_sprites = r.get_components<AnimatedSprite>();
    auto &positions = r.get_components<Position>();
    auto &sizes = r.get_components<Size>();

    for (std::size_t i = 0; i < animated_sprites.size(); ++i)
    {
        auto &animsprite = animated_sprites[i];
        auto &position = positions[i];
        auto &size = sizes[i];

        if (animsprite)
        {
            if (animsprite.value().clock.getElapsedTime().asMilliseconds() > animsprite.value().speed * 60)
            {
                if (animsprite.value().rect.left >= animsprite.value().rect.width * (animsprite.value().max_frame))
                    animsprite.value().rect.left = animsprite.value().rect.width * (animsprite.value().start_frame);
                else
                    animsprite.value().rect.left += animsprite.value().rect.width;
                animsprite.value().sprite.setTextureRect(animsprite.value().rect);
                animsprite.value().clock.restart();
            }
        }
    }
}