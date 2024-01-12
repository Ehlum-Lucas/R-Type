/*
** EPITECH PROJECT, 2024
** runner.cpp
** File description:
** runner
*/

#include "GameEngine.hpp"

int main()
{
    GameEngine ecs;

    ecs.setWindow("Runner", 60, true);

    ecs.create_scene("menu");
    ecs.create_scene("level1");
    ecs.create_scene("level2");
    ecs.create_scene("level3");
    ecs.create_scene("level4");
    ecs.create_scene("level5");
    ecs.create_scene("level6");
    ecs.create_scene("level7");

    ecs.create_font("assets/fonts/BruceForeverRegular-X3jd2.ttf");

    ecs.create_texture("assets/character/Player.png");
    ecs.create_texture("assets/city-day/city-parralax-1.png");
    ecs.create_texture("assets/city-day/city-parralax-2.png");
    ecs.create_texture("assets/city-day/city-parralax-3.png");
    ecs.create_texture("assets/city-day/city-parralax-4.png");
    ecs.create_texture("assets/city-day/city-parralax-5.png");
    ecs.create_texture("assets/city-day/city-parralax-6.png");

    ecs.create_texture("assets/desert-day/desert-parralax-1.png");
    ecs.create_texture("assets/desert-day/desert-parralax-2.png");
    ecs.create_texture("assets/desert-day/desert-parralax-3.png");
    ecs.create_texture("assets/desert-day/desert-parralax-4.png");
    ecs.create_texture("assets/desert-day/desert-parralax-5.png");
    ecs.create_texture("assets/desert-day/desert-parralax-6.png");
    ecs.create_texture("assets/desert-day/desert-parralax-7.png");
    ecs.create_texture("assets/desert-day/desert-parralax-8.png");
    ecs.create_texture("assets/desert-day/desert-parralax-9.png");

    ecs.create_texture("assets/field-day/field-parralax-1.png");
    ecs.create_texture("assets/field-day/field-parralax-2.png");
    ecs.create_texture("assets/field-day/field-parralax-3.png");
    ecs.create_texture("assets/field-day/field-parralax-4.png");
    ecs.create_texture("assets/field-day/field-parralax-5.png");
    ecs.create_texture("assets/field-day/field-parralax-6.png");
    ecs.create_texture("assets/field-day/field-parralax-7.png");
    ecs.create_texture("assets/field-day/field-parralax-8.png");
    ecs.create_texture("assets/field-day/field-parralax-9.png");
    ecs.create_texture("assets/field-day/field-parralax-10.png");

    ecs.create_texture("assets/forest-day/forest-parralax-1.png");
    ecs.create_texture("assets/forest-day/forest-parralax-2.png");
    ecs.create_texture("assets/forest-day/forest-parralax-3.png");
    ecs.create_texture("assets/forest-day/forest-parralax-4.png");
    ecs.create_texture("assets/forest-day/forest-parralax-5.png");

    ecs.create_texture("assets/hills-days/hills-parralax-1.png");
    ecs.create_texture("assets/hills-days/hills-parralax-2.png");
    ecs.create_texture("assets/hills-days/hills-parralax-3.png");
    ecs.create_texture("assets/hills-days/hills-parralax-4.png");
    ecs.create_texture("assets/hills-days/hills-parralax-5.png");
    ecs.create_texture("assets/hills-days/hills-parralax-6.png");
    ecs.create_texture("assets/hills-days/hills-parralax-7.png");

    ecs.create_texture("assets/mysterious-forest/mysterious-parralax-1.png");
    ecs.create_texture("assets/mysterious-forest/mysterious-parralax-2.png");
    ecs.create_texture("assets/mysterious-forest/mysterious-parralax-3.png");
    ecs.create_texture("assets/mysterious-forest/mysterious-parralax-4.png");
    ecs.create_texture("assets/mysterious-forest/mysterious-parralax-5.png");
    ecs.create_texture("assets/mysterious-forest/mysterious-parralax-6.png");

    ecs.create_texture("assets/snow-day/snow-parralax-1.png");
    ecs.create_texture("assets/snow-day/snow-parralax-2.png");
    ecs.create_texture("assets/snow-day/snow-parralax-3.png");
    ecs.create_texture("assets/snow-day/snow-parralax-4.png");
    ecs.create_texture("assets/snow-day/snow-parralax-5.png");
    ecs.create_texture("assets/snow-day/snow-parralax-6.png");
    ecs.create_texture("assets/snow-day/snow-parralax-7.png");
    ecs.create_texture("assets/snow-day/snow-parralax-8.png");
    ecs.create_texture("assets/snow-day/snow-parralax-9.png");


    Entity button = ecs.scene("menu")->create_entity();

    ecs.scene("menu")->registry->add_component(button, Position(800, 500));
    ecs.scene("menu")->registry->add_component(button, Size(10, 5));
    ecs.scene("menu")->registry->add_component(button, Drawable());
    ecs.scene("menu")->registry->add_component(button, Sprite("assets/character/Player.png"));
    ecs.scene("menu")->registry->add_component(button, OnClickLoadScene("level7"));


    // Parralax Level 1

    Entity txt = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(txt, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "PRESS [ D ] to show collisions", 32));
    ecs.scene("level1")->registry->add_component(txt, Color(COLOR_BLACK));
    ecs.scene("level1")->registry->add_component(txt, Position(1180, 20));
    ecs.scene("level1")->registry->add_component(txt, Drawable());

    Entity sky = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(sky, Position(1920, 540));
    ecs.scene("level1")->registry->add_component(sky, Size(1, 1));
    ecs.scene("level1")->registry->add_component(sky, Drawable());
    ecs.scene("level1")->registry->add_component(sky, Sprite("assets/city-day/city-parralax-1.png"));
    ecs.scene("level1")->registry->add_component(sky, Parralax(1920, 540, 0));
    ecs.scene("level1")->registry->add_component(sky, Velocity(-2.75, 0));


    Entity backgroundCity2 = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(backgroundCity2, Position(1920, 540));
    ecs.scene("level1")->registry->add_component(backgroundCity2, Size(1, 1));
    ecs.scene("level1")->registry->add_component(backgroundCity2, Drawable());
    ecs.scene("level1")->registry->add_component(backgroundCity2, Sprite("assets/city-day/city-parralax-2.png"));
    ecs.scene("level1")->registry->add_component(backgroundCity2, Parralax(1920, 540, 0));
    ecs.scene("level1")->registry->add_component(backgroundCity2, Velocity(-3, 0));

    Entity backgroundCity3 = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(backgroundCity3, Position(1920, 540));
    ecs.scene("level1")->registry->add_component(backgroundCity3, Size(1, 1));
    ecs.scene("level1")->registry->add_component(backgroundCity3, Drawable());
    ecs.scene("level1")->registry->add_component(backgroundCity3, Sprite("assets/city-day/city-parralax-3.png"));
    ecs.scene("level1")->registry->add_component(backgroundCity3, Parralax(1920, 540, 0));
    ecs.scene("level1")->registry->add_component(backgroundCity3, Velocity(-3.25, 0));

    Entity backgroundCity4 = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(backgroundCity4, Position(1920, 540));
    ecs.scene("level1")->registry->add_component(backgroundCity4, Size(1, 1));
    ecs.scene("level1")->registry->add_component(backgroundCity4, Drawable());
    ecs.scene("level1")->registry->add_component(backgroundCity4, Sprite("assets/city-day/city-parralax-4.png"));
    ecs.scene("level1")->registry->add_component(backgroundCity4, Parralax(1920, 540, 0));
    ecs.scene("level1")->registry->add_component(backgroundCity4, Velocity(-3.5, 0));

    Entity backgroundCity5 = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(backgroundCity5, Position(1920, 540));
    ecs.scene("level1")->registry->add_component(backgroundCity5, Size(1, 1));
    ecs.scene("level1")->registry->add_component(backgroundCity5, Drawable());
    ecs.scene("level1")->registry->add_component(backgroundCity5, Sprite("assets/city-day/city-parralax-5.png"));
    ecs.scene("level1")->registry->add_component(backgroundCity5, Parralax(1920, 540, 0));
    ecs.scene("level1")->registry->add_component(backgroundCity5, Velocity(-4, 0));

    Entity ground = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(ground, Position(1920, 540));
    ecs.scene("level1")->registry->add_component(ground, Size(1, 1));
    ecs.scene("level1")->registry->add_component(ground, Drawable());
    ecs.scene("level1")->registry->add_component(ground, Sprite("assets/city-day/city-parralax-6.png"));
    ecs.scene("level1")->registry->add_component(ground, Parralax(1920, 540, 0));
    ecs.scene("level1")->registry->add_component(ground, Velocity(-4, 0));
    ecs.scene("level1")->registry->add_component(ground, BoxCollider("ground", 3840, 58, 0, 520, false, COLOR_YELLOW_128));

    Entity player = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(player, Position(100, 50));
    ecs.scene("level1")->registry->add_component(player, Size(3, 3));
    ecs.scene("level1")->registry->add_component(player, Drawable());
    ecs.scene("level1")->registry->add_component(player, Sprite("assets/character/Player.png"));
    ecs.scene("level1")->registry->add_component(player, BoxCollider("player", 70, 90, 0, 6, false, COLOR_RED_128));
    ecs.scene("level1")->registry->add_component(player, OnCollideStop("ground"));
    ecs.scene("level1")->registry->add_component(player, Gravity(8));
    ecs.scene("level1")->registry->add_component(player, AddForce(-20, 200, "space"));
    ecs.scene("level1")->registry->add_component(player, ShowCollisionsWithInput("d"));

    // Parralax Level 2

    Entity backgroundDesert1 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(backgroundDesert1, Position(1920, 540));
    ecs.scene("level2")->registry->add_component(backgroundDesert1, Size(1, 1));
    ecs.scene("level2")->registry->add_component(backgroundDesert1, Drawable());
    ecs.scene("level2")->registry->add_component(backgroundDesert1, Sprite("assets/desert-day/desert-parralax-1.png"));
    ecs.scene("level2")->registry->add_component(backgroundDesert1, Parralax(1920, 540, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert1, Velocity(-2.50, 0));

    Entity backgroundDesert2 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(backgroundDesert2, Position(1920, 540));
    ecs.scene("level2")->registry->add_component(backgroundDesert2, Size(1, 1));
    ecs.scene("level2")->registry->add_component(backgroundDesert2, Drawable());
    ecs.scene("level2")->registry->add_component(backgroundDesert2, Sprite("assets/desert-day/desert-parralax-2.png"));
    ecs.scene("level2")->registry->add_component(backgroundDesert2, Parralax(1920, 540, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert2, Velocity(-2.75, 0));
    
    Entity backgroundDesert3 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(backgroundDesert3, Position(1920, 540));
    ecs.scene("level2")->registry->add_component(backgroundDesert3, Size(1, 1));
    ecs.scene("level2")->registry->add_component(backgroundDesert3, Drawable());
    ecs.scene("level2")->registry->add_component(backgroundDesert3, Sprite("assets/desert-day/desert-parralax-3.png"));
    ecs.scene("level2")->registry->add_component(backgroundDesert3, Parralax(1920, 540, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert3, Velocity(-3.0, 0));

    Entity backgroundDesert4 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(backgroundDesert4, Position(1920, 540));
    ecs.scene("level2")->registry->add_component(backgroundDesert4, Size(1, 1));
    ecs.scene("level2")->registry->add_component(backgroundDesert4, Drawable());
    ecs.scene("level2")->registry->add_component(backgroundDesert4, Sprite("assets/desert-day/desert-parralax-4.png"));
    ecs.scene("level2")->registry->add_component(backgroundDesert4, Parralax(1920, 540, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert4, Velocity(-3.25, 0));

    Entity backgroundDesert6 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(backgroundDesert6, Position(1920, 540));   
    ecs.scene("level2")->registry->add_component(backgroundDesert6, Size(1, 1));
    ecs.scene("level2")->registry->add_component(backgroundDesert6, Drawable());
    ecs.scene("level2")->registry->add_component(backgroundDesert6, Sprite("assets/desert-day/desert-parralax-6.png"));
    ecs.scene("level2")->registry->add_component(backgroundDesert6, Parralax(1920, 540, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert6, Velocity(-3.75, 0));

    Entity backgroundDesert7 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(backgroundDesert7, Position(1920, 540));
    ecs.scene("level2")->registry->add_component(backgroundDesert7, Size(1, 1));
    ecs.scene("level2")->registry->add_component(backgroundDesert7, Drawable());
    ecs.scene("level2")->registry->add_component(backgroundDesert7, Sprite("assets/desert-day/desert-parralax-7.png"));
    ecs.scene("level2")->registry->add_component(backgroundDesert7, Parralax(1920, 540, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert7, Velocity(-4, 0));

    Entity backgroundDesert8 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Position(1920, 540));
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Size(1, 1));
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Drawable());
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Sprite("assets/desert-day/desert-parralax-8.png"));
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Parralax(1920, 540, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Velocity(-4, 0));

    Entity backgroundDesert9 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Position(1920, 540));
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Size(1, 1));
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Drawable());
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Sprite("assets/desert-day/desert-parralax-9.png"));
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Parralax(1920, 540, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Velocity(-4, 0));

    // Parralax Level 3

    Entity backgroundField1 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField1, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField1, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField1, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField1, Sprite("assets/field-day/field-parralax-1.png"));
    ecs.scene("level3")->registry->add_component(backgroundField1, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField1, Velocity(-2.25, 0));

    Entity backgroundField2 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField2, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField2, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField2, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField2, Sprite("assets/field-day/field-parralax-2.png"));
    ecs.scene("level3")->registry->add_component(backgroundField2, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField2, Velocity(-2.5, 0));

    Entity backgroundField3 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField3, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField3, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField3, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField3, Sprite("assets/field-day/field-parralax-3.png"));
    ecs.scene("level3")->registry->add_component(backgroundField3, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField3, Velocity(-2.75, 0));

    Entity backgroundField4 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField4, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField4, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField4, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField4, Sprite("assets/field-day/field-parralax-4.png"));
    ecs.scene("level3")->registry->add_component(backgroundField4, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField4, Velocity(-3, 0));

    Entity backgroundField5 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField5, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField5, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField5, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField5, Sprite("assets/field-day/field-parralax-5.png"));
    ecs.scene("level3")->registry->add_component(backgroundField5, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField5, Velocity(-3.25, 0));

    Entity backgroundField6 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField6, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField6, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField6, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField6, Sprite("assets/field-day/field-parralax-6.png"));
    ecs.scene("level3")->registry->add_component(backgroundField6, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField6, Velocity(-3.5, 0));

    Entity backgroundField7 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField7, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField7, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField7, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField7, Sprite("assets/field-day/field-parralax-7.png"));
    ecs.scene("level3")->registry->add_component(backgroundField7, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField7, Velocity(-3.75, 0));

    Entity backgroundField8 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField8, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField8, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField8, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField8, Sprite("assets/field-day/field-parralax-8.png"));
    ecs.scene("level3")->registry->add_component(backgroundField8, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField8, Velocity(-4, 0));

    Entity backgroundField9 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField9, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField9, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField9, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField9, Sprite("assets/field-day/field-parralax-9.png"));
    ecs.scene("level3")->registry->add_component(backgroundField9, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField9, Velocity(-4, 0));


    Entity backgroundField10 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField10, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField10, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField10, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField10, Sprite("assets/field-day/field-parralax-10.png"));
    ecs.scene("level3")->registry->add_component(backgroundField10, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField10, Velocity(-4, 0));

    // Parralax Level 4

    Entity backgroundForest1 = ecs.scene("level4")->create_entity();
    ecs.scene("level4")->registry->add_component(backgroundForest1, Position(1920, 540));
    ecs.scene("level4")->registry->add_component(backgroundForest1, Size(1, 1));
    ecs.scene("level4")->registry->add_component(backgroundForest1, Drawable());
    ecs.scene("level4")->registry->add_component(backgroundForest1, Sprite("assets/forest-day/forest-parralax-1.png"));
    ecs.scene("level4")->registry->add_component(backgroundForest1, Parralax(1920, 540, 0));
    ecs.scene("level4")->registry->add_component(backgroundForest1, Velocity(-3, 0));

    Entity backgroundForest2 = ecs.scene("level4")->create_entity();
    ecs.scene("level4")->registry->add_component(backgroundForest2, Position(1920, 540));
    ecs.scene("level4")->registry->add_component(backgroundForest2, Size(1, 1));
    ecs.scene("level4")->registry->add_component(backgroundForest2, Drawable());
    ecs.scene("level4")->registry->add_component(backgroundForest2, Sprite("assets/forest-day/forest-parralax-2.png"));
    ecs.scene("level4")->registry->add_component(backgroundForest2, Parralax(1920, 540, 0));
    ecs.scene("level4")->registry->add_component(backgroundForest2, Velocity(-3.5, 0));

    Entity backgroundForest3 = ecs.scene("level4")->create_entity();
    ecs.scene("level4")->registry->add_component(backgroundForest3, Position(1920, 540));
    ecs.scene("level4")->registry->add_component(backgroundForest3, Size(1, 1));
    ecs.scene("level4")->registry->add_component(backgroundForest3, Drawable());
    ecs.scene("level4")->registry->add_component(backgroundForest3, Sprite("assets/forest-day/forest-parralax-3.png"));
    ecs.scene("level4")->registry->add_component(backgroundForest3, Parralax(1920, 540, 0));
    ecs.scene("level4")->registry->add_component(backgroundForest3, Velocity(-4, 0));

    Entity backgroundForest4 = ecs.scene("level4")->create_entity();
    ecs.scene("level4")->registry->add_component(backgroundForest4, Position(1920, 540));
    ecs.scene("level4")->registry->add_component(backgroundForest4, Size(1, 1));
    ecs.scene("level4")->registry->add_component(backgroundForest4, Drawable());
    ecs.scene("level4")->registry->add_component(backgroundForest4, Sprite("assets/forest-day/forest-parralax-4.png"));
    ecs.scene("level4")->registry->add_component(backgroundForest4, Parralax(1920, 540, 0));
    ecs.scene("level4")->registry->add_component(backgroundForest4, Velocity(-4, 0));

    Entity backgroundForest5 = ecs.scene("level4")->create_entity();
    ecs.scene("level4")->registry->add_component(backgroundForest5, Position(1920, 540));
    ecs.scene("level4")->registry->add_component(backgroundForest5, Size(1, 1));
    ecs.scene("level4")->registry->add_component(backgroundForest5, Drawable());
    ecs.scene("level4")->registry->add_component(backgroundForest5, Sprite("assets/forest-day/forest-parralax-5.png"));
    ecs.scene("level4")->registry->add_component(backgroundForest5, Parralax(1920, 540, 0));
    ecs.scene("level4")->registry->add_component(backgroundForest5, Velocity(-4, 0));

    // Parralax Level 5

    Entity backgroundHills1 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(backgroundHills1, Position(1920, 540));
    ecs.scene("level5")->registry->add_component(backgroundHills1, Size(1, 1));
    ecs.scene("level5")->registry->add_component(backgroundHills1, Drawable());
    ecs.scene("level5")->registry->add_component(backgroundHills1, Sprite("assets/hills-days/hills-parralax-1.png"));
    ecs.scene("level5")->registry->add_component(backgroundHills1, Parralax(1920, 540, 0));
    ecs.scene("level5")->registry->add_component(backgroundHills1, Velocity(-2.75, 0));

    Entity backgroundHills2 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(backgroundHills2, Position(1920, 540));
    ecs.scene("level5")->registry->add_component(backgroundHills2, Size(1, 1));
    ecs.scene("level5")->registry->add_component(backgroundHills2, Drawable());
    ecs.scene("level5")->registry->add_component(backgroundHills2, Sprite("assets/hills-days/hills-parralax-2.png"));
    ecs.scene("level5")->registry->add_component(backgroundHills2, Parralax(1920, 540, 0));
    ecs.scene("level5")->registry->add_component(backgroundHills2, Velocity(-3.25, 0));

    Entity backgroundHills3 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(backgroundHills3, Position(1920, 540));
    ecs.scene("level5")->registry->add_component(backgroundHills3, Size(1, 1));
    ecs.scene("level5")->registry->add_component(backgroundHills3, Drawable());
    ecs.scene("level5")->registry->add_component(backgroundHills3, Sprite("assets/hills-days/hills-parralax-3.png"));
    ecs.scene("level5")->registry->add_component(backgroundHills3, Parralax(1920, 540, 0));
    ecs.scene("level5")->registry->add_component(backgroundHills3, Velocity(-3.5, 0));

    Entity backgroundHills4 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(backgroundHills4, Position(1920, 540));
    ecs.scene("level5")->registry->add_component(backgroundHills4, Size(1, 1));
    ecs.scene("level5")->registry->add_component(backgroundHills4, Drawable());
    ecs.scene("level5")->registry->add_component(backgroundHills4, Sprite("assets/hills-days/hills-parralax-4.png"));
    ecs.scene("level5")->registry->add_component(backgroundHills4, Parralax(1920, 540, 0));
    ecs.scene("level5")->registry->add_component(backgroundHills4, Velocity(-3.75, 0));

    Entity backgroundHills5 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(backgroundHills5, Position(1920, 540));
    ecs.scene("level5")->registry->add_component(backgroundHills5, Size(1, 1));
    ecs.scene("level5")->registry->add_component(backgroundHills5, Drawable());
    ecs.scene("level5")->registry->add_component(backgroundHills5, Sprite("assets/hills-days/hills-parralax-5.png"));
    ecs.scene("level5")->registry->add_component(backgroundHills5, Parralax(1920, 540, 0));
    ecs.scene("level5")->registry->add_component(backgroundHills5, Velocity(-4, 0));

    Entity backgroundHills6 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(backgroundHills6, Position(1920, 540));
    ecs.scene("level5")->registry->add_component(backgroundHills6, Size(1, 1));
    ecs.scene("level5")->registry->add_component(backgroundHills6, Drawable());
    ecs.scene("level5")->registry->add_component(backgroundHills6, Sprite("assets/hills-days/hills-parralax-6.png"));
    ecs.scene("level5")->registry->add_component(backgroundHills6, Parralax(1920, 540, 0));
    ecs.scene("level5")->registry->add_component(backgroundHills6, Velocity(-4, 0));

    Entity backgroundHills7 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(backgroundHills7, Position(1920, 540));
    ecs.scene("level5")->registry->add_component(backgroundHills7, Size(1, 1));
    ecs.scene("level5")->registry->add_component(backgroundHills7, Drawable());
    ecs.scene("level5")->registry->add_component(backgroundHills7, Sprite("assets/hills-days/hills-parralax-7.png"));
    ecs.scene("level5")->registry->add_component(backgroundHills7, Parralax(1920, 540, 0));
    ecs.scene("level5")->registry->add_component(backgroundHills7, Velocity(-4, 0));

    // Parralax Level 6

    Entity backgroundMysterious1 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(backgroundMysterious1, Position(1920, 540));
    ecs.scene("level6")->registry->add_component(backgroundMysterious1, Size(1, 1));
    ecs.scene("level6")->registry->add_component(backgroundMysterious1, Drawable());
    ecs.scene("level6")->registry->add_component(backgroundMysterious1, Sprite("assets/mysterious-forest/mysterious-parralax-1.png"));
    ecs.scene("level6")->registry->add_component(backgroundMysterious1, Parralax(1920, 540, 0));
    ecs.scene("level6")->registry->add_component(backgroundMysterious1, Velocity(-2.75, 0));

    Entity backgroundMysterious2 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(backgroundMysterious2, Position(1920, 540));
    ecs.scene("level6")->registry->add_component(backgroundMysterious2, Size(1, 1));
    ecs.scene("level6")->registry->add_component(backgroundMysterious2, Drawable());
    ecs.scene("level6")->registry->add_component(backgroundMysterious2, Sprite("assets/mysterious-forest/mysterious-parralax-2.png"));
    ecs.scene("level6")->registry->add_component(backgroundMysterious2, Parralax(1920, 540, 0));
    ecs.scene("level6")->registry->add_component(backgroundMysterious2, Velocity(-3.25, 0));

    Entity backgroundMysterious3 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(backgroundMysterious3, Position(1920, 540));
    ecs.scene("level6")->registry->add_component(backgroundMysterious3, Size(1, 1));
    ecs.scene("level6")->registry->add_component(backgroundMysterious3, Drawable());
    ecs.scene("level6")->registry->add_component(backgroundMysterious3, Sprite("assets/mysterious-forest/mysterious-parralax-3.png"));
    ecs.scene("level6")->registry->add_component(backgroundMysterious3, Parralax(1920, 540, 0));
    ecs.scene("level6")->registry->add_component(backgroundMysterious3, Velocity(-3.5, 0));

    Entity backgroundMysterious4 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(backgroundMysterious4, Position(1920, 540));
    ecs.scene("level6")->registry->add_component(backgroundMysterious4, Size(1, 1));
    ecs.scene("level6")->registry->add_component(backgroundMysterious4, Drawable());
    ecs.scene("level6")->registry->add_component(backgroundMysterious4, Sprite("assets/mysterious-forest/mysterious-parralax-4.png"));
    ecs.scene("level6")->registry->add_component(backgroundMysterious4, Parralax(1920, 540, 0));
    ecs.scene("level6")->registry->add_component(backgroundMysterious4, Velocity(-4, 0));

    Entity backgroundMysterious5 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Position(1920, 540));
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Size(1, 1));
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Drawable());
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Sprite("assets/mysterious-forest/mysterious-parralax-5.png"));
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Parralax(1920, 540, 0));
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Velocity(-4, 0));

    Entity backgroundMysterious6 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Position(1920, 540));
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Size(1, 1));
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Drawable());
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Sprite("assets/mysterious-forest/mysterious-parralax-6.png"));
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Parralax(1920, 540, 0));
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Velocity(-4, 0));

    // Parralax Level 7

    Entity backgroundSnow1 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(backgroundSnow1, Position(1920, 540));
    ecs.scene("level7")->registry->add_component(backgroundSnow1, Size(1, 1));
    ecs.scene("level7")->registry->add_component(backgroundSnow1, Drawable());
    ecs.scene("level7")->registry->add_component(backgroundSnow1, Sprite("assets/snow-day/snow-parralax-1.png"));
    ecs.scene("level7")->registry->add_component(backgroundSnow1, Parralax(1920, 540, 0));
    ecs.scene("level7")->registry->add_component(backgroundSnow1, Velocity(-2.25, 0));

    Entity backgroundSnow2 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(backgroundSnow2, Position(1920, 540));
    ecs.scene("level7")->registry->add_component(backgroundSnow2, Size(1, 1));
    ecs.scene("level7")->registry->add_component(backgroundSnow2, Drawable());
    ecs.scene("level7")->registry->add_component(backgroundSnow2, Sprite("assets/snow-day/snow-parralax-2.png"));
    ecs.scene("level7")->registry->add_component(backgroundSnow2, Parralax(1920, 540, 0));
    ecs.scene("level7")->registry->add_component(backgroundSnow2, Velocity(-2.5, 0));

    Entity backgroundSnow3 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(backgroundSnow3, Position(1920, 540));
    ecs.scene("level7")->registry->add_component(backgroundSnow3, Size(1, 1));
    ecs.scene("level7")->registry->add_component(backgroundSnow3, Drawable());
    ecs.scene("level7")->registry->add_component(backgroundSnow3, Sprite("assets/snow-day/snow-parralax-3.png"));
    ecs.scene("level7")->registry->add_component(backgroundSnow3, Parralax(1920, 540, 0));
    ecs.scene("level7")->registry->add_component(backgroundSnow3, Velocity(-2.75, 0));

    Entity backgroundSnow4 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(backgroundSnow4, Position(1920, 540));
    ecs.scene("level7")->registry->add_component(backgroundSnow4, Size(1, 1));
    ecs.scene("level7")->registry->add_component(backgroundSnow4, Drawable());
    ecs.scene("level7")->registry->add_component(backgroundSnow4, Sprite("assets/snow-day/snow-parralax-4.png"));
    ecs.scene("level7")->registry->add_component(backgroundSnow4, Parralax(1920, 540, 0));
    ecs.scene("level7")->registry->add_component(backgroundSnow4, Velocity(-3, 0));

    Entity backgroundSnow5 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(backgroundSnow5, Position(1920, 540));
    ecs.scene("level7")->registry->add_component(backgroundSnow5, Size(1, 1));
    ecs.scene("level7")->registry->add_component(backgroundSnow5, Drawable());
    ecs.scene("level7")->registry->add_component(backgroundSnow5, Sprite("assets/snow-day/snow-parralax-5.png"));
    ecs.scene("level7")->registry->add_component(backgroundSnow5, Parralax(1920, 540, 0));
    ecs.scene("level7")->registry->add_component(backgroundSnow5, Velocity(-3.25, 0));

    Entity backgroundSnow6 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(backgroundSnow6, Position(1920, 540));
    ecs.scene("level7")->registry->add_component(backgroundSnow6, Size(1, 1));
    ecs.scene("level7")->registry->add_component(backgroundSnow6, Drawable());
    ecs.scene("level7")->registry->add_component(backgroundSnow6, Sprite("assets/snow-day/snow-parralax-6.png"));
    ecs.scene("level7")->registry->add_component(backgroundSnow6, Parralax(1920, 540, 0));
    ecs.scene("level7")->registry->add_component(backgroundSnow6, Velocity(-3.5, 0));

    Entity backgroundSnow7 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(backgroundSnow7, Position(1920, 540));
    ecs.scene("level7")->registry->add_component(backgroundSnow7, Size(1, 1));
    ecs.scene("level7")->registry->add_component(backgroundSnow7, Drawable());
    ecs.scene("level7")->registry->add_component(backgroundSnow7, Sprite("assets/snow-day/snow-parralax-7.png"));
    ecs.scene("level7")->registry->add_component(backgroundSnow7, Parralax(1920, 540, 0));
    ecs.scene("level7")->registry->add_component(backgroundSnow7, Velocity(-3.75, 0));

    Entity backgroundSnow8 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(backgroundSnow8, Position(1920, 540));
    ecs.scene("level7")->registry->add_component(backgroundSnow8, Size(1, 1));
    ecs.scene("level7")->registry->add_component(backgroundSnow8, Drawable());
    ecs.scene("level7")->registry->add_component(backgroundSnow8, Sprite("assets/snow-day/snow-parralax-8.png"));
    ecs.scene("level7")->registry->add_component(backgroundSnow8, Parralax(1920, 540, 0));
    ecs.scene("level7")->registry->add_component(backgroundSnow8, Velocity(-4, 0));

    Entity backgroundSnow9 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(backgroundSnow9, Position(1920, 540));
    ecs.scene("level7")->registry->add_component(backgroundSnow9, Size(1, 1));
    ecs.scene("level7")->registry->add_component(backgroundSnow9, Drawable());
    ecs.scene("level7")->registry->add_component(backgroundSnow9, Sprite("assets/snow-day/snow-parralax-9.png"));
    ecs.scene("level7")->registry->add_component(backgroundSnow9, Parralax(1920, 540, 0));
    ecs.scene("level7")->registry->add_component(backgroundSnow9, Velocity(-4, 0));

    ecs.load_scene("level1");
    ecs.update();

    return 0;
}