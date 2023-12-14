/*
** EPITECH PROJECT, 2023
** Components.cpp
** File description:
** Components
*/

#ifndef COMPONENTS_HPP
    #define COMPONENTS_HPP
    #include <SFML/Graphics.hpp>

    #define COLOR_RED sf::Color(255, 0, 0)
    #define COLOR_GREEN sf::Color(0, 255, 0)
    #define COLOR_BLUE sf::Color(0, 0, 255)
    #define COLOR_YELLOW sf::Color(255, 255, 0)
    #define COLOR_MAGENTA sf::Color(255, 0, 255)
    #define COLOR_CYAN sf::Color(0, 255, 255)
    #define COLOR_WHITE sf::Color(255, 255, 255)
    #define COLOR_BLACK sf::Color(0, 0, 0)
    #define COLOR_ORANGE sf::Color(255, 165, 0)
    #define COLOR_PINK sf::Color(255, 192, 203)
    #define COLOR_GREY sf::Color(128, 128, 128)
    #define COLOR_BROWN sf::Color(165, 42, 42)
    #define COLOR_TRANSPARENT sf::Color(0, 0, 0, 0)

    class InputGestion {
        public:
            sf::Keyboard::Key get_key(std::string key)
            {
                if (key == "up") {
                    return sf::Keyboard::Up;
                } else if (key == "down") {
                    return sf::Keyboard::Down;
                } else if (key == "left") {
                    return sf::Keyboard::Left;
                } else if (key == "right") {
                    return sf::Keyboard::Right;
                } else if (key == "space") {
                    return sf::Keyboard::Space;
                } else if (key == "0") {
                    return sf::Keyboard::Num0;
                } else if (key == "1") {
                    return sf::Keyboard::Num1;
                } else if (key == "2") {
                    return sf::Keyboard::Num2;
                } else if (key == "3") {
                    return sf::Keyboard::Num3;
                } else if (key == "4") {
                    return sf::Keyboard::Num4;
                } else if (key == "5") {
                    return sf::Keyboard::Num5;
                } else if (key == "6") {
                    return sf::Keyboard::Num6;
                } else if (key == "7") {
                    return sf::Keyboard::Num7;
                } else if (key == "8") {
                    return sf::Keyboard::Num8;
                } else if (key == "9") {
                    return sf::Keyboard::Num9;
                } else if (key == "a") {
                    return sf::Keyboard::A;
                } else if (key == "b") {
                    return sf::Keyboard::B;
                } else if (key == "c") {
                    return sf::Keyboard::C;
                } else if (key == "d") {
                    return sf::Keyboard::D;
                } else if (key == "e") {
                    return sf::Keyboard::E;
                } else if (key == "f") {
                    return sf::Keyboard::F;
                } else if (key == "g") {
                    return sf::Keyboard::G;
                } else if (key == "h") {
                    return sf::Keyboard::H;
                } else if (key == "i") {
                    return sf::Keyboard::I;
                } else if (key == "j") {
                    return sf::Keyboard::J;
                } else if (key == "k") {
                    return sf::Keyboard::K;
                } else if (key == "l") {
                    return sf::Keyboard::L;
                } else if (key == "m") {
                    return sf::Keyboard::M;
                } else if (key == "n") {
                    return sf::Keyboard::N;
                } else if (key == "o") {
                    return sf::Keyboard::O;
                } else if (key == "p") {
                    return sf::Keyboard::P;
                } else if (key == "q") {
                    return sf::Keyboard::Q;
                } else if (key == "r") {
                    return sf::Keyboard::R;
                } else if (key == "s") {
                    return sf::Keyboard::S;
                } else if (key == "t") {
                    return sf::Keyboard::T;
                } else if (key == "u") {
                    return sf::Keyboard::U;
                } else if (key == "v") {
                    return sf::Keyboard::V;
                } else if (key == "w") {
                    return sf::Keyboard::W;
                } else if (key == "x") {
                    return sf::Keyboard::X;
                } else if (key == "y") {
                    return sf::Keyboard::Y;
                } else if (key == "z") {
                    return sf::Keyboard::Z;
                } else if (key == "f1") {
                    return sf::Keyboard::F1;
                } else if (key == "f2") {
                    return sf::Keyboard::F2;
                } else if (key == "f3") {
                    return sf::Keyboard::F3;
                } else if (key == "f4") {
                    return sf::Keyboard::F4;
                } else if (key == "f5") {
                    return sf::Keyboard::F5;
                } else if (key == "f6") {
                    return sf::Keyboard::F6;
                } else if (key == "f7") {
                    return sf::Keyboard::F7;
                } else if (key == "f8") {
                    return sf::Keyboard::F8;
                } else if (key == "f9") {
                    return sf::Keyboard::F9;
                } else if (key == "f10") {
                    return sf::Keyboard::F10;
                } else if (key == "f11") {
                    return sf::Keyboard::F11;
                } else if (key == "f12") {
                    return sf::Keyboard::F12;
                } else if (key == "f13") {
                    return sf::Keyboard::F13;
                } else if (key == "f14") {
                    return sf::Keyboard::F14;
                } else if (key == "f15") {
                    return sf::Keyboard::F15;
                } else if (key == "rctrl") {
                    return sf::Keyboard::RControl;
                } else if (key == "lctrl") {
                    return sf::Keyboard::LControl;
                }
                
                return sf::Keyboard::Unknown;
            };

    };

    // position component
    class Position {
        public:
            Position(float x, float y) : x(x), y(y) {};
            float x;
            float y;
    };

    // velocity component
    class Velocity {
        public:
            Velocity(float vx, float vy) : vx(vx), vy(vy) {};
            float vx;
            float vy;
    };

    // circle shape component
    class CircleShape {
        public:
            CircleShape(float radius) : shape(radius) {};
            sf::CircleShape shape;
    };

    // rectangle shape component
    class RectangleShape {
        public:
            RectangleShape(float width, float height) : shape(sf::Vector2f(width, height)) {};
            sf::RectangleShape shape;
    };

    // drawable component
    class Drawable {
        public:
            Drawable() {};
    };

    // color component
    class Color {
        public:
            Color(sf::Color color) : color(color) {};
            sf::Color color;
    };

    // gravity component
    class Gravity {
        public:
            Gravity(float gravity_force, std::string direction = "y") : gravity_force(gravity_force), direction(direction) {};
            float gravity_force;
            std::string direction;
    };

    // controller component
    class Controller {
        public:
            Controller(bool can_go_up, bool can_go_right, bool can_go_left, bool can_go_down, std::string up, std::string down, std::string left, std::string right) : can_go_up(can_go_up), can_go_right(can_go_right), can_go_left(can_go_left), can_go_down(can_go_down) {
                this->up = inputGestion.get_key(up);
                this->down = inputGestion.get_key(down);
                this->left = inputGestion.get_key(left);
                this->right = inputGestion.get_key(right);
            };
            bool can_go_up;
            bool can_go_right;
            bool can_go_left;
            bool can_go_down;
            sf::Keyboard::Key up;
            sf::Keyboard::Key down;
            sf::Keyboard::Key left;
            sf::Keyboard::Key right;
        private:
            InputGestion inputGestion;
    };

    // speed component
    class Speed {
        public:
            Speed(float speed) : speed(speed) {}
            float speed;
    };

    // sprite component
    class Sprite {
        public:
            Sprite(std::string texture_path, float angle = 0.0) : texture_path(texture_path)
            {
                texture.loadFromFile(texture_path);
                sprite.setTexture(texture);
                sprite.setRotation(angle);
                sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
            };
            sf::Texture texture;
            std::string texture_path;
            sf::Sprite sprite;
    };

    // size component
    class Size {
        public:
            Size(float width, float height) : width(width), height(height) {};
            float width;
            float height;
    };

    // shoot component
    class Shoot {
        public:
            Shoot(float angle, float speed, std::string _input, std::string _texture_path, float _width, float _height, float _delay, float _rotate = 0.0) : angle(angle), speed(speed) {
                this->input = inputGestion.get_key(_input);
                texture_path = _texture_path;
                width = _width;
                height = _height;
                delay = _delay;
                timer = delay;
            };
            float angle;
            float speed;
            sf::Keyboard::Key input;
            std::string texture_path;
            float width;
            float height;
            float rotate;
            float timer;
            float delay;
        private:
            InputGestion inputGestion;
    };

    // box collider component
    class BoxCollider {
        public:
            BoxCollider(std::string _tag, bool _draw = false, sf::Color _color = COLOR_RED) {
                tag = _tag;
                draw = _draw;
                color = _color;
            };
            bool draw;
            std::string tag;
            sf::Color color;
    };

    class Id {
        public:
            Id(size_t id) : id(id) {};
            size_t id;
    };

    class Shootable {
        public:
            Shootable() {};
    };

    class OnClickLoadScene {
        public:
            OnClickLoadScene(std::string _scene_name) {
                scene_name = _scene_name;
            };
            std::string scene_name;
    };

#endif //COMPONENTS_HPP