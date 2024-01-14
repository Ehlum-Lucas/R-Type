/*
** EPITECH PROJECT, 2023
** server.cpp
** File description:
** server
*/

/**
 * @file server.cpp
 * @brief This file contains the implementation of the `server` function.
 */

#include "GameEngine.hpp"

/**
 * @brief The main function of the program.
 *
 * This function initializes the game engine, creates textures, scenes, and prefabs,
 * and sets up the game entities. It also hosts an online game, loads the game scene,
 * and updates the game loop.
 *
 * @return 0 indicating successful execution of the program.
 */

int main()
{
    GameEngine ecs;
    std::string ip = "";

    // ecs.setWindow("MyGame", 60, true);
    ecs.create_texture("assets/player.png");
    ecs.create_texture("assets/player2.png");
    ecs.create_texture("assets/player3.png");
    ecs.create_texture("assets/player4.png");
    ecs.create_texture("assets/enemy.png");
    ecs.create_texture("assets/bullet.png");

    ecs.create_scene("game");

    ecs.create_prefab("player");
    ecs.add_component_to_prefab("player", Position(200, 500));
    ecs.add_component_to_prefab("player", Velocity(0.0, 0.0));
    ecs.add_component_to_prefab("player", Controller(true, true, true, true, "up", "down", "left", "right"));
    ecs.add_component_to_prefab("player", Speed(10));
    ecs.add_component_to_prefab("player", Drawable());
    ecs.add_component_to_prefab("player", Size(0.2, 0.2));
    ecs.add_component_to_prefab("player", Sprite("assets/player.png", 90.0));
    ecs.add_component_to_prefab("player", SpawnWithInput("bullet", "space", 20.0, true));
    ecs.create_prefab("bullet");
    ecs.add_component_to_prefab("bullet", Position(0, 0));
    ecs.add_component_to_prefab("bullet", Velocity(50.0, 0.0));
    ecs.add_component_to_prefab("bullet", Drawable());
    ecs.add_component_to_prefab("bullet", Size(0.1, 0.1));
    ecs.add_component_to_prefab("bullet", Sprite("assets/bullet.png", 0.0));

    ecs.on_new_player_load_prefab("player");
    std::vector<std::string> atlas = {"assets/player.png", "assets/player2.png", "assets/player3.png", "assets/player4.png"};
    ecs.set_player_atlas_texture(atlas);

    for (int i = 0; i < 100; ++i) {
        Entity enemy = ecs.scene("game")->create_entity();
        int posX = rand() % 15000 + 2000;
        int posY = rand() % 951 + 50;
        ecs.scene("game")->registry->add_component(enemy, Type(ecs.e_type++));
        ecs.scene("game")->registry->add_component(enemy, Position(posX, posY));
        ecs.scene("game")->registry->add_component(enemy, Velocity(-12.0, 0.0));
        ecs.scene("game")->registry->add_component(enemy, Drawable());
        ecs.scene("game")->registry->add_component(enemy, Size(0.2, 0.2));
        ecs.scene("game")->registry->add_component(enemy, Sprite("assets/enemy.png", 90.0));
    }

    ecs.hostOnlineGame("4080");
    ecs.load_scene("game");
    ecs.update();
    return 0;
}
