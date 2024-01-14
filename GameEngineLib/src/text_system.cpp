/*
** EPITECH PROJECT, 2024
** text_system.cpp
** File description:
** text_system
*/

/**
 * @file text_system.cpp
 * @brief This file contains the implementation of the `text_system` function.
 */

#include "Systems.hpp"

/**
 * The function iterates through a collection of Text components and draws them on the screen.
 * 
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class.
 */

void text_system(Registry &r)
{
    auto &texts = r.get_components<Text>();
    auto &poss = r.get_components<Position>();
    auto &colors = r.get_components<Color>();
    auto &drawables = r.get_components<Drawable>();

    for (size_t i = 0; i < texts.size() && i < poss.size() && i < colors.size() && i < drawables.size(); ++i) {
        auto &text = texts[i];
        auto &pos = poss[i];
        auto &color = colors[i];
        auto &draw = drawables[i];

        if (text && pos && color && draw) {
            text.value().text.setFillColor(color.value().color);
            text.value().text.setPosition(sf::Vector2f(pos.value().x, pos.value().y));
            r._window->draw(text.value().text);
        }
    }
}
