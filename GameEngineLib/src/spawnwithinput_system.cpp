/*
** EPITECH PROJECT, 2023
** spawnwithinput_system.cpp
** File description:
** spawnwithinput_system
*/

/**
 * @file spawnwithinput_system.cpp
 * @brief This file contains the implementation of the `spawnwithinput_system` function.
 */

#include "Systems.hpp"

/**
 * The function applies gravity forces to positions based on their corresponding gravity components.
 * 
 * @param r The parameter `r` is of type `Registry&`, which is a reference to an object of the
 * `Registry` class.
 */

std::string spawn_with_input_system(Registry &r, bool online)
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

                    if (online) {
                        std::string ser = "";
                        std::string bc;
                        std::string ac;
                        int c = 1;
                        spawnwithinput.value().timer = 0;
                        ser += spawnwithinput.value().prefab_name;
                        ser += ";";
                        if (spawnwithinput.value().at_parent_pos) {
                            if (pos.value().x < 0.0) {
                                c = -1;
                                ser += "1";
                            } else {
                                ser += "0";
                            }
                            separateString(std::to_string(pos.value().x * c), bc, ac);
                            ser += bc;
                            ser += ac;
                            if (pos.value().y < 0.0) {
                                c = -1;
                                ser += "1";
                            } else {
                                ser += "0";
                            }
                            separateString(std::to_string(pos.value().y * c), bc, ac);
                            ser += bc;
                            ser += ac;
                        }
                        return ser;
                    }
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
                        } else if (component.type() == typeid(Send)) {
                            auto &comp = std::any_cast<Send&>(component);
                            r.add_component_from_prefab(e, comp);
                        }else if (component.type() == typeid(SpawnWithInput)) {
                            auto &comp = std::any_cast<SpawnWithInput&>(component);
                            r.add_component_from_prefab(e, comp);
                        } else {
                            std::cout << "Component type not found" << std::endl;
                        }
                    }
                    spawnwithinput.value().timer = 0;
                }
            }
            spawnwithinput.value().timer++;
        }
    }
    return "";
}