/*
** EPITECH PROJECT, 2023
** Scene.cpp
** File description:
** Scene
*/

#include "Scene.hpp"

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
    registry->register_component<Shoot>();
    registry->register_component<BoxCollider>();
    registry->register_component<Shootable>();
    registry->register_component<OnClickLoadScene>();
    registry->register_component<SpawnWithInput>();
    registry->register_component<Prefab>();

}

Scene::~Scene()
{
}
