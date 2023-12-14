/*
** EPITECH PROJECT, 2023
** GameEngine.cpp
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

GameEngine::GameEngine(std::string const &title, std::string const &mode, int framerate, bool fullscreen, int width, int height)
{
    if (fullscreen) {
        sf::VideoMode fullscreenMode = sf::VideoMode::getFullscreenModes()[0];
        _window = std::make_shared<sf::RenderWindow>(fullscreenMode, title, sf::Style::Fullscreen);
    } else {
        _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
    }
    _window->setFramerateLimit(framerate);
}

GameEngine::~GameEngine()
{
}

void GameEngine::update()
{
    while (_window->isOpen()) {
        _window->clear(sf::Color::Black);
        while (_window->pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _window->close();
            }
            quit_system(*current_scene->registry.get());
            controller_system(*current_scene->registry.get());
            std::string scene_name = onclickloadscene_system(*current_scene->registry.get());
            if (scene_name != "") {
                load_scene(scene_name);
                continue;
            }
        }
        shoot_system(*current_scene->registry.get());
        position_system(*current_scene->registry.get());
        gravity_system(*current_scene->registry.get());
        collide_system(*current_scene->registry.get());
        draw_system(*current_scene->registry.get());
        _window->display();

    }
}
