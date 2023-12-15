/*
** EPITECH PROJECT, 2023
** GameEngine.cpp
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

void receiveMessageThread(std::shared_ptr<Client> client) {
    while (1) {
        client->_message = client->receiveMessage();
        std::cout << client->_message << std::endl;
    }
}

GameEngine::GameEngine(std::string const &title, std::string const &mode, int framerate, bool fullscreen, int width, int height)
{
    _mode = mode;
    if (_mode == "SERVER") {
        _server = std::make_shared<Server>(_io_context, 4080);
    } else if (_mode == "CLIENT") {
        _client = std::make_shared<Client>("10.0.8.15", "4080");
        _client->_thread = std::thread(receiveMessageThread, _client);
        _client->connectToServer();
        if (fullscreen) {
            sf::VideoMode fullscreenMode = sf::VideoMode::getFullscreenModes()[0];
            _window = std::make_shared<sf::RenderWindow>(fullscreenMode, title, sf::Style::Fullscreen);
        } else {
            _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
        }
        _window->setFramerateLimit(framerate);
    } else if (_mode == "NORMAL") {
        if (fullscreen) {
            sf::VideoMode fullscreenMode = sf::VideoMode::getFullscreenModes()[0];
            _window = std::make_shared<sf::RenderWindow>(fullscreenMode, title, sf::Style::Fullscreen);
        } else {
            _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
        }
        _window->setFramerateLimit(framerate);
    }
}

GameEngine::~GameEngine()
{
}

void GameEngine::unserialize(std::string &serialized)
{
    std::string cid, texture_path, x, y, width, height;
    std::istringstream iss(serialized);
    std::string msg;

    while (std::getline(iss, msg, ';')) {
        std::istringstream iss2(msg);
        std::getline(iss2, cid, ':');
        std::getline(iss2, texture_path, ':');
        std::getline(iss2, x, ':');
        std::getline(iss2, y, ':');
        std::getline(iss2, width, ':');
        std::getline(iss2, height, ':');

        auto &clientIds = current_scene->registry->get_components<ClientId>();

        bool client_exists = false;

        for (size_t i = 0; i < clientIds.size(); i++) {
            auto &clientId = clientIds[i];
            std::stringstream sstream(cid);
            size_t result;
            sstream >> result;
            if (&clientId && clientId.value().id == result) {
                client_exists = true;
            }
        }

        if (!client_exists) {
            Entity entity = current_scene->registry->create_entity();
            current_scene->registry->add_component(entity, Position(std::stoi(x), std::stoi(y)));
            current_scene->registry->add_component(entity, Drawable());
            current_scene->registry->add_component(entity, Size(std::stod(width), std::stod(height)));
            current_scene->registry->add_component(entity, Sprite(texture_path));
            current_scene->registry->add_component(entity, Id(entity.get_id()));
            current_scene->registry->add_component(entity, ClientId(std::stoi(cid)));
        } else {
            auto &positions = current_scene->registry->get_components<Position>();
            auto &sprites = current_scene->registry->get_components<Sprite>();
            auto &sizes = current_scene->registry->get_components<Size>();
            auto &ids = current_scene->registry->get_components<Id>();

            for (size_t i = 0; i < positions.size() && i < sprites.size() && i < sizes.size(); i++) {
                auto &pos = positions[i];
                // auto &sprite = sprites[i];
                auto &size = sizes[i];
                auto &id = ids[i];

                if (id && size && pos && id.value().id == std::stoi(cid)) {
                    pos.value().x = std::stoi(x);
                    pos.value().y = std::stoi(y);
                    size.value().width = std::stod(width);
                    size.value().height = std::stod(height);
                    // sprite.value().texture_path = texture_path;
                }
            }
        }
    }
}

void GameEngine::update()
{
    if (_mode == "SERVER") {
        while (true) {
            std::vector<std::string> serializes = serialize_components(*current_scene->registry.get());
            std::string msg = "";

            for (auto& serialize : serializes) {
                msg += serialize;
            }

            _server->message = msg;
            _io_context.run();
        }
    } else if (_mode == "CLIENT") {
        while (_window->isOpen()) {
            while (_window->pollEvent(_event)) {
                if (_event.type == sf::Event::Closed) {
                    _window->close();
                }
            }
            std::string message = _client->getMessage();
            if (!message.empty() && _client->_message.substr(0, 8) != "YOU ARE ") {
                std::cout << "RECEIVED: " << message << std::endl;
                unserialize(message);
            }
            if (!_client->_server_know)
                _client->sendMessage("OK");
            _window->clear(sf::Color::Black);
            position_system(*current_scene->registry.get());
            draw_system(*current_scene->registry.get());
            _window->display();
        }
    } else if (_mode == "NORMAL") {
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
}
