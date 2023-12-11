/*
** EPITECH PROJECT, 2023
** Menu.cpp
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu() : _window(sf::VideoMode(1920, 1080), "SFML Window")
{
    loadMenu();
}

Menu::~Menu()
{
}

void Menu::loopMenu()
{
    while (_window.isOpen()) {

        sf::Time deltaTime = _clock.restart();
        
        Update(deltaTime);
        Event();
        Draw();
    }
}

void Menu::Update(sf::Time deltaTime)
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
}

void Menu::Event()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        EventMouse(event);
        EventTextEntered(event);
        EventKey(event);
    }
}

void Menu::loadMenu()
{
    _font.loadFromFile("./assets/fonts/arcade_ya/ARCADE_R.ttf");

    // Title Port
    _titlePort.setFont(_font);
    _titlePort.setCharacterSize(40);
    _titlePort.setFillColor(sf::Color::White);
    _titlePort.setString("Port:");
    _titlePort.setPosition((_window.getSize().x / 2 - _titlePort.getGlobalBounds().width / 2) - 165, _window.getSize().y / 2 + 25);

    // Box Input for Port Server
    _textboxPort.setSize(sf::Vector2f(500, 50));
    _textboxPort.setFillColor(sf::Color::White);
    _textboxPort.setPosition(_window.getSize().x / 2 - _textboxPort.getSize().x / 2, (_window.getSize().y / 2) + 100);

    // Text for Port Server
    _textPort.setFont(_font);
    _textPort.setCharacterSize(24);
    _textPort.setFillColor(sf::Color::Black);

    // Title Ip
    _titleIp.setFont(_font);
    _titleIp.setCharacterSize(40);
    _titleIp.setFillColor(sf::Color::White);
    _titleIp.setString("IP:");
    _titleIp.setPosition((_window.getSize().x / 2 - _titleIp.getGlobalBounds().width / 2) - 210, _window.getSize().y / 2 - 125);

    // BoxInput for Ip Server
    _textboxIp.setSize(sf::Vector2f(500, 50));
    _textboxIp.setFillColor(sf::Color::White);
    _textboxIp.setPosition(_window.getSize().x / 2 - _textboxIp.getSize().x / 2, _window.getSize().y / 2 - 50);

    // Text for Ip Server
    _textIp.setFont(_font);
    _textIp.setCharacterSize(24);
    _textIp.setFillColor(sf::Color::Black);

    // Title
    _titleTexture.loadFromFile("./assets/images/title.png");
    _titleSprite.setTexture(_titleTexture);
    _titleSprite.setPosition(_window.getSize().x / 2 - _titleSprite.getGlobalBounds().width / 2, _window.getSize().y / 2 - 300);

    // Play Button
    _playButtonTexture.loadFromFile("./assets/images/play.png");
    _playButtonSprite.setTexture(_playButtonTexture);
    _playButtonHoverTexture.loadFromFile("./assets/images/playHover.png");
    _playButtonSprite.setPosition(_window.getSize().x / 2 - _playButtonSprite.getGlobalBounds().width / 2, _window.getSize().y / 2 + 200);

    // Background
    _backgroundTexture.loadFromFile("./assets/images/background.png");
    _backgroundPosition = sf::Vector2f(0, -1080);

    _backgroundRect.setSize(sf::Vector2f(2683, 2160));
    _backgroundRect.setTexture(&_backgroundTexture, false); 
    _backgroundRect.setPosition(_backgroundPosition);

    _diagonalSpeedBackground = 33.0f;

    // Stars
    _starTexture.loadFromFile("./assets/images/stars.png");
    _starPosition = sf::Vector2f(0, -1080);

    _starRect.setSize(sf::Vector2f(3840, 2160));
    _starRect.setTexture(&_starTexture, false);

    _diagonalSpeedStar = 42.0f;


    // Planets
    _planetTexture.loadFromFile("./assets/images/planet.png");
    _planetPosition = sf::Vector2f(0, -1080);

    _planetRect.setSize(sf::Vector2f(3840, 2160));
    _planetRect.setTexture(&_planetTexture, false);

    _diagonalSpeedPlanet = 55.0f;

    // Saturns
    _saturnTexture.loadFromFile("./assets/images/saturn.png");
    _saturnPosition = sf::Vector2f(0, -1080);

    _saturnRect.setSize(sf::Vector2f(3840, 2160));
    _saturnRect.setTexture(&_saturnTexture, false);

    _diagonalSpeedSaturn = 35.0f;

    // Rocks
    _rocksTexture.loadFromFile("./assets/images/rocks.png");
    _rocksPosition = sf::Vector2f(0, -1080);

    _rocksRect.setSize(sf::Vector2f(3840, 2160));
    _rocksRect.setTexture(&_rocksTexture, false);

    _diagonalSpeedRocks = 47.0f;

    _isFocusedIp = false;
    _isFocusedPort = false;
}

void Menu::loadAssets()
{
    // Ici on loadera tout les assets du jeu
}

void Menu::Draw()
{
    _window.clear(sf::Color::Black);
    _window.draw(_backgroundRect);
    _window.draw(_saturnRect);
    _window.draw(_starRect);
    _window.draw(_rocksRect);
    _window.draw(_planetRect);
    _window.draw(_textboxIp);
    _window.draw(_textIp);
    _window.draw(_textboxPort);
    _window.draw(_textPort);
    _window.draw(_titleSprite);
    _window.draw(_playButtonSprite);
    _window.draw(_titleIp);
    _window.draw(_titlePort);
    _window.display();
}

void Menu::EventKey(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            _window.close();
        }
        else if (_isFocusedIp == true || _isFocusedPort == true) {
            if (_inputIp.empty() && _isFocusedIp == true) {
                _textIp.setPosition(_textboxIp.getPosition().x + 5, _textboxIp.getPosition().y + 5);
            }
            if (event.key.code == sf::Keyboard::BackSpace && !_inputIp.empty() && _isFocusedIp == true) {
                _inputIp.pop_back();
                _textIp.setString(_inputIp);
                if (_textIp.getLocalBounds().width < _textboxIp.getSize().x) {
                    _textIp.move(20, 0);
                }
            }
            if (_inputPort.empty() && _isFocusedPort == true) {
                _textPort.setPosition(_textboxPort.getPosition().x + 5, _textboxPort.getPosition().y + 5);
            }
            if (event.key.code == sf::Keyboard::BackSpace && !_inputPort.empty() && _isFocusedPort == true) {
                _inputPort.pop_back();
                _textPort.setString(_inputPort);
                if (_textPort.getLocalBounds().width < _textboxPort.getSize().x) {
                    _textPort.move(20, 0);
                }
            }
        }
    }
}

void Menu::EventTextEntered(sf::Event event)
{
    if (event.type == sf::Event::TextEntered && (_isFocusedIp == true || _isFocusedPort == true)) {
        if (event.text.unicode < 128 && event.text.unicode != 8 && _isFocusedIp == true) {
            _inputIp += static_cast<char>(event.text.unicode);
            _textIp.setString(_inputIp);
            if (_textIp.getLocalBounds().width > _textboxIp.getSize().x) {
                _textIp.move(-20, 0);
            }
        }
        if (event.text.unicode < 128 && event.text.unicode != 8 && _isFocusedPort == true) {
            _inputPort += static_cast<char>(event.text.unicode);
            _textPort.setString(_inputPort);
            if (_textPort.getLocalBounds().width > _textboxPort.getSize().x) {
                _textPort.move(-20, 0);
            }
        }
    }
}

void Menu::EventMouse(sf::Event event)
{
    sf::Vector2f mousePos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));

    if (_playButtonSprite.getGlobalBounds().contains(mousePos)) {
        _playButtonSprite.setTexture(_playButtonHoverTexture);
    } else {
        _playButtonSprite.setTexture(_playButtonTexture);
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (_playButtonSprite.getGlobalBounds().contains(mousePos)) {
            std::cout << "Ip: " << _inputIp << std::endl;
            std::cout << "Port: " << _inputPort << std::endl;
        }
        if (_textboxIp.getGlobalBounds().contains(mousePos)) {
            _isFocusedIp = true;
            _isFocusedPort = false;
        } else if (_textboxPort.getGlobalBounds().contains(mousePos)) {
            _isFocusedPort = true;
            _isFocusedIp = false;
        } else {
            _isFocusedIp = false;
            _isFocusedPort = false;
        }
    }
}