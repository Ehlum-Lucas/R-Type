/*
** EPITECH PROJECT, 2023
** Systems.hpp
** File description:
** Systems
*/

#ifndef SYSTEMS_HPP_
    #define SYSTEMS_HPP_
    #include "Registry.hpp"

    void controller_system(Registry &r);
    void position_system (Registry &r);
    void draw_system(Registry &r);
    void quit_system(Registry &r);
    void gravity_system(Registry &r);
    void shoot_system(Registry &r);
    void collide_system(Registry &r);
    std::string onclickloadscene_system(Registry &r);

#endif /* !SYSTEMS_HPP_ */
