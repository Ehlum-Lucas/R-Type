/*
** EPITECH PROJECT, 2023
** serialize_system.cpp
** File description:
** serialize_system
*/

#include "Systems.hpp"

std::vector<std::string> serialize_system (Registry &r)
{
    auto &positions = r.get_components<Position>();
    auto &types = r.get_components<Type>();
    auto &ids = r.get_components<Id>();
    std::vector<std::string> serialized;

    for ( size_t i = 0; i < positions.size() && i < types.size(); ++i) {
        auto const &pos = positions[i];
        auto const &vel = types[i];
        auto const &id = ids[i];
    
        if (pos && vel && id && pos.value().x > -100 && pos.value().x < 1920) {
            std::string serialized_entity = vel.value().type + ":" + std::to_string(id.value().id) + ":" + std::to_string(pos.value().x) + ":" + std::to_string(pos.value().y) + ":" + "1";
            serialized.push_back(serialized_entity);
        }
    }

    return serialized;
}