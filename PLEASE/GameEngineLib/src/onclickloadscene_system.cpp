/*
** EPITECH PROJECT, 2023
** onclickloadscene_system.cpp
** File description:
** onclickloadscene_system
*/

#include "Systems.hpp"

/**
 * @file onclickloadscene_system.cpp
 * @brief This file contains the implementation of the `onclickloadscene_system` function.
 */

/**
 * The function checks if the left mouse button is pressed and if the mouse is within the bounds of a
 * sprite, and returns the scene name associated with the sprite if true.
 * 
 * @param r The parameter `r` is a reference to an object of type `Registry`. It is being passed by
 * reference so that the function can access and modify the components stored in the registry. The
 * `Registry` class likely represents a collection of entities and their associated components in an
 * entity-component system (ECS
 * 
 * @return a std::string value.
 */

std::string onclickloadscene_system(Registry &r)
{
    auto &onclickloadscenes = r.get_components<OnClickLoadScene>();
    auto &sprites = r.get_components<Sprite>();

    for (size_t i = 0; i < sprites.size() && i < onclickloadscenes.size(); ++i) {
        auto &sprite = sprites[i];
        auto &onclickloadscene = onclickloadscenes[i];


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition();
            if (sprite.value().sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                return onclickloadscene.value().scene_name;
            }
        }
    }

    return "";
}