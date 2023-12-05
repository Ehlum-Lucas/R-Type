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

void Game::unserialize(std::string data)
{
    std::string type, id, x, y, status;
    std::istringstream iss(data);
    std::string message;

    while (std::getline(iss, message, ';')) {
        std::istringstream iss2(message);
        std::getline(iss2, type, ':');
        std::getline(iss2, id, ':');
        std::getline(iss2, x, ':');
        std::getline(iss2, y, ':');
        std::getline(iss2, status, ':');

        bool is_object_exists = false;
        for (auto &object : _objects) {
            if (object->getId() == std::stoi(id)) {
                is_object_exists = true;
                object->setPosition(sf::Vector2f(std::stof(x), std::stof(y)));
                break;
            }
        }

        if (!is_object_exists) {
            _objects.push_back(std::make_shared<Object>(type, std::stoi(id), std::stof(x), std::stof(y), std::stoi(status)));
        }
    }

}
void receiveMessageThread(std::shared_ptr<Client> client) {
    while (true) {
        client->_message = client->receiveMessage();
    }
}
void Game::start()
{
    _client->_thread = std::thread(receiveMessageThread, this->_client);
    while (_window->isOpen()) {
        inputsHandler();
        update();
    }
    _client->_thread.join();
}
void Game::inputsHandler()
{
    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed 
        || (_event.type == sf::Event::KeyPressed 
        && _event.key.code == sf::Keyboard::Escape))
            _window->close();
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
    if (!message.empty()) {
        _client->sendMessage(message);
    }

    if (!_client->_message.empty()) {
        unserialize(_client->_message);
        _client->_message = "";
    }
}

void Game::update()
{
    _window->clear(sf::Color::Black);
    for (auto object : _objects) {
        object->draw(_window);
    }
    _window->display();
}