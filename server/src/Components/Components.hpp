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
};

struct Type {
    std::string type;
};

struct Id {
    int id;
};
