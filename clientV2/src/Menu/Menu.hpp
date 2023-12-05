/*
** EPITECH PROJECT, 2023
** Menu.hpp
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include <SFML/Graphics.hpp>
    #include <memory> 

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
            sf::RenderWindow _window;
            sf::RectangleShape _textbox;
            sf::Font _font;
            sf::Text _text;
            std::string _input;
            bool _isFocused;
    };

#endif /* !MENU_HPP_ */
