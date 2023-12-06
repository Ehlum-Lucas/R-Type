/*
** EPITECH PROJECT, 2023
** Object.cpp
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(std::string type, int id, float x, float y, int status) : _type(type), _id(id), _status(status), _color(sf::Color::White)
{
    _pos = sf::Vector2f(x, y);

    if (_type == "p1") {
        setColor(sf::Color::Green);
    } else if (_type == "p2") {
        setColor(sf::Color::Blue);
    } else if (_type == "e") {
        setColor(sf::Color::Red);
    } else if (_type == "b") {
        setColor(sf::Color::Yellow);
    }
}

Object::~Object() {}

void Object::draw(std::shared_ptr<sf::RenderWindow> window)
{
    if (drawed) {
        _shape.setPosition(_pos);
        _shape.setFillColor(_color);
        _shape.setSize(sf::Vector2f(100, 100));
        window->draw(_shape);
    }
}
