/*
** EPITECH PROJECT, 2023
** Object.cpp
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(std::string type, std::string id, std::string x, std::string y, std::string status) : _type("default"), _status(std::stoi(status)), _id(std::stoi(id)), _position(sf::Vector2f(std::stoi(x), std::stoi(y))), _shape(sf::Vector2f(100, 100)), _color(sf::Color::White)
{
    if (type == "p") {
        _color = sf::Color::Green;
    } else if (type == "e") {
        _color = sf::Color::Red;
    } else if (type == "b") {
        _color = sf::Color::Blue;
    }
}

Object::~Object()
{
}

void Object::draw(sf::RenderWindow &window)
{
    _shape.setPosition(_position);
    _shape.setFillColor(_color);
    window.draw(_shape);
}

