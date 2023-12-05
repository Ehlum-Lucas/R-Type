/*
** EPITECH PROJECT, 2023
** Menu.hpp
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "Game.hpp"

    class Menu {
        public:
            Menu();
            ~Menu();
            void loopMenu();
            void loadAssets();
            void loadMenu();
            void Event();

        protected:
        private:
            std::shared_ptr<sf::RenderWindow> _window;
            sf::Event _event;
            sf::RectangleShape _textbox;
            sf::Font _font;
            sf::Text _text;
            std::string _input;
            bool _isFocused;

            std::shared_ptr<Game> _game;
    };

#endif /* !MENU_HPP_ */
