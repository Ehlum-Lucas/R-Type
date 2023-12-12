/*
** EPITECH PROJECT, 2023
** Components.cpp
** File description:
** Components
*/

// position component
struct Position {
    float x;
    float y;
};

// velocity component
struct Velocity {
    float vx;
    float vy;
};

// drawable component
struct Drawable {
    bool drawable;
};

// controllable component
struct Controllable {
    bool controllable;   
    int shoot;
};

struct Type {
    std::string type;
};

struct Id {
    size_t id;
};

struct Size {
    float height;
    float width;
};

struct Shoot {
    bool shoot;
    float delay;
    float time;
    bool shooted;
    bool is_shooting;
};
