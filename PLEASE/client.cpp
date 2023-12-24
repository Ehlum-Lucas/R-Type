/*
** EPITECH PROJECT, 2023
** server.cpp
** File description:
** server
*/

/**
 * @file client.cpp
 * @brief This file contains the main function that initializes a game engine, creates entities and components,
 * sets up a player entity, joins an online game, loads a scene, and updates the game engine.
 *
 * @details The main function initializes a `GameEngine` object, sets up the game window, creates a scene,
 * creates entities and adds components to them, joins an online game, loads a scene, and updates the game engine.
 * The game engine is responsible for managing the game loop and updating the entities and components.
 *
 * @return The main function returns 0 to indicate successful execution.
 */

#include "GameEngine.hpp"

/**
 * This C++ code initializes a game engine, creates entities and components, sets up a player entity,
 * joins an online game, loads a scene, and updates the game engine.
 * 
 * @return The main function is returning 0.
 */

int main(void)
{
    GameEngine ecs;

    ecs.setWindow("MyGame", 60, true);
    
    ecs.create_scene("game");

    ecs.create_prefab("bullet");
    ecs.add_component_to_prefab("bullet", Position(0, 0));
    ecs.add_component_to_prefab("bullet", Velocity(50.0, 0.0));
    ecs.add_component_to_prefab("bullet", Drawable());
    ecs.add_component_to_prefab("bullet", Size(0.2, 0.2));
    ecs.add_component_to_prefab("bullet", Sprite("assets/bullet.png", 90.0));
    ecs.add_component_to_prefab("bullet", BoxCollider("bullet"));

    Entity player = ecs.scene("game")->create_entity();
    ecs.scene("game")->registry->add_component(player, Position(150, 500));
    ecs.scene("game")->registry->add_component(player, Velocity(0.0, 0.0));
    ecs.scene("game")->registry->add_component(player, Drawable());
    ecs.scene("game")->registry->add_component(player, Controller(true, true, true, true, "up", "down", "left", "right"));
    ecs.scene("game")->registry->add_component(player, Speed(10.0));
    ecs.scene("game")->registry->add_component(player, Size(0.2, 0.2));
    ecs.scene("game")->registry->add_component(player, Sprite("assets/player.png", 90.0));
    ecs.scene("game")->registry->add_component(player, SpawnWithInput("bullet", "space", 20.0, true));
    ecs.scene("game")->registry->add_component(player, BoxCollider("player"));

    ecs.joinOnlineGame("10.19.254.72", "4080");
    ecs.load_scene("game");
    ecs.update();
    return 0;
}

// int main(void)
// {
//     GameEngine ecs("MyGame", "NORMAL", 60, true);

//     ecs.create_scene("game");
//     ecs.create_scene("menu");

//     Entity button = ecs.scene("menu")->create_entity();
//     ecs.scene("menu")->registry->add_component(button, Position(950, 480));
//     ecs.scene("menu")->registry->add_component(button, Drawable());
//     ecs.scene("menu")->registry->add_component(button, Size(1, 1));
//     ecs.scene("menu")->registry->add_component(button, Sprite("assets/play.gif"));
//     ecs.scene("menu")->registry->add_component(button, OnClickLoadScene("game"));

//     Entity player = ecs.scene("game")->create_entity();
//     ecs.scene("game")->registry->add_component(player, Position(150, 500));
//     ecs.scene("game")->registry->add_component(player, Velocity(0.0, 0.0));
//     ecs.scene("game")->registry->add_component(player, Drawable());
//     ecs.scene("game")->registry->add_component(player, Controller(true, true, true, true, "up", "down", "left", "right"));
//     ecs.scene("game")->registry->add_component(player, Speed(10.0));
//     ecs.scene("game")->registry->add_component(player, Size(0.2, 0.2));
//     ecs.scene("game")->registry->add_component(player, Sprite("assets/player.png", 90.0));
//     ecs.scene("game")->registry->add_component(player, Shoot(0.0, 50.0, "space", "assets/bullet.png", 0.05, 0.05, 20.0));
//     ecs.scene("game")->registry->add_component(player, BoxCollider("player"));

//     for (int i = 0; i < 100; ++i) {
//         Entity enemy = ecs.scene("game")->create_entity();
//         int posX = rand() % 15000 + 2000; // Random x position between 2000 and 4000
//         int posY = rand() % 951 + 50; // Random y position between 50 and 1000
//         ecs.scene("game")->registry->add_component(enemy, Position(posX, posY));
//         ecs.scene("game")->registry->add_component(enemy, Velocity(-6.0, 0.0));
//         ecs.scene("game")->registry->add_component(enemy, Drawable());
//         ecs.scene("game")->registry->add_component(enemy, Size(0.2, 0.2));
//         ecs.scene("game")->registry->add_component(enemy, Sprite("assets/enemy.png", 90.0));
//         ecs.scene("game")->registry->add_component(enemy, BoxCollider("enemy"));
//         ecs.scene("game")->registry->add_component(enemy, Shootable());
//     }

//     ecs.load_scene("menu");
//     ecs.update();
//     return 0;
// }
