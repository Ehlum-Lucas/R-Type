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


    Entity player = ecs.create_entity();
    ecs.registry->add_component(player, Position(150, 500));
    ecs.registry->add_component(player, Velocity(0.0, 0.0));
    ecs.registry->add_component(player, Drawable());
    ecs.registry->add_component(player, Controller(true, true, true, true, "up", "down", "left", "right"));
    ecs.registry->add_component(player, Speed(10.0));
    ecs.registry->add_component(player, Size(0.2, 0.2));
    ecs.registry->add_component(player, Sprite("assets/player.png", 90.0));
    ecs.registry->add_component(player, Shoot(0.0, 50.0, "space", "assets/bullet.png", 0.05, 0.05, 20.0));

    for (int i = 0; i < 100; ++i) {
        Entity enemy = ecs.create_entity();
        int posX = rand() % 15000 + 2000; // Random x position between 2000 and 4000
        int posY = rand() % 951 + 50; // Random y position between 50 and 1000
        ecs.registry->add_component(enemy, Position(posX, posY));
        ecs.registry->add_component(enemy, Velocity(-6.0, 0.0));
        ecs.registry->add_component(enemy, Drawable());
        ecs.registry->add_component(enemy, Size(0.2, 0.2));
        ecs.registry->add_component(enemy, Sprite("assets/enemy.png", 90.0));
        ecs.registry->add_component(enemy, BoxCollider("enemy", false));
    }
    ecs.update();
    return 0;
    }
