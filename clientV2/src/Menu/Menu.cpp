/*
** EPITECH PROJECT, 2023
** Menu.cpp
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu() : _window(sf::VideoMode::getFullscreenModes()[0], "SFML Window", sf::Style::Fullscreen)
{
    loadMenu();
}

Menu::~Menu()
{
}

void Menu::loopMenu()
{
    while (_window.isOpen()) {
        Event();
        _window.clear(sf::Color::Black);
        _window.draw(_textbox);
        _window.draw(_text);
        _window.display();
    }
}

void Menu::Event()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (_textbox.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window)))) {
                _isFocused = true;
            } else {
                _isFocused = false;
            }
        }
        else if (event.type == sf::Event::TextEntered && _isFocused == true) {
            if (event.text.unicode < 128 && event.text.unicode != 8) {
                _input += static_cast<char>(event.text.unicode);
                _text.setString(_input);

                if (_text.getLocalBounds().width > _textbox.getSize().x) {
                    _text.move(-20, 0);
                }
            }
        }
        else if (event.type == sf::Event::KeyPressed && _isFocused == true) {
            if (_input.empty()) {
                _text.setPosition(_textbox.getPosition().x + 5, _textbox.getPosition().y + 5);
            }
            if (event.key.code == sf::Keyboard::BackSpace && !_input.empty()) {
                _input.pop_back();
                _text.setString(_input);
                if (_text.getLocalBounds().width < _textbox.getSize().x) {
                    _text.move(20, 0);
                }
            }
        }
    }
}

void Menu::loadMenu()
{
    _textbox.setSize(sf::Vector2f(200, 100));
    _textbox.setFillColor(sf::Color::White);
    _textbox.setPosition(100, 100);

    _font.loadFromFile("./assets/fonts/arcade_ya/ARCADE_R.ttf");
    _text.setFont(_font);
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::Black);
    _text.setPosition(105, 105);

    _isFocused = false;
}

void Menu::loadAssets()
{
    // Ici on loadera tout les assets du jeu
}
