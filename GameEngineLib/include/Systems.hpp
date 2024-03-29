/*
** EPITECH PROJECT, 2023
** Systems.hpp
** File description:
** Systems
*/

/**
 * @file Systems.hpp
 * @brief This file contains the declaration of the `Systems` functions.
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
    std::vector<std::string> serialize_components(Registry &r);
    void parralax_system (Registry &r);
    std::string  spawn_with_input_system(Registry &r, bool online);
    void boxcollider_system(Registry &r);
    void oncollidestop_system(Registry &r);
    void addforce_system(Registry &r);
    void showcollisionswithinput_system(Registry &r);
    void text_system(Registry &r);
    void spawn_at_random_position_system(Registry &r);
    void animation_system(Registry &r);
    std::string on_collide_load_scene_system(Registry &r);
    void sound_system(Registry &r);
    

#endif /* !SYSTEMS_HPP_ */
