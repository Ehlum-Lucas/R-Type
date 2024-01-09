/*
** EPITECH PROJECT, 2023
** GameEngine.cpp
** File description:
** GameEngine
*/

#include "GameEngine.hpp"


#include <any>

void GameEngine::add_prefab_to_a_scene(Registry& r, Entity &e, std::string prefab_name)
{
    auto prefab_components = r.get_prefab(prefab_name);

    for (auto component : prefab_components) {
        if (component.type() == typeid(Sprite)) {
            auto &sprite = std::any_cast<Sprite&>(component);
            // r.add_component_from_prefab(e, sprite);
            std::string skin = get_available_player_skin();
            std::cout << "skin: [" << skin << "]" << std::endl;
            r.add_component(e, Sprite(skin, sprite.angle));
        } else if (component.type() == typeid(Position)) {
            auto &position = std::any_cast<Position&>(component);
            r.add_component_from_prefab(e, position);
        } else if (component.type() == typeid(Velocity)) {
            auto &velocity = std::any_cast<Velocity&>(component);
            r.add_component_from_prefab(e, velocity);
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

    // while (afterComma.length() > 1 && afterComma.back() == '0') {
    //     afterComma.pop_back();
    // }

    while (beforeComma.length() < 7) {
        beforeComma = "0" + beforeComma;
    }

    while (afterComma.length() < 7) {
        afterComma += "0";
    }

}

void set_size_string_to(std::string &str, std::size_t size) {
    while (str.length() < size) {
        str = "0" + str;
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
            if (types.size() <= 0) {
                break;
            }
            float c = 1;

            bool send = true;
            bool cont = false;

            // Controller
            auto &controllers = current_scene->registry->get_components<Controller>();
            for (size_t j = 0; j < controllers.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && controllers[j]) {
                    if (_controllable_sended && _host) {
                        send = false;
                        break;
                    }
                    cont = true;
                    serialized_entity += "410";
                    if (controllers[j].value().can_go_up) {
                        serialized_entity += "1";
                    } else {
                        serialized_entity += "0";
                    }
                    if (controllers[j].value().can_go_down) {
                        serialized_entity += "1";
                    } else {
                        serialized_entity += "0";
                    }
                    if (controllers[j].value().can_go_left) {
                        serialized_entity += "1";
                    } else {
                        serialized_entity += "0";
                    }
                    if (controllers[j].value().can_go_right) {
                        serialized_entity += "1";
                    } else {
                        serialized_entity += "0";
                    }
                    serialized_entity +=  _inputGestion.sf_key_to_binary(controllers[j].value().up);
                    serialized_entity +=  _inputGestion.sf_key_to_binary(controllers[j].value().down);
                    serialized_entity +=  _inputGestion.sf_key_to_binary(controllers[j].value().left);
                    serialized_entity +=  _inputGestion.sf_key_to_binary(controllers[j].value().right);
                }
            }

            if (!send || (!_host && !cont)) {
                continue;
            }

            auto &posistions = current_scene->registry->get_components<Position>();
            for (size_t j = 0; j < posistions.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && posistions[j]) {
                    serialized_entity += "401";
                    if (posistions[j].value().x < 0.0) {
                        c = -1;
                        serialized_entity += "1";
                    } else {
                        serialized_entity += "0";
                    }
                    separateString(std::to_string(posistions[j].value().x * c), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                    if (posistions[j].value().y < 0.0) {
                        c = -1;
                        serialized_entity += "1";
                    } else {
                        serialized_entity += "0";
                    }
                    separateString(std::to_string(posistions[j].value().y * c), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            auto &velocities = current_scene->registry->get_components<Velocity>();
            for (size_t j = 0; j < velocities.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && velocities[j]) {
                    serialized_entity += "402";
                    if (velocities[j].value().vx < 0.0) {
                        c = -1;
                        serialized_entity += "1";
                    } else {
                        c = 1;
                        serialized_entity += "0";
                    }
                    separateString(std::to_string(velocities[j].value().vx * c), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                    if (velocities[j].value().vy < 0.0) {
                        c = -1;
                        serialized_entity += "1";
                    } else {
                        c = 1;
                        serialized_entity += "0";
                    }
                    separateString(std::to_string(velocities[j].value().vy * c), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            auto &drawables = current_scene->registry->get_components<Drawable>();
            for (size_t j = 0; j < drawables.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && drawables[j]) {
                    serialized_entity += "403";
                }
            }
            auto &cshapes = current_scene->registry->get_components<CircleShape>();
            for (size_t j = 0; j < cshapes.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && cshapes[j]) {
                    serialized_entity += "404";
                    separateString(std::to_string(cshapes[j].value().radius), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            auto &rshapes = current_scene->registry->get_components<RectangleShape>();
            for (size_t j = 0; j < rshapes.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && rshapes[j]) {
                    serialized_entity += "405";
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
                    serialized_entity += "406";
                    if (gravities[j].value().gravity_force < 0.0) {
                        c = -1;
                        serialized_entity += "1";
                    } else {
                        c = 1;
                        serialized_entity += "0";
                    }
                    separateString(std::to_string(gravities[j].value().gravity_force * c), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                    if (gravities[j].value().direction == "y") {
                        serialized_entity += "0";
                    } else {
                        serialized_entity += "1";
                    }
                }
            }
            auto &speeds = current_scene->registry->get_components<Speed>();
            for (size_t j = 0; j < speeds.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && speeds[j]) {
                    serialized_entity += "407";
                    if (speeds[j].value().speed < 0.0) {
                        c = -1;
                        serialized_entity += "1";
                    } else {
                        c = 1;
                        serialized_entity += "0";
                    }
                    separateString(std::to_string(speeds[j].value().speed * c), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            auto &sprites = current_scene->registry->get_components<Sprite>();
            for (size_t j = 0; j < sprites.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && sprites[j]) {
                    serialized_entity += "408";

                    std::string texture_id = std::to_string(get_texture_indice(sprites[j].value().texture_path));
                    set_size_string_to(texture_id, 5);
                    serialized_entity += texture_id;
                    if (sprites[j].value().angle < 0.0) {
                        c = -1;
                        serialized_entity += "1";
                    } else {
                        c = 1;
                        serialized_entity += "0";
                    }
                    separateString(std::to_string(sprites[j].value().angle * c), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                }
            }
            // SIZE
            auto &sizes = current_scene->registry->get_components<Size>();
            for (size_t j = 0; j < sizes.size() && j < types.size(); j++) {
                if (types[j] && types[j].value().type == base_type.value().type && sizes[j]) {
                    serialized_entity += "409";
                    if (sizes[j].value().width < 0.0) {
                        c = -1;
                        serialized_entity += "1";
                    } else {
                        c = 1;
                        serialized_entity += "0";
                    }
                    separateString(std::to_string(sizes[j].value().width * c), bc, ac);
                    serialized_entity += bc;
                    serialized_entity += ac;
                    if (sizes[j].value().height < 0.0) {
                        c = -1;
                        serialized_entity += "1";
                    } else {
                        c = 1;
                        serialized_entity += "0";
                    }
                    separateString(std::to_string(sizes[j].value().height * c), bc, ac);
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

void GameEngine::unserialize_game()
{
    for (auto& message : _received_messages) {
        std::string entity_type = message.substr(0, 8);

        // check if entity exist and modify it
        bool entity_exist = false;
        auto &types = current_scene->registry->get_components<Type>();
        for (size_t j = 0; j < types.size(); j++) {
            if (types[j] && types[j].value().type == std::stoi(entity_type)) {
                entity_exist = true;
                break;
            }
        }
        // else create it
        Entity e;
        if (!entity_exist) {
            e = current_scene->registry->create_entity();
            current_scene->registry->add_component(e, Id(e.get_id()));
            current_scene->registry->add_component(e, Type(std::stoi(entity_type)));
        }
        size_t pos = 8;


        // Controller
        if ((pos + 23) <= message.size() && message.substr(pos, 3) == "410") {
            if (_host) {
                _controllable_sended = true;
            } else {
                std::cout << "CLIENT RECEIVE A CONTROLLER" << std::endl;
            }
            pos += 3;
            std::string can_up = message.substr(pos, 1);
            pos++;
            std::string can_down = message.substr(pos, 1);
            pos++;
            std::string can_left = message.substr(pos, 1);
            pos++;
            std::string can_right = message.substr(pos, 1);
            pos++;
            std::string key_up = message.substr(pos, 4);
            pos += 4;
            std::string key_down = message.substr(pos, 4);
            pos += 4;
            std::string key_left = message.substr(pos, 4);
            pos += 4;
            std::string key_right = message.substr(pos, 4);
            pos += 4;
            bool up = false, down = false, left = false, right = false;
            if (can_up == "1") {
                up = true;
            } else {
                up = false;
            }
            if (can_down == "1") {
                down = true;
            } else {
                down = false;
            }
            if (can_left == "1") {
                left = true;
            } else {
                left = false;
            }
            if (can_right == "1") {
                right = true;
            } else {
                right = false;
            }
            bool exist = false;
            auto &controllers = current_scene->registry->get_components<Controller>();
            auto &types = current_scene->registry->get_components<Type>();
            for (size_t j = 0; j < controllers.size() && j < types.size(); j++) {
                if (controllers[j] && types[j] && types[j].value().type == std::stoi(entity_type)) {
                    controllers[j].value().can_go_up = up;
                    controllers[j].value().can_go_down = down;
                    controllers[j].value().can_go_left = left;
                    controllers[j].value().can_go_right = right;
                    controllers[j].value().up = _inputGestion.binary_to_sf_key(key_up);
                    controllers[j].value().down = _inputGestion.binary_to_sf_key(key_down);
                    controllers[j].value().left = _inputGestion.binary_to_sf_key(key_left);
                    controllers[j].value().right = _inputGestion.binary_to_sf_key(key_right);
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                current_scene->registry->add_component(e, Controller(up, down, left, right, _inputGestion.binary_to_sf_key(key_up), _inputGestion.binary_to_sf_key(key_down), _inputGestion.binary_to_sf_key(key_left), _inputGestion.binary_to_sf_key(key_right)));
            }
        }


        // Position
        if ((pos + 33) <= message.size() && message.substr(pos, 3) == "401") {
            std::string x;
            pos += 3;
            if (message[pos] == '1') {
                x += "-";
            }
            pos++;
            x += message.substr(pos, 7);
            pos += 7;
            x += ".";
            x += message.substr(pos, 7);
            pos += 7;
            std::string y;
            if (message[pos] == '1') {
                y += "-";
            }
            pos++;
            y += message.substr(pos, 7);
            pos += 7;
            y += ".";
            y += message.substr(pos, 7);
            pos += 7;
            bool exist = false;
            auto &positions = current_scene->registry->get_components<Position>();
            auto &types = current_scene->registry->get_components<Type>();
            for (size_t j = 0; j < positions.size() && j < types.size(); j++) {
                if (positions[j] && types[j] && types[j].value().type == std::stoi(entity_type)) {
                    positions[j].value().x = std::stod(x);
                    positions[j].value().y = std::stod(y);
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                current_scene->registry->add_component(e, Position(std::stod(x), std::stod(y)));
            }
        }
        // Velocity
        if ((pos + 33) <= message.size() && message.substr(pos, 3) == "402") {
            std::string vx;
            pos += 3;
            if (message[pos] == '1') {
                vx += "-";
            }
            pos++;
            vx += message.substr(pos, 7);
            pos += 7;
            vx += ".";
            vx += message.substr(pos, 7);
            pos += 7;
            std::string vy;
            if (message[pos] == '1') {
                vy += "-";
            }
            pos++;
            vy += message.substr(pos, 7);
            pos += 7;
            vy += ".";
            vy += message.substr(pos, 7);
            pos += 7;
            bool exist = false;
            auto &velocities = current_scene->registry->get_components<Velocity>();
            auto &types = current_scene->registry->get_components<Type>();
            for (size_t j = 0; j < velocities.size() && j < types.size(); j++) {
                if (velocities[j] && types[j] && types[j].value().type == std::stoi(entity_type)) {
                    velocities[j].value().vx = std::stod(vx);
                    velocities[j].value().vy = std::stod(vy);
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                current_scene->registry->add_component(e, Velocity(std::stod(vx), std::stod(vy)));
            }
        }
        // Drawable
        if ((pos + 3) <= message.size() && message.substr(pos, 3) == "403") {
            pos += 3;
            bool exist = false;
            auto &drawables = current_scene->registry->get_components<Drawable>();
            auto &types = current_scene->registry->get_components<Type>();
            for (size_t j = 0; j < drawables.size() && j < types.size(); j++) {
                if (drawables[j] && types[j] && types[j].value().type == std::stoi(entity_type)) {
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                current_scene->registry->add_component(e, Drawable());
            }
        }

        // Speed
        if ((pos + 18) <= message.size() && message.substr(pos, 3) == "407") {
            std::string speed;
            pos += 3;
            if (message[pos] == '1') {
                speed += "-";
            }
            pos++;
            speed += message.substr(pos, 7);
            pos += 7;
            speed += ".";
            speed += message.substr(pos, 7);
            pos += 7;
            bool exist = false;
            auto &speeds = current_scene->registry->get_components<Speed>();
            auto &types = current_scene->registry->get_components<Type>();
            for (size_t j = 0; j < speeds.size() && j < types.size(); j++) {
                if (speeds[j] && types[j] && types[j].value().type == std::stoi(entity_type)) {
                    speeds[j].value().speed = std::stod(speed);
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                current_scene->registry->add_component(e, Speed(std::stod(speed)));
            }
        }
        // Sprite
        if ((pos + 23) <= message.size() && message.substr(pos, 3) == "408") {
            if (!_host) {
                std::cout << "CLIENT RECEIVE A SPRITE" << std::endl;
            }
            pos += 3;
            std::string texture_id = message.substr(pos, 5);
            pos += 5;
            std::string angle = "";
            if (message[pos] == '1') {
                angle += "-";
            }
            pos++;
            angle += message.substr(pos, 7);
            pos += 7;
            angle += ".";
            angle += message.substr(pos, 7);
            pos += 7;
            bool exist = false;
            auto &sprites = current_scene->registry->get_components<Sprite>();
            auto &types = current_scene->registry->get_components<Type>();
            for (size_t j = 0; j < sprites.size() && j < types.size(); j++) {
                if (sprites[j] && types[j] && types[j].value().type == std::stoi(entity_type)) {
                    // sprites[j].value().texture_path = get_texture_path(std::stoi(texture_id));
                    sprites[j].value().angle = std::stod(angle);
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                std::cout << "I CREATE SPRITE" << std::endl;
                current_scene->registry->add_component(e, Sprite(get_texture_path(std::stoi(texture_id)), std::stod(angle)));
            }
        }
        // Size 
        if ((pos + 33) <= message.size() && message.substr(pos, 3) == "409") {
            std::string width;
            pos += 3;
            if (message[pos] == '1') {
                width += "-";
            }
            pos++;
            width += message.substr(pos, 7);
            pos += 7;
            width += ".";
            width += message.substr(pos, 7);
            pos += 7;
            std::string height;
            if (message[pos] == '1') {
                height += "-";
            }
            pos++;
            height += message.substr(pos, 7);
            pos += 7;
            height += ".";
            height += message.substr(pos, 7);
            pos += 7;
            bool exist = false;
            auto &sizes = current_scene->registry->get_components<Size>();
            auto &types = current_scene->registry->get_components<Type>();
            for (size_t j = 0; j < sizes.size() && j < types.size(); j++) {
                if (sizes[j] && types[j] && types[j].value().type == std::stoi(entity_type)) {
                    sizes[j].value().width = std::stod(width);
                    sizes[j].value().height = std::stod(height);
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                current_scene->registry->add_component(e, Size(std::stod(width), std::stod(height)));
            }
        }
        // Speed
        if ((pos + 18) <= message.size() && message.substr(pos, 3) == "407") {
            std::string speed;
            pos += 3;
            if (message[pos] == '1') {
                speed += "-";
            }
            pos++;
            speed += message.substr(pos, 7);
            pos += 7;
            speed += ".";
            speed += message.substr(pos, 7);
            pos += 7;
            bool exist = false;
            auto &speeds = current_scene->registry->get_components<Speed>();
            auto &types = current_scene->registry->get_components<Type>();
            for (size_t j = 0; j < speeds.size() && j < types.size(); j++) {
                if (speeds[j] && types[j] && types[j].value().type == std::stoi(entity_type)) {
                    speeds[j].value().speed = std::stod(speed);
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                current_scene->registry->add_component(e, Speed(std::stod(speed)));
            }
        }
    }
    if (_received_messages.size() > 0) {
       _received_messages.clear();
    }
}

void GameEngine::start_send_host()
{
    _timer->async_wait([this](std::error_code ec) {
        if (!ec) {
            if (_game_is_running) {
                position_system(*current_scene->registry.get());
                serialize_game();
            }
            for (auto& client : _clients) {
                for (auto& message : _to_send_messages) {
                    // std::cout << "Send to " << client.getEndpoint().address().to_string() << ":" << client.getEndpoint().port() << " : " << message << std::endl;
                    std::string e_type_ser = message.substr(0, 8);
                    auto e_check = std::find(client.entities_sended.begin(), client.entities_sended.end(), e_type_ser);

                    if (e_check == client.entities_sended.end()) {
                        _socket->send_to(asio::buffer(message), client.getEndpoint());
                        if (client.connected && client.created) {
                            client.entities_sended.push_back(e_type_ser);
                        }
                    }
                }
            
            }
            if (_to_send_messages.size() > 0) {
                _to_send_messages.clear();
            }
            _timer->expires_after(std::chrono::milliseconds(1000/30));
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

            // std::cout << "REICEIVED MESSAGE: " << message << std::endl;

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
                        add_prefab_to_a_scene(*current_scene->registry.get(), e, _on_new_cient_prefab_name);
                        it->created = true;
                    } else if (message == "133") {
                        it->connected = true;
                        _game_is_running = true;
                    } else if (message.size() > 10 && message[0] == '1' && is_a_component(message.substr(8, 3)) && it->created && it->connected) {
                        _received_messages.push_back(message);
                        unserialize_game();
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
                std::cout << "SEND 111" << std::endl;
            }
            for (auto& message : _to_send_messages) {
                _socket->send_to(asio::buffer(message), _server_endpoint);
            }
            _to_send_messages.clear();
            _timer->expires_after(std::chrono::milliseconds(1000/30));
            start_send_join();
        } else {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
    });
}

bool GameEngine::is_a_component(std::string const &str)
{
    if (str == "401" || str == "402" || str == "403" || str == "404" || str == "405" || str == "406" || str == "407" || str == "408" || str == "409" || str == "410") {
        return true;
    }
    return false;
}

void GameEngine::start_receive_join()
{
    _socket->async_receive_from(asio::buffer(_recv_buffer), _server_endpoint, [this](std::error_code ec, std::size_t bytes_transferred) {
        if (!ec) {
            std::string message(_recv_buffer.data(), bytes_transferred);
            std::cout << "Received_client: " << message << " cfrom " << _server_endpoint.address().to_string() << ":" << _server_endpoint.port() << std::endl;

            if (message.substr(0, 3) == "122") {
                _to_send_messages.push_back("133");
                _created = true;
                _type = std::stoi(message.substr(3));
            } else if (message.size() > 10 && message[0] == '1' && is_a_component(message.substr(8, 3)) && _created) {
                _game_is_running = true;
                _received_messages.push_back(message);
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
                if (_game_is_running && _received_messages.size() > 0) {
                    std::cout << "GAME IS RUNNING" << std::endl;
                    unserialize_game();
                }
                _window->clear(sf::Color::Black);
                while (_window->pollEvent(_event)) {
                    if (_event.type == sf::Event::Closed) {
                        _window->close();
                    }
                    quit_system(*current_scene->registry.get());
                }
                controller_system(*current_scene->registry.get());
                position_system(*current_scene->registry.get());
                draw_system(*current_scene->registry.get());
                _window->display();
                if (_game_is_running) {
                    serialize_game();
                }
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
