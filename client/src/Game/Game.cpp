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
}

void Game::inputsHandler()
{
    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed 
        || (_event.type == sf::Event::KeyPressed 
        && _event.key.code == sf::Keyboard::Escape)) {
            _game = false;
            // _window->close();
        }
    }
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
    if (!_client->_server_know)
        _client->sendMessage("OK");

    if (!_client->_message.empty() && _client->_message.substr(0, 8) != "YOU ARE ") {
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

void Game::update()
{
    _window->clear(sf::Color::Black);
    if (!_game_is_runnging) {
        sf::Font font;
        sf::Text text;
        font.loadFromFile("assets/fonts/arcade_ya/ARCADE_R.ttf");
        text.setFont(font);
        text.setString("YOU ARE IN THE WAITING ROOM");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(650, 500);
        _window->draw(text);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            _client->sendMessage("MASTER:LEVEL1;");
        }
    } else {
        for (auto object : _objects) {
            object->draw(_window);
        }
    }
    _window->display();
}
