/*
** EPITECH PROJECT, 2023
** server.cpp
** File description:
** server
*/

#include "GameEngine.hpp"

int main()
{
    GameEngine ecs;

    // ecs.useInterface();

    ecs.setWindow("MyGame", 60, true);

    ecs.create_scene("game");

    // ecs.create_prefab("player");
    // ecs.add_component_to_prefab("player", Position(200, 500));
    // ecs.add_component_to_prefab("player", Velocity(0.0, 0.0));
    // ecs.add_component_to_prefab("player", Controller(true, true, true, true, "up", "down", "left", "right"));
    // ecs.add_component_to_prefab("player", Speed(10.0));
    // ecs.add_component_to_prefab("player", Drawable());
    // ecs.add_component_to_prefab("player", Size(0.2, 0.2));
    // ecs.add_component_to_prefab("player", Sprite("assets/player.png", 90.0));
    // ecs.add_component_to_prefab("player", BoxCollider("player"));

    Entity player = ecs.scene("game")->create_entity();
    ecs.scene("game")->registry->add_component(player, Position(150, 750));
    ecs.scene("game")->registry->add_component(player, Velocity(0.0, 0.0));
    ecs.scene("game")->registry->add_component(player, Drawable());
    ecs.scene("game")->registry->add_component(player, Controller(false, false, true, true, "up", "down", "left", "right"));
    ecs.scene("game")->registry->add_component(player, Speed(10.0));
    ecs.scene("game")->registry->add_component(player, Size(1, 1));
    ecs.scene("game")->registry->add_component(player, AnimatedSprite("assets/scottpilgrim.png", 0.0, 108, 140, 0, 7, 2));
    ecs.scene("game")->registry->add_component(player, Gravity(9.81));
    ecs.scene("game")->registry->add_component(player, BoxCollider("player", true));
    ecs.scene("game")->registry->add_component(player, OnCollide("ground", "destroy"));

    Entity ground = ecs.scene("game")->create_entity();
    ecs.scene("game")->registry->add_component(ground, Position(0, 1000));
    ecs.scene("game")->registry->add_component(ground, Drawable());
    ecs.scene("game")->registry->add_component(ground, Size(1, 1));
    ecs.scene("game")->registry->add_component(ground, RectangleShape(1920 * 2, 150));
    ecs.scene("game")->registry->add_component(ground, BoxCollider("ground", true));
    ecs.scene("game")->registry->add_component(ground, Color(35, 155, 65));
    ecs.scene("game")->registry->add_component(ground, OnCollide("player", "destroy"));

    ecs.load_scene("game");
    ecs.update();
    return 0;
}
