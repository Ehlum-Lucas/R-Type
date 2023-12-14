/*
** EPITECH PROJECT, 2023
** quit_system.cpp
** File description:
** quit_system
*/

#include "Registry.hpp"

void quit_system(Registry &r)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        std::cout << "quit" << std::endl;
        r._window->close();
    }
}