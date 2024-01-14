/*
** EPITECH PROJECT, 2023
** Scene.cpp
** File description:
** Scene
*/

/**
 * @file Scene.cpp
 * @brief This file contains the implementation of the `Scene` class.
 */

#include "Scene.hpp"

/**
 * The Scene constructor initializes a scene with a given name and registers various components in the
 * scene's registry.
 * 
 * @param _name _name is a string that represents the name of the scene. It is used to identify the
 * scene and differentiate it from other scenes in the game.
 * @param window The `window` parameter is a `std::shared_ptr` to an `sf::RenderWindow` object. It
 * represents the window in which the scene will be rendered.
 * @param event The `event` parameter is a reference to an `sf::Event` object. `sf::Event` is a class
 * that represents an event that has occurred in the window, such as a mouse click or a keyboard press.
 * By passing this parameter to the `Scene` constructor, it allows the
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
    registry->register_component<Parralax>();
    registry->register_component<Send>();
    registry->register_component<OnCollideStop>();
    registry->register_component<AddForce>();
    registry->register_component<ShowCollisionsWithInput>();
    registry->register_component<Text>();
    registry->register_component<SpawnPrefabAtRandomPosition>();
    registry->register_component<OnCollideLoadScene>();
}

/**
 * The destructor for the Scene class.
 */

Scene::~Scene()
{
}
