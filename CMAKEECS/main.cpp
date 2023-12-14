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

    ecs.create_scene("game");
    ecs.create_scene("menu");

    Entity button = ecs.scene("menu")->create_entity();
    ecs.scene("menu")->registry->add_component(button, Position(950, 480));
    ecs.scene("menu")->registry->add_component(button, Drawable());
    ecs.scene("menu")->registry->add_component(button, Size(1, 1));
    ecs.scene("menu")->registry->add_component(button, Sprite("assets/play.gif"));
    ecs.scene("menu")->registry->add_component(button, OnClickLoadScene("game"));

    Entity player = ecs.scene("game")->create_entity();
    ecs.scene("game")->registry->add_component(player, Position(150, 500));
    ecs.scene("game")->registry->add_component(player, Velocity(0.0, 0.0));
    ecs.scene("game")->registry->add_component(player, Drawable());
    ecs.scene("game")->registry->add_component(player, Controller(true, true, true, true, "up", "down", "left", "right"));
    ecs.scene("game")->registry->add_component(player, Speed(10.0));
    ecs.scene("game")->registry->add_component(player, Size(0.2, 0.2));
    ecs.scene("game")->registry->add_component(player, Sprite("assets/player.png", 90.0));
    ecs.scene("game")->registry->add_component(player, Shoot(0.0, 50.0, "space", "assets/bullet.png", 0.05, 0.05, 20.0));
    ecs.scene("game")->registry->add_component(player, BoxCollider("player"));

    for (int i = 0; i < 100; ++i) {
        Entity enemy = ecs.scene("game")->create_entity();
        int posX = rand() % 15000 + 2000; // Random x position between 2000 and 4000
        int posY = rand() % 951 + 50; // Random y position between 50 and 1000
        ecs.scene("game")->registry->add_component(enemy, Position(posX, posY));
        ecs.scene("game")->registry->add_component(enemy, Velocity(-6.0, 0.0));
        ecs.scene("game")->registry->add_component(enemy, Drawable());
        ecs.scene("game")->registry->add_component(enemy, Size(0.2, 0.2));
        ecs.scene("game")->registry->add_component(enemy, Sprite("assets/enemy.png", 90.0));
        ecs.scene("game")->registry->add_component(enemy, BoxCollider("enemy"));
        ecs.scene("game")->registry->add_component(enemy, Shootable());
    }
    ecs.load_scene("menu");
    ecs.update();
    return 0;
    }
