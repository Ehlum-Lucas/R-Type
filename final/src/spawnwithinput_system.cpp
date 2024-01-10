/*
** EPITECH PROJECT, 2023
** spawnwithinput_system.cpp
** File description:
** spawnwithinput_system
*/

#include "Systems.hpp"

/**
 * @file spawnwithinput_system.cpp
 * @brief This file contains the implementation of the `spawnwithinput_system` function.
 */

/**
 * The function `spawn_with_input_system` spawns entities based on user input and adds components to
 * them from a prefab.
 * 
 * @param r The parameter "r" is of type "Registry&", which is a reference to an object of the
 * "Registry" class.
 */

void spawn_with_input_system(Registry &r)
{
    auto &spawnwithinputs = r.get_components<SpawnWithInput>();
    auto &positions = r.get_components<Position>();

    for (std::size_t i = 0; i < spawnwithinputs.size() && i < positions.size(); ++i) {
        auto &spawnwithinput = spawnwithinputs[i];
        auto const &pos = positions[i];

        if (spawnwithinput && pos) {

            if (spawnwithinput.value().timer >= spawnwithinput.value().delay) {
                if (sf::Keyboard::isKeyPressed(spawnwithinput.value().input)) {
                    auto prefab_components = r.get_prefab(spawnwithinput.value().prefab_name);

                    Entity e = r.create_entity();
                    r.add_component(e, Id(e.get_id()));
                    for (auto component : prefab_components) {
                        if (component.type() == typeid(Sprite)) {
                            auto &sprite = std::any_cast<Sprite&>(component);
                            r.add_component_from_prefab(e, sprite);
                        } else if (component.type() == typeid(Position)) {
                            auto &position = std::any_cast<Position&>(component);
                            if (spawnwithinput.value().at_parent_pos) {
                                r.add_component(e, Position(pos.value().x, pos.value().y));
                            } else {
                                r.add_component_from_prefab(e, position);
                            }
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
                        } else if (component.type() == typeid(OnCollideDestroy)) {
                            auto &comp = std::any_cast<OnCollideDestroy&>(component);
                            r.add_component_from_prefab(e, comp);
                        }
                    }
                    spawnwithinput.value().timer = 0;
                }
            }
            spawnwithinput.value().timer++;

            //  auto &drawables = r.get_components<Drawable>();
            // auto &positions = r.get_components<Position>();
            // auto &sprites = r.get_components<Sprite>();
            // auto &sizes = r.get_components<Size>();

            // if (sf::Keyboard::isKeyPressed(spawnwithinput.value().input)) {
            //     auto &components = r.get_entity_components();
            // }
        }
    }
}