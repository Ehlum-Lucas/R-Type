/*
** EPITECH PROJECT, 2023
** controller_system.cpp
** File description:
** controller_system
*/

#include "Registry.hpp"

void controller_system(Registry &r) {
    auto &controllers = r.get_components<Controller>();
    auto &velocities = r.get_components<Velocity>();
    auto &speeds = r.get_components<Speed>();

    for (size_t i = 0; i < controllers.size() && i < velocities.size(); ++i) {
        auto &controller = controllers[i];
        auto &velocity = velocities[i];
        auto &speed = speeds[i];

        if (controller && velocity && speed) {
            velocity.value().vy = 0;
            velocity.value().vx = 0;

            if (sf::Keyboard::isKeyPressed(controller.value().up) && controller.value().can_go_up)
                velocity.value().vy = -speed.value().speed;
            if (sf::Keyboard::isKeyPressed(controller.value().down) && controller.value().can_go_down)
                velocity.value().vy = speed.value().speed;
            if (sf::Keyboard::isKeyPressed(controller.value().left) && controller.value().can_go_left)
                velocity.value().vx = -speed.value().speed;
            if (sf::Keyboard::isKeyPressed(controller.value().right) && controller.value().can_go_right)
                velocity.value().vx = speed.value().speed;
        }
    }
}
