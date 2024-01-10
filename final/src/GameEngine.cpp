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
            r.add_component_from_prefab(e, sprite);
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

void GameEngine::update()
{
    if (_useInterface) {
        while (_window->isOpen()) {
            _window->clear(sf::Color::Black);
            while (_window->pollEvent(_event)) {
                if (_event.type == sf::Event::Closed) {
                    _window->close();
                }
            }
            _window->display();
        }
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
            animation_system(*current_scene->registry.get());
            sound_system(*current_scene->registry.get());
            draw_system(*current_scene->registry.get());
            _window->display();
        }
    }
}
