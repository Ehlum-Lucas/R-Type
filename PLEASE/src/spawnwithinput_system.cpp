/*
** EPITECH PROJECT, 2023
** spawnwithinput_system.cpp
** File description:
** spawnwithinput_system
*/

#include "Systems.hpp"

void spawn_with_input_system(Registry &r)
{
    auto &spawnwithinputs = r.get_components<SpawnWithInput>();
    auto &positions = r.get_components<Position>();

    for (size_t i = 0; i < spawnwithinputs.size() && i < positions.size(); ++i) {
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