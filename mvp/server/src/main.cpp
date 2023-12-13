/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** main
*/

#include "Server.hpp"

int main() {
    asio::io_context io_context;
    Server server(io_context, 4080);

    while (true) {
        io_context.run();
    }

    return 0;
}
