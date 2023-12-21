/*
** EPITECH PROJECT, 2023
** serialize_components.cpp
** File description:
** serialize_components
*/

#include "Systems.hpp"

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
