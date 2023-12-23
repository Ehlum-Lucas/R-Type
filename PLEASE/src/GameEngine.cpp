/*
** EPITECH PROJECT, 2023
** GameEngine.cpp
** File description:
** GameEngine
*/

#include "GameEngine.hpp"


void GameEngine::add_prefab_to_a_scene(Registry& r, Entity &e, std::string prefab_name)
{
    auto prefab_components = r.get_prefab(prefab_name);

    for (auto component : prefab_components) {
        if (component.type() == typeid(Sprite)) {
            auto &sprite = std::any_cast<Sprite&>(component);
            // r.add_component_from_prefab(e, sprite);
            r.add_component(e, Sprite(get_available_player_skin(), sprite.angle));
        } else if (component.type() == typeid(Position)) {
            auto &position = std::any_cast<Position&>(component);
            r.add_component_from_prefab(e, position);
        } else if (component.type() == typeid(Velocity)) {
            auto &veclocity = std::any_cast<Velocity&>(component);
            r.add_component_from_prefab(e, veclocity);
        } else if (component.type() == typeid(Size)) {
            auto &size = std::any_cast<Size&>(component);
            r.add_component_from_prefab(e, size);
        } else if (component.type() == typeid(Drawable)) {
            auto &drawable = std::any_cast<Drawable&>(component);
            r.add_component_from_prefab(e, drawable);
        } else if (component.type() == typeid(BoxCollider)) {
            auto &boxCollider = std::any_cast<BoxCollider&>(component);
            r.add_component_from_prefab(e, boxCollider);
        } else if (component.type() == typeid(OnClickLoadScene)) {
            auto &comp = std::any_cast<OnClickLoadScene&>(component);
            r.add_component_from_prefab(e, comp);
        } else if (component.type() == typeid(Speed)) {
            auto &comp = std::any_cast<Speed&>(component);
            r.add_component_from_prefab(e, comp);
        } else if (component.type() == typeid(Controller)) {
            auto &comp = std::any_cast<Controller&>(component);
            r.add_component_from_prefab(e, comp);
        } else if (component.type() == typeid(Gravity)) {
            auto &comp = std::any_cast<Gravity&>(component);
            r.add_component_from_prefab(e, comp);
        } else if (component.type() == typeid(Color)) {
            auto &comp = std::any_cast<Color&>(component);
            r.add_component_from_prefab(e, comp);
        } else if (component.type() == typeid(RectangleShape)) {
            auto &comp = std::any_cast<RectangleShape&>(component);
            r.add_component_from_prefab(e, comp);
        } else if (component.type() == typeid(CircleShape)) {
            auto &comp = std::any_cast<CircleShape&>(component);
            r.add_component_from_prefab(e, comp);
        } else if (component.type() == typeid(SpawnWithInput)) {
            auto &comp = std::any_cast<SpawnWithInput&>(component);
            r.add_component_from_prefab(e, comp);
        }
    }
}

void separateString(const std::string& input, std::string& beforeComma, std::string& afterComma) {
    size_t commaPos = input.find('.');
    beforeComma = "";
    afterComma = "";
    if (commaPos != std::string::npos) {
        beforeComma = input.substr(0, commaPos);
        afterComma = input.substr(commaPos + 1);
    } else {
        beforeComma = input;
        afterComma = "";
    }

    while (beforeComma.length() < 7) {
        beforeComma = "0" + beforeComma;
    }

    while (afterComma.length() < 7) {
        afterComma += "0";
    }

}

