/*
** EPITECH PROJECT, 2023
** Object.hpp
** File description:
** Object
*/

#ifndef OBJECT_HPP_
    #define OBJECT_HPP_
    #include <SFML/Graphics.hpp>
    #include <asio.hpp>
    #include <iostream>
    #include <thread>
    #include <vector>
    #include <memory>

    class Object {
        public:
            Object(std::string type, std::string id, std::string x, std::string y, std::string status);
            ~Object();
            void draw(sf::RenderWindow &window);
            int get_id() const { return _id; }
            void set_position(sf::Vector2f position) { _position = position; }
            void set_color(sf::Color color) { _color = color; }
            void set_status(int status) { _status = status; }
            void set_type(std::string type) { _type = type; }
            sf::Vector2f get_position() const { return _position; }
            sf::Color get_color() const { return _color; }
            int get_status() const { return _status; }
            std::string get_type() const { return _type; }
        private:
            std::string _type;
            int _status;
            int _id;
            sf::Vector2f _position;
            sf::RectangleShape _shape;
            sf::Color _color;
    };

#endif /* !OBJECT_HPP_ */
