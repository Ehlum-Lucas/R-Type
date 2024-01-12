/*
** EPITECH PROJECT, 2024
** runner.cpp
** File description:
** runner
*/

#include "GameEngine.hpp"

int main()
{
    GameEngine ecs;

    ecs.setWindow("Runner", 60, true);

    ecs.create_scene("menu");

    ecs.create_texture("assets/character/Player.png");
    ecs.create_texture("assets/city-day/city-parralax-6.png");


    Entity button = ecs.scene("menu")->create_entity();

    ecs.scene("menu")->registry->add_component(button, Position(800, 500));
    ecs.scene("menu")->registry->add_component(button, Size(10, 5));
    ecs.scene("menu")->registry->add_component(button, Drawable());
    ecs.scene("menu")->registry->add_component(button, Sprite("assets/character/Player.png"));
    ecs.scene("menu")->registry->add_component(button, OnClickLoadScene("level1"));

    ecs.create_scene("level1");

    Entity ground = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(ground, Position(1920, 540));
    ecs.scene("level1")->registry->add_component(ground, Size(1, 1));
    ecs.scene("level1")->registry->add_component(ground, Drawable());
    ecs.scene("level1")->registry->add_component(ground, Sprite("assets/city-day/city-parralax-6.png"));

    Entity player = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(player, Position(100, 50));
    ecs.scene("level1")->registry->add_component(player, Size(2, 2));
    ecs.scene("level1")->registry->add_component(player, Drawable());
    ecs.scene("level1")->registry->add_component(player, Sprite("assets/character/Player.png"));
    ecs.scene("level1")->registry->add_component(player, BoxCollider("player", true, COLOR_RED));
    ecs.scene("level1")->registry->add_component(player, Gravity(2));

    ecs.load_scene("menu");
    ecs.update();

    return 0;
}