/*
** EPITECH PROJECT, 2023
** Entity.cpp
** File description:
** Entity
*/

/**
 * @file Entity.cpp
 * @brief This file contains the implementation of the `Entity` class.
 */

#include "Entity.hpp"

/**
 * The Entity constructor assigns an ID to a new entity object, either by incrementing the
 * next_entity_id or reusing a previously deleted ID.
 */

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
