/*
** EPITECH PROJECT, 2023
** onclickloadscene_system.cpp
** File description:
** onclickloadscene_system
*/

#include "Systems.hpp"

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