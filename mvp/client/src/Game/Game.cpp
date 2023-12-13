/*
** EPITECH PROJECT, 2023
** Game.cpp
** File description:
** Game
*/

#include "Game.hpp"

Game::Game(std::shared_ptr<sf::RenderWindow> window, sf::Event &event) : _window(window), _event(event)
{
}

Game::~Game() {}

void Game::connectToServer(std::string ip, std::string port)
{
    _client = std::make_shared<Client>(ip, port);
    _client->connectToServer();
}

void Game::destroyObject(int id)
{
    for (auto it = _objects.begin(); it != _objects.end(); it++) {
        if ((*it)->getId() == id) {
            _objects.erase(it);
            break;
        }
    }
}

void Game::destroyObjectIfNotExists(std::vector<int> ids)
{
    std::vector<std::vector<std::shared_ptr<Object>>::iterator> its;
    for (auto it = _objects.begin(); it != _objects.end(); it++) {
        bool is_object_exists = false;
        for (auto id : ids) {
            if ((*it)->getId() == id) {
                is_object_exists = true;
                break;
            }
        }
        if (!is_object_exists) {
            its.push_back(it);
        }
    }
    for (auto it : its) {
        std::cout << "destroying object" << std::endl;
        _objects.erase(it);
    }
}

void Game::unserialize(std::string data)
{
    
    if (data.find("CLIENTS") == std::string::npos && data.find("LEVELS") == std::string::npos) {
        _game_is_runnging = true;
    } else {
        return;
    }

    std::string type, id, x, y, status, height, width;
    std::istringstream iss(data);
    std::string message;
    std::vector<int> ids;

    while (std::getline(iss, message, ';')) {
        std::istringstream iss2(message);
        std::getline(iss2, type, ':');
        std::getline(iss2, id, ':');
        std::getline(iss2, height, ':');
        std::getline(iss2, width, ':');
        std::getline(iss2, x, ':');
        std::getline(iss2, y, ':');
        std::getline(iss2, status, ':');
        ids.push_back(std::stoi(id));
        bool is_object_exists = false;
        for (auto &object : _objects) {
            if (object->getId() == std::stoi(id)) {
                is_object_exists = true;
                object->setPosition(sf::Vector2f(std::stof(x), std::stof(y)));
                break;
            }
        }

        if (!is_object_exists) {
            _objects.push_back(std::make_shared<Object>(type, std::stoi(id), std::stof(x), std::stof(y), std::stoi(status), std::stof(height), std::stof(width)));
        }
    }
    destroyObjectIfNotExists(ids);

}
void receiveMessageThread(std::shared_ptr<Client> client, bool &run) {
    while (run) {
        client->_message = client->receiveMessage();
        std::cout << client->_message << std::endl;
    }
}
void Game::start()
{
    _client->_thread = std::thread(receiveMessageThread, this->_client, std::ref(this->_game));
    while (_window->isOpen() && _game) {
        inputsHandler();
        update();
    }
    _client->_thread.join();
    _client->sendMessage("QUIT");
    _objects.clear();
    _game = true;
    _game_is_runnging = false;
    _client->_server_know = false;
    _isLevelSelected = false;
    _nbPlayers = 0;
    _nbLevels = 0;
    _selectedLevel = 0;
    _clients.clear();
    _levels.clear();
    _loadingDots.clear();
    _textPlayers.clear();
    _textLevels.clear();
    _box.clear();
}

void Game::inputsHandler()
{
    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)) {
            _game = false;
            // _window->close();
        }
        EventRoom();
    }
    if (!_client->_server_know)
        _client->sendMessage("OK");
    
    if (_game_is_runnging) {
        std::string message = "";
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            message += "u";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            message += "d";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            message += "l";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            message += "r";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            message += "s";
        }
        if (!_client->_message.empty() && _client->_message.substr(0, 8) != "YOU ARE " && _game_is_runnging) {
            _client->_server_know = true;
            unserialize(_client->_message);
            _client->_message = "";
            if (!message.empty() && _client->_server_know) {
                message =  _client->_playerId + ':' + message;
                _client->sendMessage(message);
                message = "";
            }
        }
    }
}

void Game::EventRoom()
{
    if (!_game_is_runnging) {
        if (_event.type == sf::Event::KeyPressed)
        {
            if (_event.key.code == sf::Keyboard::Up && _selectedLevel > 0) {
                _selectedLevel--;
            } else if (_event.key.code == sf::Keyboard::Down && _selectedLevel < _nbLevels - 1) {
                _selectedLevel++;
            }
            if (_event.key.code == sf::Keyboard::Enter) {
                std::cout << "MASTER:LEVEL" + std::to_string(_selectedLevel + 1) + ";" << std::endl;
                _client->sendMessage("MASTER:LEVEL" + std::to_string(_selectedLevel + 1) + ";");
            }
        }
    }
}

