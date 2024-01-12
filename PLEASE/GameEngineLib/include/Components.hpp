/*
** EPITECH PROJECT, 2023
** Components.cpp
** File description:
** Components
*/

/**
 * @file Components.cpp
 * @brief This file contains the implementation of the `Components` class.
 */

#ifndef COMPONENTS_HPP
    #define COMPONENTS_HPP
    #include <SFML/Graphics.hpp>
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
            float radius;
    };

    // rectangle shape component
    class RectangleShape {
        public:
            RectangleShape(float width, float height) : shape(sf::Vector2f(width, height)) {};
            sf::RectangleShape shape;
            float width;
            float height;
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

    // addForce component
    class AddForce {
        public:
            AddForce(float _force, float _end_point, std::string _input, std::string _direction = "y") {
                force = _force;
                end_point = _end_point;
                direction = _direction;
                input = inputGestion.get_key(_input);
            };
            float force;
            float end_point;
            float start_x;
            float start_y;
            bool processing = false;
            bool key_was_pressed = false;
            std::string direction;
            sf::Keyboard::Key input;

        private:
            InputGestion inputGestion;
    };

    // controller component
    class Controller {
        public:
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
            Sprite(std::string texture_path, float _angle = 0.0) : texture_path(texture_path)
            {
                texture = texturesLoader.get_texture(texture_path);
                sprite.setTexture(*texture.get());
                angle = _angle;
                sprite.setRotation(angle);
                sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
            };
            std::shared_ptr<sf::Texture> texture;
            std::string texture_path;
            sf::Sprite sprite;
            float angle;
    };

    // size component
    class Size {
        public:
            Size(float width, float height) : width(width), height(height) {};
            float width;
            float height;
    };

    // spawn component
    class SpawnWithInput {
        public:
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
            std::string prefab_name;
            float angle;
            float timer;
            float delay;
            sf::Keyboard::Key input;
            bool at_parent_pos;
        private:
            InputGestion inputGestion;
            
    };

    // box collider component
    class BoxCollider {
        public:
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
            bool draw;
            std::string tag;
            sf::Color color;
            std::shared_ptr<sf::RectangleShape> collider;
            float width;
            float height;
            float origin_x;
            float origin_y;
            bool collide = true;
    };

    // ShowCollisionsWithInput
    class ShowCollisionsWithInput {
        public:
            ShowCollisionsWithInput(std::string _input) {input = inputGestion.get_key(_input);};

            sf::Keyboard::Key input;
            bool showed = true;
            bool released = true;
        private:
            InputGestion inputGestion;
    };

    class OnCollideStop {
        public:
            OnCollideStop(std::string _tag) {tag =_tag;};
            std::string tag;
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

    class Type {
        public:
            Type(size_t _type) {type = _type;};
            size_t type;
    };

    class Sendable {
        public:
            Sendable() {};
    };

    class Parralax {
        public:
            Parralax(float _start_pos_x, float _start_pos_y, float _reset_pos = 0) {reset_pos = reset_pos; start_pos_x = _start_pos_x; start_pos_y = _start_pos_y;};
            float reset_pos;
            float start_pos_x;
            float start_pos_y;
    };
      
    class Send {
        public:
            Send() {};
            bool sended = false;
    };

    class Text {
        public:
            Text(std::string _path, std::string _text, float _size) {
                font = texturesLoader.get_font(_path);
                text.setFont(*font.get());
                text.setString(_text);
                text.setCharacterSize(_size);
            };
            std::shared_ptr<sf::Font> font;
            sf::Text text;
    };

    // class ComponentFactory {
    //     public:
    //         void add_any_component_to_registry(Entity e, std::any component, Registry &r)
    //         {
    //             if (component.type() == typeid(Sprite)) {
    //                 auto &sprite = std::any_cast<Sprite&>(component);
    //                 r.add_component_from_prefab(e, sprite);
    //             } else if (component.type() == typeid(Position)) {
    //                 auto &position = std::any_cast<Position&>(component);
    //                 r.add_component_from_prefab(e, position);
    //             } else if (component.type() == typeid(Velocity)) {
    //                 auto &veclocity = std::any_cast<Velocity&>(component);
    //                 r.add_component_from_prefab(e, veclocity);
    //             } else if (component.type() == typeid(Size)) {
    //                 auto &size = std::any_cast<Size&>(component);
    //                 r.add_component_from_prefab(e, size);
    //             } else if (component.type() == typeid(Drawable)) {
    //                 auto &drawable = std::any_cast<Drawable&>(component);
    //                 r.add_component_from_prefab(e, drawable);
    //             } else if (component.type() == typeid(BoxCollider)) {
    //                 auto &boxCollider = std::any_cast<BoxCollider&>(component);
    //                 r.add_component_from_prefab(e, boxCollider);
    //             } else if (component.type() == typeid(OnClickLoadScene)) {
    //                 auto &comp = std::any_cast<OnClickLoadScene&>(component);
    //                 r.add_component_from_prefab(e, comp);
    //             } else if (component.type() == typeid(Speed)) {
    //                 auto &comp = std::any_cast<Speed&>(component);
    //                 r.add_component_from_prefab(e, comp);
    //             } else if (component.type() == typeid(Controller)) {
    //                 auto &comp = std::any_cast<Controller&>(component);
    //                 r.add_component_from_prefab(e, comp);
    //             } else if (component.type() == typeid(Gravity)) {
    //                 auto &comp = std::any_cast<Gravity&>(component);
    //                 r.add_component_from_prefab(e, comp);
    //             } else if (component.type() == typeid(Color)) {
    //                 auto &comp = std::any_cast<Color&>(component);
    //                 r.add_component_from_prefab(e, comp);
    //             } else if (component.type() == typeid(RectangleShape)) {
    //                 auto &comp = std::any_cast<RectangleShape&>(component);
    //                 r.add_component_from_prefab(e, comp);
    //             } else if (component.type() == typeid(CircleShape)) {
    //                 auto &comp = std::any_cast<CircleShape&>(component);
    //                 r.add_component_from_prefab(e, comp);
    //             }
    //         }
    // };

#endif //COMPONENTS_HPP