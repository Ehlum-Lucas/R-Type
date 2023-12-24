/*
** EPITECH PROJECT, 2023
** server.cpp
** File description:
** server
*/

#include "GameEngine.hpp"

int main(int ac, char **av)
{
    GameEngine ecs;
    std::string ip = "";

    if (ac == 2)
        ip = av[1];
    else
        ip = "192.168.1.98";

    // ecs.setWindow("MyGame", 60, true);
    ecs.load_texture("assets/player.png");
    ecs.load_texture("assets/enemy.png");

    ecs.create_scene("game");

    ecs.create_prefab("player");
    ecs.add_component_to_prefab("player", Position(200, 500));
    ecs.add_component_to_prefab("player", Velocity(0.0, 0.0));
    ecs.add_component_to_prefab("player", Controller(true, true, true, true, "up", "down", "left", "right"));
    ecs.add_component_to_prefab("player", Speed(10.0));
    ecs.add_component_to_prefab("player", Drawable());
    ecs.add_component_to_prefab("player", Size(0.2, 0.2));
    ecs.add_component_to_prefab("player", Sprite("assets/player.png", 90.0));
    ecs.add_component_to_prefab("player", BoxCollider("player"));

    ecs.on_new_player_load_prefab("player");
    std::vector<std::string> atlas = {"assets/player.png", "assets/player.png", "assets/player.png", "assets/player.png"};
    ecs.set_player_atlas_texture(atlas);

     // ecs.scene("game")->registry->add_component(player, Position(150, 500));
    // ecs.scene("game")->registry->add_component(player, Velocity(0.0, 0.0));
    // ecs.scene("game")->registry->add_component(player, Drawable());
    // ecs.scene("game")->registry->add_component(player, Controller(true, true, true, true, "up", "down", "left", "right"));
    // ecs.scene("game")->registry->add_component(player, Speed(10.0));
    // ecs.scene("game")->registry->add_component(player, Size(0.2, 0.2));
    // ecs.scene("game")->registry->add_component(player, Sprite("assets/player.png", 90.0));
    // ecs.scene("game")->registry->add_component(player, SpawnWithInput("bullet", "space", 20.0, true));
    // ecs.scene("game")->registry->add_component(player, BoxCollider("player"));

    for (int i = 0; i < 100; ++i) {
        Entity enemy = ecs.scene("game")->create_entity();
        int posX = rand() % 15000 + 2000; // Random x position between 2000 and 4000
        int posY = rand() % 951 + 50; // Random y position between 50 and 1000
        ecs.scene("game")->registry->add_component(enemy, Type(ecs.e_type++));
        ecs.scene("game")->registry->add_component(enemy, Position(posX, posY));
        ecs.scene("game")->registry->add_component(enemy, Velocity(-12.0, 0.0));
        ecs.scene("game")->registry->add_component(enemy, Drawable());
        ecs.scene("game")->registry->add_component(enemy, Size(0.2, 0.2));
        ecs.scene("game")->registry->add_component(enemy, Sprite("assets/enemy.png", 90.0));
        // ecs.scene("game")->registry->add_component(enemy, BoxCollider("enemy"));
        // ecs.scene("game")->registry->add_component(enemy, Shootable());
    }

    // 402 1 000012.000000 0 000000.000000 00040340800001000000900000000409000000002000000000000002000000
    // 10000100 401 0 0007916.0000000 0 0000587.0000000 402 1 0000120.00000000000000000000040340800001000000900000000409000000002000000000000002000000
    // 10000100 401 0 0007916.0000000 0 0000587.0000000 402 0 0000000.000000000000000000000040340800001000000900000000409000000002000000000000002000000
    // 10000100 401 0 0004532.0000000 0 0000587.0000000 402 1 0000012.0000000 0 0000000 0000000 40340800001000000900000000409000000002000000000000002000000
    // 10000001 401 0 0000200.0000000 0 0000500.0000000 402 0 0000000.0000000 0 0000000 0000000 403 407 0 0000020.0000000 4080000000000090000000040900000000200000000000000200000041011119001900290039004 cfrom 192.168.1.98:4080

    ecs.hostOnlineGame(ip, "4080");
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
