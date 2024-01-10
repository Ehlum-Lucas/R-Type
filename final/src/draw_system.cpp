/*
** EPITECH PROJECT, 2023
** draw_system.cpp
** File description:
** draw_system
*/

#include "Registry.hpp"

/**
 * @file draw_system.cpp
 * @brief This file contains the implementation of the `draw_system` function.
 */

/**
 * The function `draw_system` iterates through components in a registry and draws rectangles and
 * sprites based on their positions, sizes, and colors.
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
    auto &animsprites = r.get_components<AnimatedSprite>();
    auto &sprites = r.get_components<Sprite>();
    auto &sizes = r.get_components<Size>();

    for (std::size_t i = 0; i < drawables.size() && i < positions.size() && i < rectangle_shapes.size() && i < colors.size(); ++i)
    {
        auto &drawable = drawables[i];
        auto &position = positions[i];
        auto &rectangle_shape = rectangle_shapes[i];
        auto &color = colors[i];

        if (drawable && position && rectangle_shape && color)
        {
            rectangle_shape.value().shape.setPosition(position.value().x, position.value().y);
            rectangle_shape.value().shape.setFillColor(color.value().color);
            r._window->draw(rectangle_shape.value().shape);
        }
    }

    // std::cout << "drawables.size() = " << drawables.size() << std::endl;
    // std::cout << "sprites.size() = " << sprites.size() << std::endl;
    // std::cout << "sizes.size() = " << sizes.size() << std::endl;
    // std::cout << "positions.size() = " << positions.size() << std::endl;

    for (std::size_t i = 0; i < sprites.size() && i < sizes.size() && i < positions.size(); ++i)
    {
        auto &animsprite = animsprites[i];
        auto &sprite = sprites[i];
        auto &size = sizes[i];
        auto &position = positions[i];

        if (size && position)
        {
            std::cout << "size && posit" << std::endl;
            if (sprite)
            {
                std::cout << "sprite" << std::endl;
                sprite.value().sprite.setPosition(position.value().x, position.value().y);
                sprite.value().sprite.setScale(size.value().width, size.value().height);
                sprite.value().sprite.setTexture(sprite.value().texture);
                r._window->draw(sprite.value().sprite);
            }
            else if (animsprite)
            {
                std::cout << "animsprite" << std::endl;
                animsprite.value().sprite.setPosition(position.value().x, position.value().y);
                animsprite.value().sprite.setScale(size.value().width, size.value().height);
                animsprite.value().sprite.setTexture(animsprite.value().texture);
                animsprite.value().sprite.setTextureRect(animsprite.value().rect);
                r._window->draw(animsprite.value().sprite);
            }
        }
    }

    for (std::size_t i = 0; i < animsprites.size() && i < sizes.size() && i < positions.size(); ++i)
    {
        auto &animsprite = animsprites[i];
        auto &size = sizes[i];
        auto &position = positions[i];

        if (size && position && animsprite)
        {
            animsprite.value().sprite.setPosition(position.value().x, position.value().y);
            animsprite.value().sprite.setScale(size.value().width, size.value().height);
            animsprite.value().sprite.setTexture(animsprite.value().texture);
            animsprite.value().sprite.setTextureRect(animsprite.value().rect);
            r._window->draw(animsprite.value().sprite);
        }
    }
}