/*
** EPITECH PROJECT, 2024
** on_collide_load_scene.cpp
** File description:
** on_collide_load_scene
*/

#include "Systems.hpp"

std::string on_collide_load_scene_system(Registry &r)
{
    auto &oncollideloadcenes = r.get_components<OnCollideLoadScene>();
    auto &boxcolliders = r.get_components<BoxCollider>();
    auto &positions = r.get_components<Position>();

    for (size_t i = 0; i < oncollideloadcenes.size() && i < boxcolliders.size(); ++i) {
        auto &oncollideloadcene = oncollideloadcenes[i];
        auto &boxcollider1 = boxcolliders[i];

        if (oncollideloadcene && boxcollider1) {

            for (size_t j = 0; j < boxcolliders.size() && j < positions.size(); ++j) {
                auto &boxcollider2 = boxcolliders[j];
                auto &position = positions[j];

                if (boxcollider2 && i != j && oncollideloadcene.value().tag == boxcollider2.value().tag) {
                    boxcollider2.value().collider->setPosition(position.value().x + boxcollider2.value().origin_x, position.value().y + boxcollider2.value().origin_y);
                    if (boxcollider1.value().collider->getGlobalBounds().intersects(boxcollider2.value().collider->getGlobalBounds())) {
                        return oncollideloadcene.value().scene_name;
                    }
                }

            }
        }
    }
    return "";
}
