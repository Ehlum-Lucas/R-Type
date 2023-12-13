/*
** EPITECH PROJECT, 2023
** quit_system.cpp
** File description:
** quit_system
*/

#include "Registry.hpp"

void quit_system(Registry &r)
{
    if (r._event.type == sf::Event::Closed || (r._event.type == sf::Event::KeyPressed && r._event.key.code == sf::Keyboard::Escape)) {
        r._window->close();
    }
}