/*
** EPITECH PROJECT, 2023
** collide_system.cpp
** File description:
** collide_system
*/

#include "Systems.hpp"

void collide_system(Registry &r)
{
    auto &positions = r.get_components<Position>();
    auto &box_colliders = r.get_components<BoxCollider>();
    auto &sprites = r.get_components<Sprite>();
    auto &sizes = r.get_components<Size>();
    auto &ids = r.get_components<Id>();
    auto &shootables = r.get_components<Shootable>();

    for (size_t i = 0; i < positions.size() && i < box_colliders.size() && i < sprites.size() && i < sizes.size() && i < ids.size(); ++i) {
        bool check = false;
        auto &pos1 = positions[i];
        auto &box_collider1 = box_colliders[i];
        auto &sprite1 = sprites[i];
        auto &size1 = sizes[i];
        auto &id1 = ids[i];

        if (pos1 && box_collider1 && sprite1 && size1 && id1) {
            sf::RectangleShape col1(sf::Vector2f(sprite1.value().texture.getSize().x, sprite1.value().texture.getSize().y));
            col1.setOrigin(sprite1.value().texture.getSize().x / 2, sprite1.value().texture.getSize().y / 2);
            col1.setScale(size1.value().width, size1.value().height);
            col1.setFillColor(box_collider1.value().color);
            col1.setPosition(pos1.value().x, pos1.value().y);
            if (box_collider1.value().draw)
                r._window->draw(col1);
            for (size_t y = 0; y < positions.size() && y < box_colliders.size() && y < shootables.size(); ++y) {
                auto &pos2 = positions[y];
                auto &box_collider2 = box_colliders[y];
                auto &sprite2 = sprites[y];
                auto &size2 = sizes[y];
                auto &id2 = ids[y];
                auto &shootable = shootables[y];

                if (pos2 && box_collider2 && id2 && sprite2 && size2 && y != i && box_collider1.value().tag == "bullet" && box_collider2.value().tag == "enemy" && shootable) {
                    sf::RectangleShape col2(sf::Vector2f(sprite2.value().texture.getSize().x, sprite2.value().texture.getSize().y));
                    col2.setOrigin(sprite2.value().texture.getSize().x / 2, sprite2.value().texture.getSize().y / 2);
                    col2.setScale(size2.value().width, size2.value().height);
                    col2.setFillColor(sf::Color::Red);
                    col2.setPosition(pos2.value().x, pos2.value().y);

                    if (col1.getGlobalBounds().intersects(col2.getGlobalBounds())) {
                        std::cout << "COLLISION" << std::endl;
                        r.delete_entity_by_id(id1.value().id);
                        r.delete_entity_by_id(id2.value().id);
                        check = true;
                        break;
                    }
                }
            }
            if (check) {
                continue;
            }
        }

    }
}