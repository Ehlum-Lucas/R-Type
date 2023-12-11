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
    #include <iostream>

    class Menu {
        public:
            Menu();
            ~Menu();
            void loopMenu();
            void loadAssets();
            void loadMenu();
            void Event();
            void EventKey(sf::Event event);
            void EventTextEntered(sf::Event event);
            void EventMouse(sf::Event event);
            void Draw();
            void Update(sf::Time deltaTime);

            // Ajouter la fonction pour gérer le clic sur le bouton "Play"
            void handlePlayButton();

        protected:
        private:
            sf::RenderWindow _window;
            sf::Font _font;

            sf::Text _titleIp;
            sf::RectangleShape _textboxIp;
            std::string _inputIp;
            sf::Text _textIp;

            sf::Text _titlePort;
            sf::RectangleShape _textboxPort;
            std::string _inputPort;
            sf::Text _textPort;

            sf::Texture _titleTexture;
            sf::Sprite _titleSprite;
            
            sf::Texture _playButtonTexture;
            sf::Sprite _playButtonSprite;
            sf::Texture _playButtonHoverTexture;

            sf::Texture _backgroundTexture;
            sf::Vector2f _backgroundPosition;
            sf::RectangleShape _backgroundRect;

            sf::Texture _starTexture;
            sf::Vector2f _starPosition;
            sf::RectangleShape _starRect;

            sf::Texture _planetTexture;
            sf::Vector2f _planetPosition;
            sf::RectangleShape _planetRect;

            sf::Texture _saturnTexture;
            sf::Vector2f _saturnPosition;
            sf::RectangleShape _saturnRect;

            sf::Texture _rocksTexture;
            sf::Vector2f _rocksPosition;
            sf::RectangleShape _rocksRect;
            
            sf::Clock _clock;

            float _diagonalSpeedBackground;
            float _diagonalSpeedStar;
            float _diagonalSpeedPlanet;
            float _diagonalSpeedSaturn;
            float _diagonalSpeedRocks;
            
            bool _isFocusedIp;
            bool _isFocusedPort;
    };

#endif /* !MENU_HPP_ */
