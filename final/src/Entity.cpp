/*
** EPITECH PROJECT, 2023
** Entity.cpp
** File description:
** Entity
*/

#include "Entity.hpp"

/**
 * @file Entity.cpp
 * @brief This file contains the implementation of the `Entity` class.
 */

std::size_t next_entity_id = 0;

/**
 * The Entity constructor assigns an ID to a new entity object, either by incrementing the
 * next_entity_id or reusing a previously deleted ID.
 */

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
