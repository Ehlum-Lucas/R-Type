/*
** EPITECH PROJECT, 2023
** draw_system.cpp
** File description:
** draw_system
*/

/**
 * @file draw_system.cpp
 * @brief This file contains the implementation of the `draw_system` function.
 */

#include "Registry.hpp"

/**
 * The function `draw_system` draws the entities in a game.
 * 
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class.
 */

void draw_system(Registry &r)
{
    auto &drawables = r.get_components<Drawable>();
    auto &positions = r.get_components<Position>();
    auto &rectangle_shapes = r.get_components<RectangleShape>();
    auto &colors = r.get_components<Color>();
    auto &sprites = r.get_components<Sprite>();
    auto &sizes = r.get_components<Size>();
    auto &animated_sprites = r.get_components<AnimatedSprite>();

    for (size_t i = 0; i < drawables.size() && i < positions.size() && i < rectangle_shapes.size() && i < colors.size(); ++i) {
        auto &drawable = drawables[i];
        auto &position = positions[i];
        auto &rectangle_shape = rectangle_shapes[i];
        auto &color = colors[i];

        if (drawable && position && rectangle_shape && color) {
            rectangle_shape.value().shape.setPosition(position.value().x, position.value().y);
            rectangle_shape.value().shape.setFillColor(color.value().color);
            r._window->draw(rectangle_shape.value().shape);
        }
    }

    for (size_t i = 0; i < drawables.size() &&  i < sprites.size() && i < sizes.size() && i < positions.size(); ++i) {
        auto &sprite = sprites[i];
        auto &size = sizes[i];
        auto &position = positions[i];
        auto &drawable = drawables[i];

        if (sprite && size && position && drawable) {
            sprite.value().sprite.setPosition(position.value().x, position.value().y);
            sprite.value().sprite.setScale(size.value().width, size.value().height);
            r._window->draw(sprite.value().sprite);
        }
    }

    for (size_t i = 0; i < drawables.size() && i < sizes.size() && i < positions.size() && i < animated_sprites.size(); ++i) {
        auto &size = sizes[i];
        auto &position = positions[i];
        auto &drawable = drawables[i];
        auto &animated_sprite = animated_sprites[i];

        if (size && position && drawable && animated_sprite) {
            animated_sprite.value().sprite.setPosition(position.value().x, position.value().y);
            animated_sprite.value().sprite.setScale(size.value().width, size.value().height);
            r._window->draw(animated_sprite.value().sprite);
        }
    }
}