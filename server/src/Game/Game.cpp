/*
** EPITECH PROJECT, 2023
** Game.cpp
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::setup()
{

    _levels.push_back("LEVEL1");
    _levels.push_back("LEVEL2");
    _levels.push_back("LEVEL3");

    _registry.register_component<Position>();
    _registry.register_component<Velocity>();
    _registry.register_component<Drawable>();
    _registry.register_component<Controllable>();
    _registry.register_component<Type>();
    _registry.register_component<Id>();
    _registry.register_component<Size>();
    _registry.register_component<Shoot>();
}

size_t Game::create_player(int client_type)
{
    Entity player = _registry.create_entity();
    _players.push_back(player);
    _registry.add_component(player, Position{100, 100});
    _registry.add_component(player, Velocity{0.0, 0.0});
    _registry.add_component(player, Drawable{true});
    _registry.add_component(player, Controllable{true});
    _registry.add_component(player, Type{"p" + std::to_string(client_type)});
    _clients_in_room.push_back("player " + std::to_string(client_type));
    _registry.add_component(player, Id{player.get_id()});
    _registry.add_component(player, Size{50, 100});
    _registry.add_component(player, Shoot{true, 30.0, 0.0, false, false});
    return player.get_id();
}

void Game::delete_player(int entity_id)
{
    _registry.delete_entity_by_id(entity_id);
}

void Game::update(std::vector<std::string> &_inputs_list)
{
    for (auto &input : _inputs_list) {
        control_system(_registry, input);
    }
    shoot_system(_registry);
    position_system(_registry);
    _inputs_list.clear();
}

void Game::reset()
{
    _registry.reset();
    _players.clear();
    _enemies.clear();
    _levels.clear();
    _clients_in_room.clear();
    _game_is_running = false;
}

void Game::run_level(std::string level)
{
    _game_is_running = true;

    // create enemies and boss for the good level
    int id = 1;
    float y = 45;
    float x = 300;
    std::random_device rd;
    std::mt19937 gen(rd());

    float min = 2000.0f;
    float max = 1000000.0f;

    std::uniform_real_distribution<float> distribution(min, max);

    for (int i = 0; i < 0; i++) {
        _enemies.push_back(_registry.create_entity());
    }

    for (auto& enemy : _enemies) {
        _registry.add_component(enemy, Position{distribution(gen), y});
        _registry.add_component(enemy, Velocity{-10, 0.0});
        _registry.add_component(enemy, Drawable{true});
        _registry.add_component(enemy, Controllable{false});
        _registry.add_component(enemy, Type{"e"});
        _registry.add_component(enemy, Id{enemy.get_id()});
        _registry.add_component(enemy, Size{50, 50});
        _registry.add_component(enemy, Shoot{false, 0.0, 0.0, false, false});
        y += 200;
        if (y > 1000)
            y = 45;
        x += 110;
        id++;
    }
}

std::vector<std::string> Game::get_serialized()
{
    if (_game_is_running == false) {
        std::string levels = "LEVELS:";
        for (auto &level : _levels) {
            levels += level + ";";
        }
        std::string clients = "CLIENTS:";
        for (auto &client : _clients_in_room) {
            clients += client + ";";
        }
        std::vector<std::string> serialized;
        serialized.push_back(levels);
        serialized.push_back(clients);
        return serialized;
    } else {
        return serialize_system(_registry);
    }
}