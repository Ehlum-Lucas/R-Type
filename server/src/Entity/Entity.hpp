/*
** EPITECH PROJECT, 2023
** Entity.hpp
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_
    #include <cstddef>

    class Entity {
        public:
            explicit Entity(size_t id) : _id(id) {};
            size_t get_id() const {return _id;};
            ~Entity() = default;
        private:
            size_t _id;
    };

#endif /* !ENTITY_HPP_ */
