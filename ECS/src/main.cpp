/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main
*/

#include "GameEngine.hpp"

int main()
{
    GameEngine ecs("ECS", "NORMAL", 60, true);


    Entity e = ecs.registry->create_entity();
    ecs.registry->add_component(e, Position(900, 500));
    ecs.registry->add_component(e, Velocity(0.0, 0.0));
    ecs.registry->add_component(e, Drawable());
    ecs.registry->add_component(e, Controller(true, true, true, true, "z", "s", "q", "d"));
    ecs.registry->add_component(e, Speed(5.0));
    ecs.registry->add_component(e, Size(0.2, 0.2));
    ecs.registry->add_component(e, Sprite("assets/player.png", 90.0));
    ecs.registry->add_component(e, Shoot(0.0, 50.0, "space", "assets/bullet.png", 0.05, 0.05));

    ecs.update();
    return 0;
}