/*
** EPITECH PROJECT, 2024
** spawn_at_random_position_system.cpp
** File description:
** spawn_at_random_position_system
*/

#include "Systems.hpp"

void spawn_at_random_position_system(Registry &r)
{
    auto &spawn_at_random_positions = r.get_components<SpawnPrefabAtRandomPosition>();

    for (size_t i = 0; i < spawn_at_random_positions.size(); ++i) {
        auto &spawn_at_random_position = spawn_at_random_positions[i];

        if (spawn_at_random_position) {
            if (spawn_at_random_position.value().timer >= spawn_at_random_position.value().delay) {
                spawn_at_random_position.value().timer = 0;

                auto prefab_components = r.get_prefab(spawn_at_random_position.value().prefab_name);

                Entity e = r.create_entity();
                r.add_component(e, Id(e.get_id()));

                auto &boxcollider = r.get_components<BoxCollider>();
                auto &position = r.get_components<Position>();

                int randomX = std::rand() % (spawn_at_random_position.value().x_max - spawn_at_random_position.value().x_min + 1) + spawn_at_random_position.value().x_min;
                int randomY = std::rand() % (spawn_at_random_position.value().y_max - spawn_at_random_position.value().y_min + 1) + spawn_at_random_position.value().y_min;

                r.add_component(e, Position(randomX, randomY));
            
                for (auto component : prefab_components) {
                    if (component.type() == typeid(Sprite)) {
                        auto &sprite = std::any_cast<Sprite&>(component);
                        r.add_component_from_prefab(e, sprite);
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
                
            } else {
                spawn_at_random_position.value().timer += 1;
            }
        }
    }
}
