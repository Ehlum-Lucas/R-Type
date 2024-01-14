/*
** EPITECH PROJECT, 2023
** quit_system.cpp
** File description:
** quit_system
*/

/**
 * @file quit_system.cpp
 * @brief This file contains the implementation of the `quit_system` function.
 */

#include "Registry.hpp"

/**
 * The function checks if the Escape key is pressed and if so, it prints "quit" and closes the window.
 * 
 * @param r The parameter "r" is of type "Registry", which is a user-defined class. It likely contains
 * information and resources related to the system, such as a window object.
 */

void quit_system(Registry &r)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        std::cout << "quit" << std::endl;
        r._window->close();
    }
}