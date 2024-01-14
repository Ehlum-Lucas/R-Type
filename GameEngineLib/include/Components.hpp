/*
** EPITECH PROJECT, 2023
** Components.cpp
** File description:
** Components
*/

/**
 * @file Components.hpp
 * @brief This file contains the implementation of the `Components` class.
 */

#ifndef COMPONENTS_HPP
    #define COMPONENTS_HPP
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
    #include "Registry.hpp"
    #include <any>
    #include "TexturesLoader.hpp"

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

    #define COLOR_RED_128 sf::Color(255, 0, 0, 128)
    #define COLOR_GREEN_128 sf::Color(0, 255, 0, 128)
    #define COLOR_BLUE_128 sf::Color(0, 0, 255)
    #define COLOR_YELLOW_128 sf::Color(255, 255, 0, 128)
    #define COLOR_MAGENTA_128 sf::Color(255, 0, 255)
    #define COLOR_CYAN_128 sf::Color(0, 255, 255)
    #define COLOR_WHITE_128 sf::Color(255, 255, 255)
    #define COLOR_BLACK_128 sf::Color(0, 0, 0, 128)
    #define COLOR_ORANGE_128 sf::Color(255, 165, 0, 128)
    #define COLOR_PINK_128 sf::Color(255, 192, 203)
    #define COLOR_GREY_128 sf::Color(128, 128, 0, 128)
    #define COLOR_BROWN_128 sf::Color(165, 42, 42)
    #define COLOR_TRANSPARENT_128 sf::Color(0, 0, 0, 0, 128)

    /**
     * @brief Maps a string representation of a key to its corresponding sf::Keyboard::Key value.
     * 
     * @param key The string representation of the key.
     * @return The sf::Keyboard::Key value corresponding to the given key string.
     *         If the key string is not recognized, sf::Keyboard::Unknown is returned.
     */
    
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
            }

              /**
             * @brief Converts a binary key code to an sf::Keyboard::Key.
             * 
             * This function takes a binary key code as a string and returns the corresponding sf::Keyboard::Key.
             * The binary key codes are used to represent specific keys on the keyboard.
             * 
             * @param key The binary key code as a string.
             * @return The corresponding sf::Keyboard::Key.
             *         If the key code is not recognized, sf::Keyboard::Unknown is returned.
             */

            sf::Keyboard::Key binary_to_sf_key(std::string key) {
                if (key == "9001") {
                    return sf::Keyboard::Up;
                } else if (key == "9002") {
                    return sf::Keyboard::Down;
                } else if (key == "9003") {
                    return sf::Keyboard::Left;
                } else if (key == "9004") {
                    return sf::Keyboard::Right;
                } else if (key == "9005") {
                    return sf::Keyboard::Space;
                } else if (key == "9006") {
                    return sf::Keyboard::Num0;
                } else if (key == "9007") {
                    return sf::Keyboard::Num1;
                } else if (key == "9008") {
                    return sf::Keyboard::Num2;
                } else if (key == "909") {
                    return sf::Keyboard::Num3;
                } else if (key == "9010") {
                    return sf::Keyboard::Num4;
                } else if (key == "9011") {
                    return sf::Keyboard::Num5;
                } else if (key == "9012") {
                    return sf::Keyboard::Num6;
                } else if (key == "9013") {
                    return sf::Keyboard::Num7;
                } else if (key == "9014") {
                    return sf::Keyboard::Num8;
                } else if (key == "9015") {
                    return sf::Keyboard::Num9;
                } else if (key == "9016") {
                    return sf::Keyboard::A;
                } else if (key == "9017") {
                    return sf::Keyboard::B;
                } else if (key == "9018") {
                    return sf::Keyboard::C;
                } else if (key == "9019") {
                    return sf::Keyboard::D;
                } else if (key == "9020") {
                    return sf::Keyboard::E;
                } else if (key == "9021") {
                    return sf::Keyboard::F;
                } else if (key == "9022") {
                    return sf::Keyboard::G;
                } else if (key == "9023") {
                    return sf::Keyboard::H;
                } else if (key == "9024") {
                    return sf::Keyboard::I;
                } else if (key == "9025") {
                    return sf::Keyboard::J;
                } else if (key == "9026") {
                    return sf::Keyboard::K;
                } else if (key == "9027") {
                    return sf::Keyboard::L;
                } else if (key == "9028") {
                    return sf::Keyboard::M;
                } else if (key == "9029") {
                    return sf::Keyboard::N;
                } else if (key == "9030") {
                    return sf::Keyboard::O;
                } else if (key == "9031") {
                    return sf::Keyboard::P;
                } else if (key == "9032") {
                    return sf::Keyboard::Q;
                } else if (key == "9033") {
                    return sf::Keyboard::R;
                } else if (key == "9034") {
                    return sf::Keyboard::S;
                } else if (key == "9035") {
                    return sf::Keyboard::T;
                } else if (key == "9036") {
                    return sf::Keyboard::U;
                } else if (key == "9037") {
                    return sf::Keyboard::V;
                } else if (key == "9038") {
                    return sf::Keyboard::W;
                } else if (key == "9039") {
                    return sf::Keyboard::X;
                } else if (key == "9040") {
                    return sf::Keyboard::Y;
                } else if (key == "9041") {
                    return sf::Keyboard::Z;
                } else if (key == "9042") {
                    return sf::Keyboard::F1;
                } else if (key == "9043") {
                    return sf::Keyboard::F2;
                } else if (key == "9044") {
                    return sf::Keyboard::F3;
                } else if (key == "9045") {
                    return sf::Keyboard::F4;
                } else if (key == "9046") {
                    return sf::Keyboard::F5;
                } else if (key == "9047") {
                    return sf::Keyboard::F6;
                } else if (key == "9048") {
                    return sf::Keyboard::F7;
                } else if (key == "9049") {
                    return sf::Keyboard::F8;
                } else if (key == "9050") {
                    return sf::Keyboard::F9;
                } else if (key == "9051") {
                    return sf::Keyboard::F10;
                } else if (key == "9052") {
                    return sf::Keyboard::F11;
                } else if (key == "9053") {
                    return sf::Keyboard::F12;
                } else if (key == "9054") {
                    return sf::Keyboard::F13;
                } else if (key == "9055") {
                    return sf::Keyboard::F14;
                } else if (key == "9056") {
                    return sf::Keyboard::F15;
                } else if (key == "9057") {
                    return sf::Keyboard::RControl;
                } else if (key == "9058") {
                    return sf::Keyboard::LControl;
                }
                return sf::Keyboard::Unknown;
            }

            /**
             * @brief Converts an SFML keyboard key to a binary string representation.
             * 
             * This function takes an SFML keyboard key as input and returns a binary string representation of the key.
             * The binary string representation is a unique identifier for each key.
             * 
             * @param key The SFML keyboard key to convert.
             * @return The binary string representation of the key.
             *         If the key is not recognized, the function returns "9000".
             */

            std::string sf_key_to_binary(sf::Keyboard::Key key) {
                if (key == sf::Keyboard::Up) {
                    return "9001";
                } else if (key == sf::Keyboard::Down) {
                    return "9002";
                } else if (key == sf::Keyboard::Left) {
                    return "9003";
                } else if (key == sf::Keyboard::Right) {
                    return "9004";
                } else if (key == sf::Keyboard::Space) {
                    return "9005";
                } else if (key == sf::Keyboard::Num0) {
                    return "9006";
                } else if (key == sf::Keyboard::Num1) {
                    return "9007";
                } else if (key == sf::Keyboard::Num2) {
                    return "9008";
                } else if (key == sf::Keyboard::Num3) {
                    return "9009";
                } else if (key == sf::Keyboard::Num4) {
                    return "9010";
                } else if (key == sf::Keyboard::Num5) {
                    return "9011";
                } else if (key == sf::Keyboard::Num6) {
                    return "9012";
                } else if (key == sf::Keyboard::Num7) {
                    return "9013";
                } else if (key == sf::Keyboard::Num8) {
                    return "9014";
                } else if (key == sf::Keyboard::Num9) {
                    return "9015";
                } else if (key == sf::Keyboard::A) {
                    return "9016";
                } else if (key == sf::Keyboard::B) {
                    return "9017";
                } else if (key == sf::Keyboard::C) {
                    return "9018";
                } else if (key == sf::Keyboard::D) {
                    return "9019";
                } else if (key == sf::Keyboard::E) {
                    return "9020";
                } else if (key == sf::Keyboard::F) {
                    return "9021";
                } else if (key == sf::Keyboard::G) {
                    return "9022";
                } else if (key == sf::Keyboard::H) {
                    return "9023";
                } else if (key == sf::Keyboard::I) {
                    return "9024";
                } else if (key == sf::Keyboard::J) {
                    return "9025";
                } else if (key == sf::Keyboard::K) {
                    return "9026";
                } else if (key == sf::Keyboard::L) {
                    return "9027";
                } else if (key == sf::Keyboard::M) {
                    return "9028";
                } else if (key == sf::Keyboard::N) {
                    return "9029";
                } else if (key == sf::Keyboard::O) {
                    return "9030";
                } else if (key == sf::Keyboard::P) {
                    return "9031";
                } else if (key == sf::Keyboard::Q) {
                    return "9032";
                } else if (key == sf::Keyboard::R) {
                    return "9033";
                } else if (key == sf::Keyboard::S) {
                    return "9034";
                } else if (key == sf::Keyboard::T) {
                    return "9035";
                } else if (key == sf::Keyboard::U) {
                    return "9036";
                } else if (key == sf::Keyboard::V) {
                    return "9037";
                } else if (key == sf::Keyboard::W) {
                    return "9038";
                } else if (key == sf::Keyboard::X) {
                    return "9039";
                } else if (key == sf::Keyboard::Y) {
                    return "9040";
                } else if (key == sf::Keyboard::Z) {
                    return "9041";
                } else if (key == sf::Keyboard::F1) {
                    return "9042";
                } else if (key == sf::Keyboard::F2) {
                    return "9043";
                } else if (key == sf::Keyboard::F3) {
                    return "9044";
                } else if (key == sf::Keyboard::F4) {
                    return "9045";
                } else if (key == sf::Keyboard::F5) {
                    return "9046";
                } else if (key == sf::Keyboard::F6) {
                    return "9047";
                } else if (key == sf::Keyboard::F7) {
                    return "9048";
                } else if (key == sf::Keyboard::F8) {
                    return "9049";
                } else if (key == sf::Keyboard::F9) {
                    return "9050";
                } else if (key == sf::Keyboard::F10) {
                    return "9051";
                } else if (key == sf::Keyboard::F11) {
                    return "9052";
                } else if (key == sf::Keyboard::F12) {
                    return "9053";
                } else if (key == sf::Keyboard::F13) {
                    return "9054";
                } else if (key == sf::Keyboard::F14) {
                    return "9055";
                } else if (key == sf::Keyboard::F15) {
                    return "9056";
                } else if (key == sf::Keyboard::RControl) {
                    return "9057";
                } else if (key == sf::Keyboard::LControl) {
                    return "9058";
                }

                return "9000";
            }
    };


    // position component
    /**
     * @class Position
     * @brief Represents the position of an object in 2D space.
     */
    class Position {
        public:
            /**
             * @brief Constructs a Position object with the given coordinates.
             * @param x The x-coordinate of the position.
             * @param y The y-coordinate of the position.
             */
            Position(float x, float y) : x(x), y(y) {};

            float x; /**< The x-coordinate of the position. */
            float y; /**< The y-coordinate of the position. */
    };

    // velocity component
    /**
     * @class Velocity
     * @brief Represents the velocity of an object in a 2D space.
     */
    class Velocity {
        public:
            /**
             * @brief Constructs a Velocity object with the given x and y components.
             * @param vx The x component of the velocity.
             * @param vy The y component of the velocity.
             */
            Velocity(float vx, float vy) : vx(vx), vy(vy) {};

            float vx; /**< The x component of the velocity. */
            float vy; /**< The y component of the velocity. */
    };

    // circle shape component
    /**
     * @class CircleShape
     * @brief Represents a circle shape component.
     *
     * The CircleShape class is used to create and manipulate circle shapes in a game engine.
     * It provides a sf::CircleShape object and a radius value to define the size of the circle.
     */
    class CircleShape {
        public:
            /**
             * @brief Constructor for CircleShape.
             * @param radius The radius of the circle shape.
             */
            CircleShape(float radius) : shape(radius) {};

            sf::CircleShape shape; /**< The sf::CircleShape object representing the circle shape. */
            float radius; /**< The radius of the circle shape. */
    };

    // rectangle shape component
    /**
     * @class RectangleShape
     * @brief Represents a rectangle shape in the game engine.
     *
     * This class encapsulates a rectangle shape with a specified width and height.
     * It is used to define the shape of game objects in the R-Type game engine.
     */
    class RectangleShape {
        public:
            /**
             * @brief Constructs a RectangleShape object with the given width and height.
             * @param width The width of the rectangle shape.
             * @param height The height of the rectangle shape.
             */
            RectangleShape(float width, float height) : shape(sf::Vector2f(width, height)) {};

            sf::RectangleShape shape; /**< The SFML rectangle shape. */
            float width; /**< The width of the rectangle shape. */
            float height; /**< The height of the rectangle shape. */
    };

    // drawable component
    /**
     * @class Drawable
     * @brief Represents a drawable component.
     *
     * The Drawable class is a base class for components that can be drawn on the screen.
     * It provides a default constructor.
     */
    class Drawable {
        public:
            Drawable() {};
    };

    // color component
    /**
     * @class Color
     * @brief Represents a color component.
     *
     * The Color class is used to define the color of a drawable component.
     * It provides a sf::Color object to represent the color.
     */
    class Color {
        public:
            /**
             * @brief Constructs a Color object with the given color.
             * @param color The color of the drawable component.
             */
            Color(sf::Color color) : color(color) {}; 
            sf::Color color; /**< The color of the drawable component. */
    };

    // gravity component
    /**
     * @class Gravity
     * @brief Represents a gravity component.
     *
     * The Gravity class is used to define the gravity of an object.
     * It provides a gravity force value and a direction value.
     */
    class Gravity {
        public:
            /**
             * @brief Constructs a Gravity object with the given gravity force and direction.
             * @param gravity_force The gravity force of the object.
             * @param direction The direction of the gravity force.
             */
            Gravity(float gravity_force, std::string direction = "y") : gravity_force(gravity_force), direction(direction) {};
            float gravity_force; /**< The gravity force of the object. */
            std::string direction; /**< The direction of the gravity force. */
    };

    // addForce component
    /**
     * @class AddForce
     * @brief Represents an addForce component.
     *
     * The AddForce class is used to define a force that can be applied to an object.
     * It provides a force value, an end point value, a direction value and an input value.
     */
    class AddForce {
        public:
            /**
             * @brief Constructs an AddForce object with the given force, end point, input and direction.
             * @param force The force to apply to the object.
             * @param end_point The end point of the force.
             * @param input The input that triggers the force.
             * @param direction The direction of the force.
             */
            AddForce(float _force, float _end_point, std::string _input, std::string _direction = "y") {
                force = _force;
                end_point = _end_point;
                direction = _direction;
                input = inputGestion.get_key(_input);
            };
            float force; /**< The force to apply to the object. */
            float end_point; /**< The end point of the force. */
            float start_x; /**< The starting x-coordinate of the force. */
            float start_y; /**< The starting y-coordinate of the force. */
            bool processing = false; /**< A boolean value indicating whether the force is being applied. */
            bool key_was_pressed = false; /**< A boolean value indicating whether the input key was pressed. */
            std::string direction; /**< The direction of the force. */
            sf::Keyboard::Key input; /**< The input that triggers the force. */

        private:
            InputGestion inputGestion; /**< The InputGestion object used to convert input strings to sf::Keyboard::Key values. */
    };

    // controller component
    /**
     * @class Controller
     * @brief Represents a controller component.
     *
     * The Controller class is used to define the controls of an object.
     * It provides a boolean value for each direction to indicate whether the object can move in that direction.
     * It also provides an input value for each direction.
     */
    class Controller {
        public:
            /**
             * @brief Constructs a Controller object with the given control values.
             * @param can_go_up A boolean value indicating whether the object can move up.
             * @param can_go_down A boolean value indicating whether the object can move down.
             * @param can_go_left A boolean value indicating whether the object can move left.
             * @param can_go_right A boolean value indicating whether the object can move right.
             * @param _up The input that triggers the object to move up.
             * @param _down The input that triggers the object to move down.
             * @param _left The input that triggers the object to move left.
             * @param _right The input that triggers the object to move right.
             */
            Controller(bool can_go_up, bool can_go_down, bool can_go_left, bool can_go_right, std::string _up, std::string _down, std::string _left, std::string _right) : can_go_up(can_go_up), can_go_right(can_go_right), can_go_left(can_go_left), can_go_down(can_go_down) {
                this->up = inputGestion.get_key(_up);
                this->down = inputGestion.get_key(_down);
                this->left = inputGestion.get_key(_left);
                this->right = inputGestion.get_key(_right);
            };
            Controller(bool can_go_up, bool can_go_down, bool can_go_left, bool can_go_right, sf::Keyboard::Key _up, sf::Keyboard::Key _down, sf::Keyboard::Key _left, sf::Keyboard::Key _right) : can_go_up(can_go_up), can_go_right(can_go_right), can_go_left(can_go_left), can_go_down(can_go_down) {
                this->up = _up;
                this->down = _down;
                this->left = _left;
                this->right = _right;
            };
            bool can_go_up; /**< A boolean value indicating whether the object can move up. */
            bool can_go_right; /**< A boolean value indicating whether the object can move right. */
            bool can_go_left; /**< A boolean value indicating whether the object can move left. */
            bool can_go_down; /**< A boolean value indicating whether the object can move down. */
            sf::Keyboard::Key up; /**< The input that triggers the object to move up. */
            sf::Keyboard::Key down; /**< The input that triggers the object to move down. */
            sf::Keyboard::Key left; /**< The input that triggers the object to move left. */
            sf::Keyboard::Key right; /**< The input that triggers the object to move right. */
        private:
            InputGestion inputGestion; /**< The InputGestion object used to convert input strings to sf::Keyboard::Key values. */
    };

    // speed component
    /**
     * @class Speed
     * @brief Represents a speed component.
     *
     * The Speed class is used to define the speed of an object.
     * It provides a speed value and a direction value.
     */
    class Speed {
        public:
            /**
             * @brief Constructs a Speed object with the given speed and direction.
             * @param speed The speed of the object.
             * @param direction The direction of the speed.
             */
            Speed(float speed) : speed(speed) {}
            float speed; /**< The speed of the object. */
    };

    // sprite component
    /**
     * @class Sprite
     * @brief Represents a sprite component.
     *
     * The Sprite class is used to define the sprite of an object.
     * It provides a sf::Sprite object and a texture path value.
     */
    class Sprite {
        public:
            /**
             * @brief Constructs a Sprite object with the given texture path.
             * @param texture_path The path to the texture of the sprite.
             */
            Sprite(std::string texture_path, float _angle = 0.0) : texture_path(texture_path)
            {
                texture = texturesLoader.get_texture(texture_path);
                sprite.setTexture(*texture.get());
                angle = _angle;
                sprite.setRotation(angle);
                sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
            };
            std::shared_ptr<sf::Texture> texture; /**< The texture of the sprite. */
            std::string texture_path; /**< The path to the texture of the sprite. */
            sf::Sprite sprite; /**< The sf::Sprite object representing the sprite. */
            float angle; /**< The angle of the sprite. */
    };


    // animated sprite component
    class AnimatedSprite {
        public:
            AnimatedSprite(std::string texture_path, float _angle = 0.0, float sprite_size_x = 0.0, float sprite_size_y = 0.0, float _start_frame = 0.0, float _max_frame = 0.0, float _speed = 1.0) : texture_path(texture_path)
            {
                texture = texturesLoader.get_texture(texture_path);
                sprite.setTexture(*texture.get());
                angle = _angle;
                sprite.setRotation(angle);
                sprite.setOrigin(sprite_size_x / 2, sprite_size_y / 2);
                rect = sf::IntRect(sprite_size_x * _start_frame, 0, sprite_size_x, sprite_size_y);
                sprite.setTextureRect(rect);
                start_frame = _start_frame;
                max_frame = _max_frame;
                speed = _speed;
            };
            std::shared_ptr<sf::Texture> texture;
            std::string texture_path;
            sf::Sprite sprite;
            sf::IntRect rect;
            sf::Clock clock;
            int start_frame;
            int max_frame;
            float speed;
            float angle;
    };

    // size component
    /**
     * @class Size
     * @brief Represents a size component.
     *
     * The Size class is used to define the size of an object.
     * It provides a width value and a height value.
     */
    class Size {
        public:
            /**
             * @brief Constructs a Size object with the given width and height.
             * @param width The width of the object.
             * @param height The height of the object.
             */
            Size(float width, float height) : width(width), height(height) {};
            float width; /**< The width of the object. */
            float height; /**< The height of the object. */
    };

    // spawn component
    /**
     * @class Spawn
     * @brief Represents a spawn component.
     *
     * The Spawn class is used to define the spawn of an object.
     * It provides a spawn delay value and a prefab name value.
     */
    class SpawnWithInput {
        public:
            /**
             * @brief Constructor for SpawnWithInput.
             * @param _prefab_name The name of the prefab to spawn.
             * @param _input The input that triggers the spawn.
             * @param _delay The delay before spawning.
             * @param _at_parent_pos A boolean value indicating whether the prefab should be spawned at the parent's position.
             * @param _angle The angle of the prefab (default: 0.0).
             */
            SpawnWithInput(std::string _prefab_name, std::string _input, float _delay, bool _at_parent_pos, float _angle = 0.0) : prefab_name(_prefab_name)
            {
                input = inputGestion.get_key(_input);
                timer = _delay;
                delay = _delay;
                angle = _angle;
                at_parent_pos = _at_parent_pos;
            };
            SpawnWithInput(std::string _prefab_name, sf::Keyboard::Key _input, float _delay, bool _at_parent_pos, float _angle = 0.0) : prefab_name(_prefab_name)
            {
                input = _input;
                timer = _delay;
                delay = _delay;
                angle = _angle;
                at_parent_pos = _at_parent_pos;
            };
            std::string prefab_name; /**< The name of the prefab to spawn. */
            float angle; /**< The angle of the prefab. */
            float timer; /**< The timer of the prefab. */
            float delay; /**< The delay of the prefab. */
            sf::Keyboard::Key input; /**< The input that triggers the spawn. */
            bool at_parent_pos; /**< A boolean value indicating whether the prefab should be spawned at the parent's position. */
        private:
            InputGestion inputGestion; /**< The InputGestion object used to convert input strings to sf::Keyboard::Key values. */   
            
    };

    // box collider component
    /**
     * @class BoxCollider
     * @brief Represents a box collider component.
     *
     * The BoxCollider class is used to define a box collider for an object.
     * It provides a tag value, a width value, a height value, an origin x-coordinate value, an origin y-coordinate value, a draw value and a color value.
     */
    class BoxCollider {
        public:
            /**
             * @brief Constructs a BoxCollider object with the given tag, width, height, origin x-coordinate, origin y-coordinate, draw value and color.
             * @param _tag The tag of the box collider.
             * @param _width The width of the box collider.
             * @param _height The height of the box collider.
             * @param _origin_x The origin x-coordinate of the box collider.
             * @param _origin_y The origin y-coordinate of the box collider.
             * @param _draw A boolean value indicating whether the box collider should be drawn.
             * @param _color The color of the box collider.
             */
            BoxCollider(std::string _tag, float _width, float _height, float _origin_x = 0.0, float _origin_y = 0.0, bool _draw = false, sf::Color _color = COLOR_RED) {
                tag = _tag;
                draw = _draw;
                color = _color;
                width = _width;
                height = _height;
                origin_x = _origin_x;
                origin_y = _origin_y;
                collider = std::make_shared<sf::RectangleShape>(sf::Vector2f(width,height));
            };
            bool draw; /**< A boolean value indicating whether the box collider should be drawn. */
            std::string tag; /**< The tag of the box collider. */
            sf::Color color; /**< The color of the box collider. */
            std::shared_ptr<sf::RectangleShape> collider; /**< The sf::RectangleShape object representing the box collider. */
            float width; /**< The width of the box collider. */
            float height; /**< The height of the box collider. */
            float origin_x; /**< The origin x-coordinate of the box collider. */
            float origin_y; /**< The origin y-coordinate of the box collider. */
            bool collide = true; /**< A boolean value indicating whether the box collider should collide. */
    };

    // ShowCollisionsWithInput
    /**
     * @class ShowCollisionsWithInput
     * @brief Represents a ShowCollisionsWithInput component.
     *
     * The ShowCollisionsWithInput class is used to define a ShowCollisionsWithInput component for an object.
     * It provides an input value.
     */
    class ShowCollisionsWithInput {
        public:
            /**
             * @brief Constructs a ShowCollisionsWithInput object with the given input.
             * @param _input The input that triggers the ShowCollisionsWithInput.
             */
            ShowCollisionsWithInput(std::string _input) {input = inputGestion.get_key(_input);};

            sf::Keyboard::Key input; /**< The input that triggers the ShowCollisionsWithInput. */
            bool showed = false; /**< A boolean value indicating whether the ShowCollisionsWithInput was showed. */
            bool released = true; /**< A boolean value indicating whether the input was released. */
        private:
            InputGestion inputGestion; /**< The InputGestion object used to convert input strings to sf::Keyboard::Key values. */
    };

    // OnCollideStop
    /**
     * @class OnCollideStop
     * @brief Represents an OnCollideStop component.
     *
     * The OnCollideStop class is used to define an OnCollideStop component for an object.
     * It provides a tag value.
     */
    class OnCollideStop {
        public:
            /**
             * @brief Constructs an OnCollideStop object with the given tag.
             * @param _tag The tag of the OnCollideStop.
             */
            OnCollideStop(std::string _tag) {tag =_tag;};
            std::string tag; /**< The tag of the OnCollideStop. */
    };

    // Id
    /**
     * @class Id
     * @brief Represents an Id component.
     *
     * The Id class is used to define an Id component for an object.
     * It provides an id value.
     */
    class Id {
        public:
            /**
             * @brief Constructs an Id object with the given id.
             * @param id The id of the Id.
             */
            Id(size_t id) : id(id) {};
            size_t id; /**< The id */
    };

    // Shootable
    /**
     * @class Shootable
     * @brief Represents a Shootable component.
     *
     * The Shootable class is used to define a Shootable component for an object.
     * It provides a boolean value indicating whether the object is shootable.
     */
    class Shootable {
        public:
            /**
             * @brief Constructs a Shootable object with the given shootable value.
             * @param _shootable A boolean value indicating whether the object is shootable.
             */
            Shootable() {};
    };

    // OnCLickLoadScene
    /**
     * @class OnClickLoadScene
     * @brief Represents a component that triggers a scene load when clicked.
     */
    class OnClickLoadScene {
        public:
            /**
             * @brief Constructs an OnClickLoadScene object with the specified scene name.
             * @param _scene_name The name of the scene to load.
             */
            OnClickLoadScene(std::string _scene_name) {
                scene_name = _scene_name;
            };
            std::string scene_name; /**< The name of the scene to load. */
    };

    // Type
    /**
     * @class Type
     * @brief Represents a component that defines the type of an object.
     */
    class Type {
        public:
            /**
             * @brief Constructs a Type object with the specified type.
             * @param _type The type of the object.
             */
            Type(size_t _type) {type = _type;};
            size_t type; /**< The type of the object. */
    };

    // Sendable
    /**
     * @class Sendable
     * @brief Represents a component that defines whether an object can be sent.
     */
    class Sendable {
        public:
            /**
             * @brief Constructs a Sendable object with the specified sendable value.
             * @param _sendable A boolean value indicating whether the object can be sent.
             */
            Sendable() {};
    };

    // Parralax
    /**
     * @class Parralax
     * @brief Represents a component that defines the parralax of an object.
     */
    class Parralax {
        public:
            /**
             * @brief Constructs a Parralax object with the specified start position and reset position.
             * @param _start_pos_x The starting x-coordinate of the object.
             * @param _start_pos_y The starting y-coordinate of the object.
             * @param _reset_pos The reset position of the object.
             */
            Parralax(float _start_pos_x, float _start_pos_y, float _reset_pos = 0) {reset_pos = _reset_pos; start_pos_x = _start_pos_x; start_pos_y = _start_pos_y;};
            float reset_pos; /**< The reset position of the object. */
            float start_pos_x; /**< The starting x-coordinate of the object. */
            float start_pos_y; /**< The starting y-coordinate of the object. */
    };

    // Send
    /**
     * @class Send
     * @brief Represents a component that defines whether an object has been sent.
     */
    class Send {
        public:
            /**
             * @brief Constructs a Send object with the specified send value.
             * @param _send A boolean value indicating whether the object has been sent.
             */
            Send() {};
            bool sended = false; /**< A boolean value indicating whether the object has been sent. */
    };

    //Text
    /**
     * @class Text
     * @brief Represents a component that defines the text of an object.
     */
    class Text {
        public:
            /**
             * @brief Constructs a Text object with the specified font path, text and size.
             * @param _path The path to the font.
             * @param _text The text to display.
             * @param _size The size of the text.
             */
            Text(std::string _path, std::string _text, float _size) {
                font = texturesLoader.get_font(_path);
                text.setFont(*font.get());
                text.setString(_text);
                text.setCharacterSize(_size);
                
                // Set the origin of the text to the middle
                sf::FloatRect textBounds = text.getLocalBounds();
                text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
            };
            std::shared_ptr<sf::Font> font; /**< The font of the text. */
            sf::Text text; /**< The sf::Text object representing the text. */
    };

    // SpawnPrefabAtRandomPosition
    /**
     * @class SpawnPrefabAtRandomPosition
     * @brief Represents a component that spawns a prefab at a random position.
     */
    class SpawnPrefabAtRandomPosition {
        public:
            /**
             * @brief Constructs a SpawnPrefabAtRandomPosition object with the specified prefab name, delay and position.
             * @param _prefab_name The name of the prefab to spawn.
             * @param _delay The delay before spawning.
             * @param _x_min The minimum x-coordinate of the position.
             * @param _x_max The maximum x-coordinate of the position.
             * @param _y_min The minimum y-coordinate of the position.
             * @param _y_max The maximum y-coordinate of the position.
             */
            SpawnPrefabAtRandomPosition(std::string _prefab_name, float _delay, int _x_min, int _x_max, int _y_min, int _y_max) {
                prefab_name = _prefab_name;
                timer = _delay;
                delay = _delay;
                x_min = _x_min;
                x_max = _x_max;
                y_min = _y_min;
                y_max = _y_max;
            };
            std::string prefab_name; /**< The name of the prefab to spawn. */
            float timer; /**< The timer of the prefab. */
            float delay; /**< The delay of the prefab. */
            int x_min; /**< The minimum x-coordinate of the position. */
            int x_max; /**< The maximum x-coordinate of the position. */
            int y_min; /**< The minimum y-coordinate of the position. */
            int y_max; /**< The maximum y-coordinate of the position. */
    };

    // OnCollideLoadScene
    /**
     * @class OnCollideLoadScene
     * @brief Represents a component that loads a scene when colliding with an object.
     */
    class OnCollideLoadScene {
        public:
            /**
             * @brief Constructs an OnCollideLoadScene object with the specified scene name and tag.
             * @param _scene_name The name of the scene to load.
             * @param _tag The tag of the object to collide with.
             */
            OnCollideLoadScene(std::string _scene_name, std::string _tag) {
                scene_name = _scene_name;
                tag = _tag;
            };
            std::string scene_name; /**< The name of the scene to load. */
            std::string tag; /**< The tag of the object to collide with. */
    };

    class PlaySound {
        public:
            PlaySound(std::string _music_path, bool _loop, float _volume = 100.0) {
                music_path = _music_path;
                loop = _loop;
                volume = _volume;

                music = std::make_shared<sf::Music>();

                if (!music->openFromFile(music_path)) {
                    std::cout << "Error loading music" << std::endl;
                } else {
                    music->setLoop(loop);
                    music->setVolume(volume);
                }

            };
            std::string music_path;
            std::shared_ptr<sf::Music> music;
            bool played = false;
            bool loop;
            bool volume;
    };

#endif //COMPONENTS_HPP