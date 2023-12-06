/*
** EPITECH PROJECT, 2023
** control_system.cpp
** File description:
** control_system
*/

#include "Systems.hpp"

void control_system(Registry &r, std::string &inputs)
{
    bool up = (inputs.find("u") != std::string::npos);
    bool down = (inputs.find("d") != std::string::npos);
    bool left = (inputs.find("l") != std::string::npos);
    bool right = (inputs.find("r") != std::string::npos);
    bool space = (inputs.find("s") != std::string::npos);
    bool enter = (inputs.find("e") != std::string::npos);

    std::string received_type = inputs.substr(0, 2);

    // if (received_type.empty()) {
    //     return;
    // }

    auto &positions = r.get_components<Position>();
    auto &velocities = r.get_components<Velocity>();
    auto &controllables = r.get_components<Controllable>();
    auto &types = r.get_components<Type>();

    for (size_t i = 0; i < positions.size() && i < velocities.size() && i < controllables.size() && i < controllables.size() && i < types.size(); ++i) {
        auto &pos = positions[i];
        auto &vel = velocities[i];
        auto &controllable = controllables[i];
        auto &type = types[i];
        if (pos && vel && controllable && controllable.value().controllable && type) {
            vel.value().vx = 0;
            vel.value().vy = 0;
        }
        if (pos && vel && controllable && controllable.value().controllable && type && type.value().type == received_type) {
            std::cout << "received_type: " << received_type << std::endl;
            std::cout << "type: " << type.value().type << std::endl;
            if (up && (pos.value().y + vel.value().vy) > 0)
                vel.value().vy = -10;
            else if (down && (pos.value().y + vel.value().vy + 100) < 1080)
                vel.value().vy = 10;
            else
                vel.value().vy = 0;
            if (left && (pos.value().x + vel.value().vx) > 0)
                vel.value().vx = -10;
            else if (right && (pos.value().x + vel.value().vx + 100) < 1920)
                vel.value().vx = 10;
            else
                vel.value().vx = 0;

        }
    }
}