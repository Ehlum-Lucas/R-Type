/*
** EPITECH PROJECT, 2023
** GameEngine.cpp
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

// void receiveMessageThread(std::shared_ptr<Client> client) {
//     while (1) {
//         client->_message = client->receiveMessage();
//         std::cout << client->_message << std::endl;
//     }
// }

GameEngine::~GameEngine()
{
}

GameEngine::GameEngine(std::string const &title, int const& mode, int framerate, bool fullscreen, int width, int height)
{
    _mode = mode;
    if (_mode == ONLINE) {
        // _server = std::make_shared<Server>(_io_context, 4080);
    } else if (_mode == OFFLINE) {
        if (fullscreen) {
            sf::VideoMode fullscreenMode = sf::VideoMode::getFullscreenModes()[0];
            _window = std::make_shared<sf::RenderWindow>(fullscreenMode, title, sf::Style::Fullscreen);
        } else {
            _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
        }
        _window->setFramerateLimit(framerate);
    }
}

void GameEngine::update()
{
    if (_mode == ONLINE) {
        // while (true) {
        //     std::vector<std::string> serializes = serialize_components(*current_scene->registry.get());
        //     std::string msg = "";

        //     for (auto& serialize : serializes) {
        //         msg += serialize;
        //     }

        //     _server->message = msg;
        //     _io_context.run();
        // }
    } else if (_mode == OFFLINE) {
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
            // shoot_system(*current_scene->registry.get());
            spawn_with_input_system(*current_scene->registry.get());
            position_system(*current_scene->registry.get());
            gravity_system(*current_scene->registry.get());
            collide_system(*current_scene->registry.get());
            draw_system(*current_scene->registry.get());
            _window->display();

        }
    }
}