void::Game::drawRoom()
{
    _window->draw(_backgroundRect);
    _window->draw(_saturnRect);
    _window->draw(_starRect);
    _window->draw(_rocksRect);
    _window->draw(_planetRect);
    _window->draw(_roomBox);
    _window->draw(_welcome);
    _window->draw(_chooseLevel);
    for (auto box : _box) {
        _window->draw(box);
    }
    for (auto text : _textPlayers) {
        _window->draw(text);
    }
    for (auto text : _textLevels) {
        _window->draw(text);
    }
    for (int i = _nbPlayers; i < _loadingDots.size(); i++) {
        _window->draw(_loadingDots[i]);
    }
}

void Game::parseMessageRoom(std::string message)
{
    std::size_t levelsPos = message.find("LEVELS:");
    std::size_t clientsPos = message.find("CLIENTS:");

    if (_client->_message.substr(0, 8) != "YOU ARE " && message.find("LEVELS:") == std::string::npos && message.find("CLIENTS:") == std::string::npos && _client->_server_know) {
        _game_is_runnging = true;
    }

    if (levelsPos != std::string::npos && clientsPos != std::string::npos && _client->_message.substr(0, 8) != "YOU ARE " ) {
        _client->_server_know = true;
        std::string levelsStr = message.substr(levelsPos + 7, clientsPos - levelsPos - 7);
        std::string clientsStr = message.substr(clientsPos + 8);

        _nbLevels = std::count(levelsStr.begin(), levelsStr.end(), ';');
        _nbPlayers = std::count(clientsStr.begin(), clientsStr.end(), ';');

        sf::Vector2u windowSize = _window->getSize();
        sf::Vector2f boxLevelSize = _roomBox.getSize();
        float posX = (windowSize.x - boxLevelSize.x) / 2;
        float posY = (windowSize.y - boxLevelSize.y) / 2;

        for (int i = _textPlayers.size(); i < _nbPlayers; i++) {
            sf::Text text;
            text.setFont(_font);
            text.setCharacterSize(30);
            text.setFillColor(sf::Color::White);
            text.setPosition(1145, 257 + i * 75);
            text.setString("Player " + std::to_string(i + 1));
            _textPlayers.push_back(text);
        }
        for (int i = _textLevels.size(); i < _nbLevels; i++) {
            sf::Text text;
            text.setFont(_font);
            text.setCharacterSize(30);
            text.setFillColor(sf::Color::White);
            text.setPosition(posX + 25, 310 + i * 85);
            text.setString("Level " + std::to_string(i + 1));
            _textLevels.push_back(text);
        }
    }
}


void Game::loadRoom(sf::Texture starTexture, sf::Texture planetTexture, sf::Texture saturnTexture, sf::Texture rocksTexture, sf::Texture backgroundTexture, sf::Vector2f backgroundPosition, sf::Vector2f starPosition, sf::Vector2f planetPosition, sf::Vector2f saturnPosition, sf::Vector2f rocksPosition, sf::RectangleShape backgroundRect, sf::RectangleShape starRect, sf::RectangleShape planetRect, sf::RectangleShape saturnRect, sf::RectangleShape rocksRect, float diagonalSpeedBackground, float diagonalSpeedStar, float diagonalSpeedPlanet, float diagonalSpeedSaturn, float diagonalSpeedRocks, sf::Clock clock)
{
    _backgroundTexture = backgroundTexture;
    _backgroundPosition = backgroundPosition;
    _backgroundRect = backgroundRect;

    _starTexture = starTexture;
    _starPosition = starPosition;
    _starRect = starRect;

    _planetTexture = planetTexture;
    _planetPosition = planetPosition;
    _planetRect = planetRect;

    _saturnTexture = saturnTexture;
    _saturnPosition = saturnPosition;
    _saturnRect = saturnRect;

    _rocksTexture = rocksTexture;
    _rocksPosition = rocksPosition;
    _rocksRect = rocksRect;
    
    _clock = clock;

    _diagonalSpeedBackground = diagonalSpeedBackground;
    _diagonalSpeedStar = diagonalSpeedStar;
    _diagonalSpeedPlanet = diagonalSpeedPlanet;
    _diagonalSpeedSaturn = diagonalSpeedSaturn;
    _diagonalSpeedRocks = diagonalSpeedRocks;

    _roomBox.setSize(sf::Vector2f(900, 600));

    _roomBox.setOutlineColor(sf::Color::White);
    _roomBox.setOutlineThickness(10);
    _roomBox.setFillColor(sf::Color::Transparent);
    sf::Vector2u windowSize = _window->getSize();
    sf::Vector2f boxLevelSize = _roomBox.getSize();
    float posX = (windowSize.x - boxLevelSize.x) / 2;
    float posY = (windowSize.y - boxLevelSize.y) / 2;
    _roomBox.setPosition(posX, posY);
    _font.loadFromFile("assets/fonts/arcade_ya/ARCADE_R.ttf");

    _welcome.setFont(_font);
    _welcome.setCharacterSize(50);
    _welcome.setFillColor(sf::Color::White);
    _welcome.setPosition(posX + 25, 100);
    _welcome.setString("Welcome to the room");

    _chooseLevel.setFont(_font);
    _chooseLevel.setCharacterSize(30);
    _chooseLevel.setFillColor(sf::Color::White);
    _chooseLevel.setPosition(posX + 25, posY + 15);
    _chooseLevel.setString("Choose your level:");

    for (int i = 0; i < 8; i++) {
        _box.push_back(sf::RectangleShape(sf::Vector2f(300, 75)));
        _box[i].setOutlineColor(sf::Color::White);
        _box[i].setOutlineThickness(5);
        _box[i].setFillColor(sf::Color::Transparent);
        _box[i].setPosition(1115, posY + i * 75);
    }

    _loadingDotsTexture.loadFromFile("assets/images/LoadingDots.png");
    for (int i = 0; i < 8; i++) {
        _loadingDots.push_back(sf::RectangleShape(sf::Vector2f(115, 52)));
        _loadingDots[i].setTexture(&_loadingDotsTexture);
        _loadingDots[i].setTextureRect(sf::IntRect(0, 0, 115, 52));
        _loadingDots[i].setPosition(1195, posY + (i * 75) + 10);
    }

}

