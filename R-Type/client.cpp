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

int main(int ac, char **av)
{
    GameEngine ecs;
    std::string ip = "";

    if (ac == 2)
        ip = av[1];
    else
        ip = "10.19.254.250";
        
    ecs.create_texture("assets/player.png");
    ecs.create_texture("assets/player2.png");
    ecs.create_texture("assets/player3.png");
    ecs.create_texture("assets/player4.png");
    ecs.create_texture("assets/enemy.png");
    ecs.create_texture("assets/bullet.png");
    
    ecs.create_texture("assets/spaceBackground.png");
    ecs.setWindow("MyGame", 30, true);

    ecs.create_scene("game");

    Entity parralax = ecs.scene("game")->create_entity();
    ecs.scene("game")->registry->add_component(parralax, Position(1920, 540));
    ecs.scene("game")->registry->add_component(parralax, Drawable());
    ecs.scene("game")->registry->add_component(parralax, Size(1, 1));
    ecs.scene("game")->registry->add_component(parralax, Velocity(-1.0, 0.0));
    ecs.scene("game")->registry->add_component(parralax, Sprite("assets/spaceBackground.png", 0.0));
    ecs.scene("game")->registry->add_component(parralax, Parralax(1920, 540, -960));

    ecs.create_prefab("player");
    ecs.create_prefab("bullet");
    ecs.add_component_to_prefab("bullet", Position(0, 0));
    ecs.add_component_to_prefab("bullet", Velocity(50.0, 0.0));
    ecs.add_component_to_prefab("bullet", Drawable());
    ecs.add_component_to_prefab("bullet", Size(0.1, 0.1));
    ecs.add_component_to_prefab("bullet", Sprite("assets/bullet.png", 0.0));
  
    ecs.joinOnlineGame(ip, "4080");
    ecs.load_scene("game");
    ecs.update();
    return 0;
}
