/*
** EPITECH PROJECT, 2023
** Systems.hpp
** File description:
** Systems
*/

#ifndef SYSTEMS_HPP_
    #define SYSTEMS_HPP_
    #include "Registry.hpp"
    #include "Components.hpp"

    void position_system (Registry &r);
    void control_system(Registry &r, std::string &inputs);
    std::vector<std::string> serialize_system (Registry &r);

#endif /* !SYSTEMS_HPP_ */