void::Game::updateRoom(sf::Time deltaTime)
{
    float ratio = 762.5 / 1080;
    float speedY = _diagonalSpeedBackground;
    float speedX = _diagonalSpeedBackground * ratio;

    _backgroundPosition.y += speedY * deltaTime.asSeconds();
    _backgroundPosition.x += (- speedX * deltaTime.asSeconds());
    _backgroundRect.setPosition(_backgroundPosition);

    if (_backgroundPosition.y >= 0)
    {
        _backgroundPosition.y = -1080;
        _backgroundPosition.x = 0;
    }

    float ratioStar =  1920.0 / 1080.0;
    float starSpeedY = _diagonalSpeedStar;
    float starSpeedX = _diagonalSpeedStar * ratioStar;

    _starPosition.x += (-starSpeedX * deltaTime.asSeconds());
    _starPosition.y += starSpeedY * deltaTime.asSeconds();
    _starRect.setPosition(_starPosition);

    if (_starPosition.y >= 0)
    {
        _starPosition.x = 0;
        _starPosition.y = -1080;
    }

    float ratioPlanet =  1920.0 / 1080.0;
    float planetSpeedY = _diagonalSpeedPlanet;
    float planetSpeedX = _diagonalSpeedPlanet * ratioPlanet;

    _planetPosition.x += (-planetSpeedX * deltaTime.asSeconds());
    _planetPosition.y += planetSpeedY * deltaTime.asSeconds();
    _planetRect.setPosition(_planetPosition);

    if (_planetPosition.y >= 0)
    {
        _planetPosition.x = 0;
        _planetPosition.y = -1080;
    }

    float ratioSaturn =  1920.0 / 1080.0;
    float saturnSpeedY = _diagonalSpeedSaturn;
    float saturnSpeedX = _diagonalSpeedSaturn * ratioSaturn;

    _saturnPosition.x += (-saturnSpeedX * deltaTime.asSeconds());
    _saturnPosition.y += saturnSpeedY * deltaTime.asSeconds();
    _saturnRect.setPosition(_saturnPosition);

    if (_saturnPosition.y >= 0)
    {
        _saturnPosition.x = 0;
        _saturnPosition.y = -1080;
    }

    float ratioRocks =  1920.0 / 1080.0;
    float rocksSpeedY = _diagonalSpeedRocks;
    float rocksSpeedX = _diagonalSpeedRocks * ratioRocks;

    _rocksPosition.x += (-rocksSpeedX * deltaTime.asSeconds());
    _rocksPosition.y += rocksSpeedY * deltaTime.asSeconds();
    _rocksRect.setPosition(_rocksPosition);

    if (_rocksPosition.y >= 0)
    {
        _rocksPosition.x = 0;
        _rocksPosition.y = -1080;
    }


    sf::Time elapsdTime = _dotClock.getElapsedTime();
    const float interval = 0.1f;

    if (elapsdTime.asSeconds() >= interval) {
        for (auto& dot : _loadingDots) {
            sf::IntRect textureRect = dot.getTextureRect();
            textureRect.left += 115;
            if (textureRect.left >= 115 * 6) {
                textureRect.left = 0;
            }
            dot.setTextureRect(textureRect);
        }
        _dotClock.restart();
    }

    if (!_game_is_runnging) {
        for (int i = 0; i < _textLevels.size(); i++)
        {
            if (i == _selectedLevel) {
                _textLevels[i].setFillColor(sf::Color::Red);
            } else {
                _textLevels[i].setFillColor(sf::Color::White);
            }
        }
    }
}

void Game::update()
{
    _window->clear(sf::Color::Black);
    if (!_game_is_runnging) {
        sf::Time deltaTime = _clock.restart();
        parseMessageRoom(_client->_message);
        updateRoom(deltaTime);
        drawRoom();
    } else {
        for (auto object : _objects) {
            object->draw(_window);
        }
    }
    _window->display();
}
