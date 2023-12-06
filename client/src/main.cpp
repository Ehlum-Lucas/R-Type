/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** main
*/

#include "Client.hpp"
#include <iostream>

int main() 
{
    try {
        Client client("localhost", "4080");
        client.run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}