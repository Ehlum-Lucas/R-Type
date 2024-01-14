/*
** EPITECH PROJECT, 2024
** text_system.cpp
** File description:
** text_system
*/

#include "Systems.hpp"

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