void GameEngine::serialize_game()
{
    auto &types = current_scene->registry->get_components<Type>();

    std::vector<std::string> serialized_elements;
    for (size_t i = 0; i < types.size(); i++) {
        auto &base_type = types[i];

        if (base_type) {
            std::string serialized_entity = "";
            std::string bc;
            std::string ac;
            serialized_entity += std::to_string(base_type.value().type);
            auto &types = current_scene->registry->get_components<Type>();
            auto &posistions = current_scene->registry->get_components<Position>();
            for (size_t j = 0; j < posistions.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && posistions[j]) {
                    serialized_entity += " 401 ";
                    if (posistions[j].value().x < 0.0) {
                        serialized_entity += "1 ";
                    } else {
                        serialized_entity += "0 ";
                    }
                    separateString(std::to_string(posistions[j].value().x), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                    if (posistions[j].value().y < 0.0) {
                        serialized_entity += " 1 ";
                    } else {
                        serialized_entity += " 0 ";
                    }
                    separateString(std::to_string(posistions[j].value().y), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            auto &velocities = current_scene->registry->get_components<Velocity>();
            for (size_t j = 0; j < velocities.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && velocities[j]) {
                    serialized_entity += " 402";
                    if (velocities[j].value().vx < 0.0) {
                        serialized_entity += " 1 ";
                    } else {
                        serialized_entity += " 0 ";
                    }
                    separateString(std::to_string(velocities[j].value().vx), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                    if (velocities[j].value().vy < 0.0) {
                        serialized_entity += " 1 ";
                    } else {
                        serialized_entity += " 0 ";
                    }
                    separateString(std::to_string(velocities[j].value().vy), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            auto &drawables = current_scene->registry->get_components<Drawable>();
            for (size_t j = 0; j < drawables.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && drawables[j]) {
                    serialized_entity += " 403 ";
                }
            }
            auto &cshapes = current_scene->registry->get_components<CircleShape>();
            for (size_t j = 0; j < cshapes.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && cshapes[j]) {
                    serialized_entity += " 404 ";
                    separateString(std::to_string(cshapes[j].value().radius), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            auto &rshapes = current_scene->registry->get_components<RectangleShape>();
            for (size_t j = 0; j < rshapes.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && rshapes[j]) {
                    serialized_entity += " 405 ";
                    separateString(std::to_string(rshapes[j].value().width), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                    separateString(std::to_string(rshapes[j].value().height), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            auto &colors = current_scene->registry->get_components<Color>();
            auto &gravities = current_scene->registry->get_components<Gravity>();
            for (size_t j = 0; j < gravities.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && gravities[j]) {
                    serialized_entity += " 406 ";
                    if (gravities[j].value().gravity_force < 0.0) {
                        serialized_entity += " 1 ";
                    } else {
                        serialized_entity += " 0 ";
                    }
                    separateString(std::to_string(gravities[j].value().gravity_force), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                    if (gravities[j].value().direction == "y") {
                        serialized_entity += " 0 ";
                    } else {
                        serialized_entity += " 1 ";
                    }
                }
            }
            auto &controllers = current_scene->registry->get_components<Controller>();
            auto &speeds = current_scene->registry->get_components<Speed>();
            for (size_t j = 0; j < speeds.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && speeds[j]) {
                    serialized_entity += " 407 ";
                    if (speeds[j].value().speed < 0.0) {
                        serialized_entity += " 1 ";
                    } else {
                        serialized_entity += " 0 ";
                    }
                    separateString(std::to_string(speeds[j].value().speed), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            auto &sprites = current_scene->registry->get_components<Sprite>();
            auto &sizes = current_scene->registry->get_components<Size>();
            for (size_t j = 0; j < sizes.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && sizes[j]) {
                    serialized_entity += " 408 ";
                    if (sizes[j].value().width < 0.0) {
                        serialized_entity += " 1 ";
                    } else {
                        serialized_entity += " 0 ";
                    }
                    separateString(std::to_string(sizes[j].value().width), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                    if (sizes[j].value().height < 0.0) {
                        serialized_entity += " 1 ";
                    } else {
                        serialized_entity += " 0 ";
                    }
                    separateString(std::to_string(sizes[j].value().height), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                    separateString(std::to_string(sprites[j].value().angle), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            auto &bcolliders = current_scene->registry->get_components<BoxCollider>();
            auto &onclickloadscenes = current_scene->registry->get_components<OnClickLoadScene>();
            auto &swis = current_scene->registry->get_components<SpawnWithInput>();
            auto &sendable = current_scene->registry->get_components<Sendable>();

            serialized_elements.push_back(serialized_entity);
        }
    }

    for (auto serialized_element : serialized_elements) {
        _to_send_messages.push_back(serialized_element);
    }
}

/*
    cshapes
    rshapes
    gravities
    controllers
    speeds
    sizes
    bcolliders
*/

void GameEngine::start_send_host()
{
    _timer->async_wait([this](std::error_code ec) {
        if (!ec) {
            serialize_game();
            // for (auto& client : _clients) {
            //     _socket->send_to(asio::buffer("OK BRO"), client.getEndpoint());
            // }
            for (auto& message : _to_send_messages) {
                _socket->send_to(asio::buffer(message), _remote_endpoint);
            }
            _to_send_messages.clear();
            _timer->expires_after(std::chrono::milliseconds(1000/60));
            start_send_host();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
    });
}

void GameEngine::start_receive_host()
{
    _socket->async_receive_from(asio::buffer(_recv_buffer), _remote_endpoint, [this](std::error_code ec, std::size_t bytes_transferred) {
        if (!ec) {
            std::string message(_recv_buffer.data(), bytes_transferred);

            // Check if th1e client is already in the list
            auto cl = std::find_if(_clients.begin(), _clients.end(), [this](const ServerClient& client) {
                return client.getEndpoint() == _remote_endpoint;
            });

            if (cl == _clients.end()) {
                _clients.push_back(ServerClient(_remote_endpoint));

                // // Print all client endpoints
                // std::cout << "Current client endpoints:\n";
                // for (const ServerClient& client : _clients) {
                //     std::cout << client.getEndpoint().address().to_string() << ":" << client.getEndpoint().port() << "\n";
                // }
            }
            for (auto it = _clients.begin(); it != _clients.end();) {
                if (it->getEndpoint() == _remote_endpoint) {
                    if (message == "111" && !it->created && !it->connected) {
                        Entity e = current_scene->registry->create_entity();
                        current_scene->registry->add_component(e, Id(e.get_id()));
                        it->setType(e_type);
                        current_scene->registry->add_component(e, Type(e_type++));
                        std::cout << "aie" << std::endl;
                        add_prefab_to_a_scene(*current_scene->registry.get(), e, _on_new_cient_prefab_name);
                        std::cout << "ouie" << std::endl;
                        it->created = true;
                        std::cout << "CLIENT created" << std::endl;
                    } else if (message == "133") {
                        it->connected = true;
                        std::cout << "CLIENT connected" << std::endl;
                    } else if (it->created && !it->connected) {
                        _to_send_messages.push_back("122" + it->string_type);
                    } 
                }
                ++it;
            }

            auto it = std::find_if(_clients.begin(), _clients.end(), [this](const ServerClient& client) {
                return client.getEndpoint() == _remote_endpoint;
            });
            if (it != _clients.end()) {
                it->lastMessageTime = std::chrono::steady_clock::now();
            }

            start_receive_host();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
    });
}

void GameEngine::start_send_join()
{
    _timer->async_wait([this](std::error_code ec) {
        if (!ec) {

            if (!_created && !_connected) {
                _to_send_messages.push_back("111");
            }
            for (auto& message : _to_send_messages) {
                _socket->send_to(asio::buffer(message), _server_endpoint);
            }
            _to_send_messages.clear();
            _timer->expires_after(std::chrono::milliseconds(1000/60));
            start_send_join();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
    });
}

void GameEngine::start_receive_join()
{
    _socket->async_receive_from(asio::buffer(_recv_buffer), _server_endpoint, [this](std::error_code ec, std::size_t bytes_transferred) {
        if (!ec) {
            std::string message(_recv_buffer.data(), bytes_transferred);
            std::cout << "Received_client: " << message << " from " << _server_endpoint.address().to_string() << ":" << _server_endpoint.port() << std::endl;

            if (message.substr(0, 3) == "122") {
                _to_send_messages.push_back("133");
                _created = true;
                _type = std::stoi(message.substr(3));
                std::cout << "I AM created" << std::endl;
            }
            // _lastMessageTime = std::chrono::steady_clock::now();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
        start_receive_join();
    });
}

void GameEngine::update()
{
    if (_online) {
        if (_host) {
            _io_context.run();
        } else {
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
                spawn_with_input_system(*current_scene->registry.get());
                position_system(*current_scene->registry.get());
                gravity_system(*current_scene->registry.get());
                collide_system(*current_scene->registry.get());
                draw_system(*current_scene->registry.get());
                _window->display();
            }
        }
    } else if (!_online) {
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
            spawn_with_input_system(*current_scene->registry.get());
            position_system(*current_scene->registry.get());
            gravity_system(*current_scene->registry.get());
            collide_system(*current_scene->registry.get());
            draw_system(*current_scene->registry.get());
            _window->display();
        }
    }
}
