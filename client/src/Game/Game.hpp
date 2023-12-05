/*
** EPITECH PROJECT, 2023
** Game.hpp
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_
    #include "Object.hpp"
    #include "Client.hpp"

    class Game {
        public:
            Game(std::shared_ptr<sf::RenderWindow>  window, sf::Event &event);
            ~Game();
            void loadAssets() {};
            void start();
            void inputsHandler();
            void update();
            void unserialize(std::string data);
            void connectToServer(std::string ip, std::string port);
        private:
            std::shared_ptr<sf::RenderWindow>  _window;
            sf::Event _event;
            std::vector<std::shared_ptr<Object>> _objects;
            std::shared_ptr<Client> _client;
    };

#endif /* !GAME_HPP_ */
