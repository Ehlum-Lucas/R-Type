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
            void draw();
            void drawRoom();
            void EventRoom();
            void updateRoom(sf::Time deltaTime);
            void destroyObject(int id);
            void loadRoom(sf::Texture starTexture, sf::Texture planetTexture, sf::Texture saturnTexture, sf::Texture rocksTexture, sf::Texture backgroundTexture, sf::Vector2f backgroundPosition, sf::Vector2f starPosition, sf::Vector2f planetPosition, sf::Vector2f saturnPosition, sf::Vector2f rocksPosition, sf::RectangleShape backgroundRect, sf::RectangleShape starRect, sf::RectangleShape planetRect, sf::RectangleShape saturnRect, sf::RectangleShape rocksRect, float diagonalSpeedBackground, float diagonalSpeedStar, float diagonalSpeedPlanet, float diagonalSpeedSaturn, float diagonalSpeedRocks, sf::Clock clock);
            void destroyObjectIfNotExists(std::vector<int> ids);
            void parseMessageRoom(std::string message);

        private:
            std::shared_ptr<sf::RenderWindow>  _window;
            sf::Event _event;
            std::vector<std::shared_ptr<Object>> _objects;
            std::shared_ptr<Client> _client;

            bool _game_is_runnging = false;
            bool _isLevelSelected = false;

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

            sf::Texture _loadingDotsTexture;
            sf::Vector2f _loadingDotsPosition;
        
            std::vector<sf::RectangleShape> _loadingDots;
            
            sf::Clock _clock;
            sf::Clock _dotClock;

            sf::RectangleShape _roomBox;

            std::vector<sf::Text> _textPlayers;
            std::vector<sf::Text> _textLevels;
            sf::Text _chooseLevel;
            sf::Text _welcome;
            sf::Font _font;

            std::vector<std::string> _clients;
            std::vector<std::string> _levels;

            std::vector<sf::RectangleShape> _box;

            
            float _diagonalSpeedBackground;
            float _diagonalSpeedStar;
            float _diagonalSpeedPlanet;
            float _diagonalSpeedSaturn;
            float _diagonalSpeedRocks;

            int _nbPlayers;
            int _nbLevels;
            int _selectedLevel = 0;
            
    };

#endif /* !GAME_HPP_ */
