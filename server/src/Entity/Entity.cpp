/*
** EPITECH PROJECT, 2023
** Entity.cpp
** File description:
** Entity
*/

#include "Entity.hpp"

size_t next_entity_id = 0;

Entity::Entity()
{
    if (_deleted_ids.empty()) {
        _id = next_entity_id;
        next_entity_id++;
    } else {
        _id = _deleted_ids.back();
        _deleted_ids.pop_back();
    }
}
