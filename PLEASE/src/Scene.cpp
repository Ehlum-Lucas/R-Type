/*
** EPITECH PROJECT, 2023
** Scene.cpp
** File description:
** Scene
*/

#include "Scene.hpp"

/**
 * @file Scene.cpp
 * @brief This file contains the implementation of the `Scene` class.
 */

/**
 * The Scene constructor initializes a scene with a given name, a shared pointer to a render window,
 * and an event object, and registers various components in the scene's registry.
 * 
 * @param _name _name is a string that represents the name of the scene. It is used to identify the
 * scene and can be used for various purposes, such as displaying the scene name in the user interface
 * or for internal scene management.
 * @param window The `window` parameter is a `std::shared_ptr` to an `sf::RenderWindow` object. This is
 * a smart pointer that manages the lifetime of the `sf::RenderWindow` object. It is used to interact
 * with the window and render graphics.
 * @param event The "event" parameter is a reference to an sf::Event object. This object is used to
 * handle events such as keyboard input, mouse input, and window events in the SFML library. It allows
 * you to check for and respond to user input and other events that occur during the execution of your
 */

Scene::Scene(std::string _name, std::shared_ptr<sf::RenderWindow> window, sf::Event &event)
{
    name = _name;

    registry = std::make_shared<Registry>(window, event);

    registry->register_component<Id>();

    registry->register_component<Position>();
    registry->register_component<Velocity>();
    registry->register_component<CircleShape>();
    registry->register_component<RectangleShape>();
    registry->register_component<Drawable>();
    registry->register_component<Color>();
    registry->register_component<Gravity>();
    registry->register_component<Controller>();
    registry->register_component<Speed>();
    registry->register_component<Sprite>();
    registry->register_component<Size>();
    registry->register_component<BoxCollider>();
    registry->register_component<Shootable>();
    registry->register_component<OnClickLoadScene>();
    registry->register_component<SpawnWithInput>();
    registry->register_component<Type>();
    registry->register_component<Sendable>();
    registry->register_component<Send>();
}

/**
 * The destructor for the Scene class.
 */

Scene::~Scene()
{
}
