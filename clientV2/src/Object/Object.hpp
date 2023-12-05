/*
** EPITECH PROJECT, 2023
** Object.hpp
** File description:
** Object
*/

#ifndef OBJECT_HPP_
    #define OBJECT_HPP_
    #include <SFML/Graphics.hpp>
    #include <memory>
    #include <iostream>
    #include <sstream>
    #include <string>

    class Object {
        public:
            Object(std::string type, int id, float x, float y, int status);
            ~Object();
            void draw(std::shared_ptr<sf::RenderWindow> window);
            int getId() const { return _id; }
            void setPosition(sf::Vector2f position) { _pos = position; }
            void setColor(sf::Color color) { _color = color; }
            void setStatus(int status) { _status = status; }
            void setType(std::string type) { _type = type; }
            sf::Vector2f getPosition() const { return _pos; }
            sf::Color getColor() const { return _color; }
            int getStatus() const { return _status; }
            std::string getType() const { return _type; }

        protected:
        private:
            std::string _type;
            int _id;
            int _status;
            sf::Vector2f _pos;
            sf::RectangleShape _shape;
            sf::Color _color;
    };

#endif /* !OBJECT_HPP_ */
