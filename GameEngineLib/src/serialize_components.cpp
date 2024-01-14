/*
** EPITECH PROJECT, 2023
** serialize_components.cpp
** File description:
** serialize_components
*/

/**
 * @file serialize_components.cpp
 * @brief This file contains the implementation of the `serialize_components` function.
 */

#include "Systems.hpp"

/**
 * The function `serialize_components` takes a registry object and serializes the components of type
 * Position, Sprite, Size, and Id into a vector of strings.
 * 
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class.
 * 
 * @return The function `serialize_components` returns a `std::vector<std::string>`.
 */

std::vector<std::string> serialize_components(Registry &r)
{
    auto &positions = r.get_components<Position>();
    auto &sprites = r.get_components<Sprite>();
    auto &sizes = r.get_components<Size>();
    auto &ids = r.get_components<Id>();


    std::vector<std::string> serializables;
    for (size_t i = 0; i < positions.size() && i < sprites.size() && i < sizes.size(); i++) {
        auto &pos = positions[i];
        auto &sprite = sprites[i];
        auto &size = sizes[i];
        auto &id = ids[i];

        std::string serializable = std::to_string(id.value().id) + ":" + sprite.value().texture_path + ":" + std::to_string(pos.value().x) + ":" + std::to_string(pos.value().y) + ":" + std::to_string(size.value().width) + ":" + std::to_string(size.value().height) + ";"; 
        serializables.push_back(serializable);
    }
    return serializables;
}
