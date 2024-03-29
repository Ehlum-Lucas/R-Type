/*
** EPITECH PROJECT, 2023
** Entity.hpp
** File description:
** Entity
*/

/**
 * @file Entity.hpp
 * @brief This file contains the declaration of the `Entity` class.
 */

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_
    #include <vector>
    #include <cstddef>
    extern size_t next_entity_id;

    class Entity {
        public:
            explicit Entity();
            size_t get_id() const {return _id;};
            void delete_entity() {_deleted_ids.push_back(_id);};
            ~Entity() = default;
        private:
            size_t _id;
            std::vector<size_t> _deleted_ids;
    };

#endif /* !ENTITY_HPP_ */
