/*
** EPITECH PROJECT, 2023
** GameEngine.cpp
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

GameEngine::GameEngine(std::string const &title, std::string const &mode, int framerate, bool fullscreen, int width, int height)
{
    registry = std::make_shared<Registry>(title, mode, framerate, fullscreen, width, height);

    registry->register_component<Position>();
    registry->register_component<Velocity>();
    registry->register_component<CircleShape>();
    registry->register_component<RectangleShape>();
    registry->register_component<Drawable>();
    registry->register_component<Color>();
    registry->register_component<Gravity>();
    registry->register_component<Controller>();
    registry->register_component<Speed>();
    registry->register_component<Gravity>();
    registry->register_component<Sprite>();
    registry->register_component<Size>();
    registry->register_component<Shoot>();
}

GameEngine::~GameEngine()
{
}

void GameEngine::update()
{
    while (registry->_window->isOpen()) {
        while (registry->_window->pollEvent(registry->_event)) {
            quit_system(*registry.get());
            controller_system(*registry.get());
            shoot_system(*registry.get());
        }
        position_system(*registry.get());
        gravity_system(*registry.get());
        draw_system(*registry.get());
    }
}
