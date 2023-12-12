/*
** EPITECH PROJECT, 2023
** Game.hpp
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_
    #include <array>
    #include <iostream>
    #include <vector>
    #include "Systems.hpp"
    #include <random>

    class Game {
        public:
            Game();
            ~Game();
            void create_player(int client_type);
            void update(std::vector<std::string> &_inputs_list);
            void setup();
            void run_level(std::string level);
            std::vector<std::string> get_serialized();
        private:
            std::vector<Entity> _players;
            std::vector<Entity> _enemies;
            Registry _registry;
            bool _game_is_running = false;
            std::vector<std::string> _levels;
            std::vector<std::string> _clients_in_room;
    };

#endif /* !GAME_HPP_ */
