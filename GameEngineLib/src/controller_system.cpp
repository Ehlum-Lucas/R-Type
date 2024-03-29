/*
** EPITECH PROJECT, 2023
** controller_system.cpp
** File description:
** controller_system
*/

/**
 * @file controller_system.cpp
 * @brief This file contains the implementation of the `controller_system` function.
 */

#include "Registry.hpp"

/**
 * The function `controller_system` updates the velocities of entities based on keyboard inputs and
 * controller settings.
 * 
 * @param r The parameter `r` is a reference to an object of type `Registry`.
 */

void controller_system(Registry &r) {
    auto &controllers = r.get_components<Controller>();
    auto &velocities = r.get_components<Velocity>();
    auto &speeds = r.get_components<Speed>();

    // std::cout << "controllers" << controllers.size() << std::endl;
    for (size_t i = 0; i < controllers.size() && i < velocities.size(); ++i) {
        auto &controller = controllers[i];
        auto &velocity = velocities[i];
        auto &speed = speeds[i];


        if (controller && velocity && speed) {
            velocity.value().vy = 0;
            velocity.value().vx = 0;
            // std::cout << "ici gros" << std::endl;

            if (sf::Keyboard::isKeyPressed(controller.value().up) && controller.value().can_go_up) {
                velocity.value().vy = -speed.value().speed;
                // std::cout << "UP" << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(controller.value().down) && controller.value().can_go_down) {
                velocity.value().vy = speed.value().speed;
                // std::cout << "DOWN" << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(controller.value().left) && controller.value().can_go_left) {
                velocity.value().vx = -speed.value().speed;
                // std::cout << "LEFT" << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(controller.value().right) && controller.value().can_go_right) {
                velocity.value().vx = speed.value().speed;
                // std::cout << "RIGHT" << std::endl;
            }
        }
    }
    // std::cout << "finis gros" << std::endl;
}
