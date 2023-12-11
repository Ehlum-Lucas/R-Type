/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main
*/

#include "Menu.hpp"
#include <iostream>

int main() 
{
    try {
        Menu menu;
        menu.loopMenu();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}