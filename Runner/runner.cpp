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
    ecs.create_texture("assets/obstacle/barrel.png");
    ecs.create_texture("assets/obstacle/rock.png");
    ecs.create_texture("assets/obstacle/chest.png");
    ecs.create_texture("assets/obstacle/palm.png");
    ecs.create_texture("assets/obstacle/shroom.png");
    ecs.create_texture("assets/obstacle/skull.png");
    ecs.create_texture("assets/obstacle/stalactite.png");
    
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

    ecs.create_texture("assets/menu/BackArrow.png");
    ecs.create_texture("assets/menu/background.png");
    ecs.create_texture("assets/menu/GreenButton.png");
    ecs.create_texture("assets/menu/RedButton.png");
    ecs.create_texture("assets/menu/background.png");
    ecs.create_texture("assets/menu/RightArrow.png");

    // Menu

    Entity background = ecs.scene("menu")->create_entity();
    ecs.scene("menu")->registry->add_component(background, Position(960, -1320));
    ecs.scene("menu")->registry->add_component(background, Size(1, 1));
    ecs.scene("menu")->registry->add_component(background, Drawable());
    ecs.scene("menu")->registry->add_component(background, Sprite("assets/menu/background.png"));
    ecs.scene("menu")->registry->add_component(background, Parralax(960, -1320, 1080));
    ecs.scene("menu")->registry->add_component(background, Velocity(0, 1));

    Entity buttonPlay = ecs.scene("menu")->create_entity();
    ecs.scene("menu")->registry->add_component(buttonPlay, Position(1920/2, 1080/2));
    ecs.scene("menu")->registry->add_component(buttonPlay, Size(3, 3));
    ecs.scene("menu")->registry->add_component(buttonPlay, Drawable());
    ecs.scene("menu")->registry->add_component(buttonPlay, Sprite("assets/menu/GreenButton.png"));
    ecs.scene("menu")->registry->add_component(buttonPlay, OnClickLoadScene("level1Choose"));
    ecs.scene("menu")->registry->add_component(buttonPlay, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "Play", 64));
    ecs.scene("menu")->registry->add_component(buttonPlay, Color(COLOR_WHITE));

    Entity Title = ecs.scene("menu")->create_entity();
    ecs.scene("menu")->registry->add_component(Title, Position(1920/2, 1080/2 - 400));
    ecs.scene("menu")->registry->add_component(Title, Drawable());
    ecs.scene("menu")->registry->add_component(Title, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "Runner", 128));
    ecs.scene("menu")->registry->add_component(Title, Color(COLOR_WHITE));

    // Level Choose

    std::map<std::string, std::vector<std::string>> _choices;
    _choices["level1Choose"] = {"assets/city-day/city-parralax-1.png", "assets/city-day/city-parralax-2.png", "assets/city-day/city-parralax-3.png", "assets/city-day/city-parralax-4.png", "assets/city-day/city-parralax-5.png", "assets/city-day/city-parralax-6.png"};
    _choices["level2Choose"] = {"assets/desert-day/desert-parralax-1.png", "assets/desert-day/desert-parralax-2.png", "assets/desert-day/desert-parralax-3.png", "assets/desert-day/desert-parralax-4.png", "assets/desert-day/desert-parralax-6.png", "assets/desert-day/desert-parralax-7.png", "assets/desert-day/desert-parralax-8.png", "assets/desert-day/desert-parralax-9.png"};
    _choices["level3Choose"] = {"assets/field-day/field-parralax-1.png", "assets/field-day/field-parralax-2.png", "assets/field-day/field-parralax-3.png", "assets/field-day/field-parralax-4.png", "assets/field-day/field-parralax-5.png", "assets/field-day/field-parralax-6.png", "assets/field-day/field-parralax-7.png", "assets/field-day/field-parralax-8.png", "assets/field-day/field-parralax-9.png", "assets/field-day/field-parralax-10.png"};
    _choices["level4Choose"] = {"assets/forest-day/forest-parralax-1.png", "assets/forest-day/forest-parralax-2.png", "assets/forest-day/forest-parralax-3.png", "assets/forest-day/forest-parralax-4.png", "assets/forest-day/forest-parralax-5.png"};
    _choices["level5Choose"] = {"assets/hills-days/hills-parralax-1.png", "assets/hills-days/hills-parralax-2.png", "assets/hills-days/hills-parralax-3.png", "assets/hills-days/hills-parralax-4.png", "assets/hills-days/hills-parralax-5.png", "assets/hills-days/hills-parralax-6.png", "assets/hills-days/hills-parralax-7.png"};
    _choices["level6Choose"] = {"assets/mysterious-forest/mysterious-parralax-1.png", "assets/mysterious-forest/mysterious-parralax-2.png", "assets/mysterious-forest/mysterious-parralax-3.png", "assets/mysterious-forest/mysterious-parralax-4.png", "assets/mysterious-forest/mysterious-parralax-5.png", "assets/mysterious-forest/mysterious-parralax-6.png"};
    _choices["level7Choose"] = {"assets/snow-day/snow-parralax-1.png", "assets/snow-day/snow-parralax-2.png", "assets/snow-day/snow-parralax-3.png", "assets/snow-day/snow-parralax-4.png", "assets/snow-day/snow-parralax-5.png", "assets/snow-day/snow-parralax-6.png", "assets/snow-day/snow-parralax-7.png", "assets/snow-day/snow-parralax-8.png", "assets/snow-day/snow-parralax-9.png"};

    std::map<std::string, std::string> _names_scenes;
    _names_scenes["level1Choose"] = "The City";
    _names_scenes["level2Choose"] = "The Desert";
    _names_scenes["level3Choose"] = "The Field";
    _names_scenes["level4Choose"] = "The Forest";
    _names_scenes["level5Choose"] = "The Hills";
    _names_scenes["level6Choose"] = "The Dark Forest";
    _names_scenes["level7Choose"] = "The Snow";

    std::map<std::string, std::string> _names_back;
    _names_back["level1Choose"] = "level7Choose";
    _names_back["level2Choose"] = "level1Choose";
    _names_back["level3Choose"] = "level2Choose";
    _names_back["level4Choose"] = "level3Choose";
    _names_back["level5Choose"] = "level4Choose";
    _names_back["level6Choose"] = "level5Choose";
    _names_back["level7Choose"] = "level6Choose";

    std::map<std::string, std::string> _names_next;
    _names_next["level1Choose"] = "level2Choose";
    _names_next["level2Choose"] = "level3Choose";
    _names_next["level3Choose"] = "level4Choose";
    _names_next["level4Choose"] = "level5Choose";
    _names_next["level5Choose"] = "level6Choose";
    _names_next["level6Choose"] = "level7Choose";
    _names_next["level7Choose"] = "level1Choose";

    std::map<std::string, std::string> _names_play;
    _names_play["level1Choose"] = "level1";
    _names_play["level2Choose"] = "level2";
    _names_play["level3Choose"] = "level3";
    _names_play["level4Choose"] = "level4";
    _names_play["level5Choose"] = "level5";
    _names_play["level6Choose"] = "level6";
    _names_play["level7Choose"] = "level7";

    for (const auto& pair : _choices) {
        const std::string& scene_name = pair.first;
        const std::vector<std::string>& paths = pair.second;

        ecs.create_scene(scene_name);

        for (auto &path : paths) {
            Entity entity = ecs.scene(scene_name)->create_entity();
            ecs.scene(scene_name)->registry->add_component(entity, Position(1920, 540));
            ecs.scene(scene_name)->registry->add_component(entity, Size(1, 1));
            ecs.scene(scene_name)->registry->add_component(entity, Drawable());
            ecs.scene(scene_name)->registry->add_component(entity, Sprite(path));
        }

        Entity txt = ecs.scene(scene_name)->create_entity();
        ecs.scene(scene_name)->registry->add_component(txt, Position(1920/2, 1080/2 - 400));
        ecs.scene(scene_name)->registry->add_component(txt, Drawable());
        ecs.scene(scene_name)->registry->add_component(txt, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", _names_scenes[scene_name], 128));
        ecs.scene(scene_name)->registry->add_component(txt, Color(COLOR_WHITE));

        Entity backArrow = ecs.scene(scene_name)->create_entity();
        ecs.scene(scene_name)->registry->add_component(backArrow, Position(1920/2 - 800, 1080/2 + 400));
        ecs.scene(scene_name)->registry->add_component(backArrow, Drawable());
        ecs.scene(scene_name)->registry->add_component(backArrow, Size(1, 1));
        ecs.scene(scene_name)->registry->add_component(backArrow, Sprite("assets/menu/BackArrow.png"));
        ecs.scene(scene_name)->registry->add_component(backArrow, OnClickLoadScene(_names_back[scene_name]));

        Entity nextArrow = ecs.scene(scene_name)->create_entity();
        ecs.scene(scene_name)->registry->add_component(nextArrow, Position(1920/2 + 800, 1080/2 + 400));
        ecs.scene(scene_name)->registry->add_component(nextArrow, Drawable());
        ecs.scene(scene_name)->registry->add_component(nextArrow, Size(1, 1));
        ecs.scene(scene_name)->registry->add_component(nextArrow, Sprite("assets/menu/RightArrow.png"));
        ecs.scene(scene_name)->registry->add_component(nextArrow, OnClickLoadScene(_names_next[scene_name]));

        Entity playButton = ecs.scene(scene_name)->create_entity();
        ecs.scene(scene_name)->registry->add_component(playButton, Position(1920/2, 1080/2 + 400));
        ecs.scene(scene_name)->registry->add_component(playButton, Drawable());
        ecs.scene(scene_name)->registry->add_component(playButton, Size(3, 3));
        ecs.scene(scene_name)->registry->add_component(playButton, Sprite("assets/menu/GreenButton.png"));
        ecs.scene(scene_name)->registry->add_component(playButton, OnClickLoadScene(_names_play[scene_name]));
        ecs.scene(scene_name)->registry->add_component(playButton, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "Play", 64));
        ecs.scene(scene_name)->registry->add_component(playButton, Color(COLOR_WHITE));
    }

    // Parralax Level 1

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
    ecs.scene("level1")->registry->add_component(backgroundCity5, Velocity(-6, 0));

    Entity ground = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(ground, Position(1920, 540));
    ecs.scene("level1")->registry->add_component(ground, Size(1, 1));
    ecs.scene("level1")->registry->add_component(ground, Drawable());
    ecs.scene("level1")->registry->add_component(ground, Sprite("assets/city-day/city-parralax-6.png"));
    ecs.scene("level1")->registry->add_component(ground, Parralax(1920, 540, 0));
    ecs.scene("level1")->registry->add_component(ground, Velocity(-6, 0));
    ecs.scene("level1")->registry->add_component(ground, BoxCollider("ground", 3840, 58, 0, 520, false, COLOR_YELLOW_128));

    ecs.create_prefab("barrel");
    ecs.add_component_to_prefab("barrel", Size(2, 2.5));
    ecs.add_component_to_prefab("barrel", Drawable());
    ecs.add_component_to_prefab("barrel", Sprite("assets/obstacle/barrel.png"));
    ecs.add_component_to_prefab("barrel", BoxCollider("obstacle", 30, 60, 0, 0, false, COLOR_GREEN_128));
    ecs.add_component_to_prefab("barrel", Velocity(-6, 0));

    ecs.create_prefab("skull");
    ecs.add_component_to_prefab("skull", Size(2, 2.5));
    ecs.add_component_to_prefab("skull", Drawable());
    ecs.add_component_to_prefab("skull", Sprite("assets/obstacle/skull.png"));
    ecs.add_component_to_prefab("skull", BoxCollider("obstacle", 30, 60, 0, 0, false, COLOR_GREEN_128));
    ecs.add_component_to_prefab("skull", Velocity(-6, 0));

    ecs.create_prefab("chest");
    ecs.add_component_to_prefab("chest", Size(2, 2.5));
    ecs.add_component_to_prefab("chest", Drawable());
    ecs.add_component_to_prefab("chest", Sprite("assets/obstacle/chest.png"));
    ecs.add_component_to_prefab("chest", BoxCollider("obstacle", 30, 60, 0, 0, false, COLOR_GREEN_128));
    ecs.add_component_to_prefab("chest", Velocity(-6, 0));

    ecs.create_prefab("palm");
    ecs.add_component_to_prefab("palm", Size(2, 2.5));
    ecs.add_component_to_prefab("palm", Drawable());
    ecs.add_component_to_prefab("palm", Sprite("assets/obstacle/palm.png"));
    ecs.add_component_to_prefab("palm", BoxCollider("obstacle", 30, 60, 0, 0, false, COLOR_GREEN_128));
    ecs.add_component_to_prefab("palm", Velocity(-6, 0));

    ecs.create_prefab("shroom");
    ecs.add_component_to_prefab("shroom", Size(2, 2.5));
    ecs.add_component_to_prefab("shroom", Drawable());
    ecs.add_component_to_prefab("shroom", Sprite("assets/obstacle/shroom.png"));
    ecs.add_component_to_prefab("shroom", BoxCollider("obstacle", 30, 60, 0, 0, false, COLOR_GREEN_128));
    ecs.add_component_to_prefab("shroom", Velocity(-6, 0));

    ecs.create_prefab("stalactite");
    ecs.add_component_to_prefab("stalactite", Size(2, 2.5));
    ecs.add_component_to_prefab("stalactite", Drawable());
    ecs.add_component_to_prefab("stalactite", Sprite("assets/obstacle/stalactite.png"));
    ecs.add_component_to_prefab("stalactite", BoxCollider("obstacle", 30, 60, 0, 0, false, COLOR_GREEN_128));
    ecs.add_component_to_prefab("stalactite", Velocity(-6, 0));

    ecs.create_prefab("rock");
    ecs.add_component_to_prefab("rock", Size(2, 2.5));
    ecs.add_component_to_prefab("rock", Drawable());
    ecs.add_component_to_prefab("rock", Sprite("assets/obstacle/rock.png"));
    ecs.add_component_to_prefab("rock", BoxCollider("obstacle", 30, 60, 0, 0, false, COLOR_GREEN_128));
    ecs.add_component_to_prefab("rock", Velocity(-6, 0));

    Entity txt = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(txt, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "PRESS [ D ] to show collisions", 32));
    ecs.scene("level1")->registry->add_component(txt, Color(COLOR_BLACK));
    ecs.scene("level1")->registry->add_component(txt, Position(1180, 20));
    ecs.scene("level1")->registry->add_component(txt, Drawable());

    Entity obstacle = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(obstacle, SpawnPrefabAtRandomPosition("barrel", 60, 1980, 2150, 1000, 1000));

    Entity player = ecs.scene("level1")->create_entity();
    ecs.scene("level1")->registry->add_component(player, Position(100, 900));
    ecs.scene("level1")->registry->add_component(player, Size(3, 3));
    ecs.scene("level1")->registry->add_component(player, Drawable());
    ecs.scene("level1")->registry->add_component(player, Sprite("assets/character/Player.png"));
    ecs.scene("level1")->registry->add_component(player, BoxCollider("player", 70, 90, 0, 6, false, COLOR_RED_128));
    ecs.scene("level1")->registry->add_component(player, OnCollideStop("ground"));
    ecs.scene("level1")->registry->add_component(player, Gravity(8));
    ecs.scene("level1")->registry->add_component(player, AddForce(-20, 200, "space"));
    ecs.scene("level1")->registry->add_component(player, ShowCollisionsWithInput("d"));
    ecs.scene("level1")->registry->add_component(player, OnCollideLoadScene("menu", "obstacle"));

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
    ecs.scene("level2")->registry->add_component(backgroundDesert7, Velocity(-6, 0));

    Entity backgroundDesert8 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Position(1920, 540));
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Size(1, 1));
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Drawable());
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Sprite("assets/desert-day/desert-parralax-8.png"));
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Parralax(1920, 540, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert8, Velocity(-6, 0));

    Entity backgroundDesert9 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Position(1920, 540));
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Size(1, 1));
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Drawable());
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Sprite("assets/desert-day/desert-parralax-9.png"));
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Parralax(1920, 540, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert9, Velocity(-6, 0));
    ecs.scene("level2")->registry->add_component(backgroundDesert9, BoxCollider("ground", 3840, 58, 0, 520, false, COLOR_YELLOW_128));

    Entity txt2 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(txt2, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "PRESS [ D ] to show collisions", 32));
    ecs.scene("level2")->registry->add_component(txt2, Color(COLOR_BLACK));
    ecs.scene("level2")->registry->add_component(txt2, Position(1180, 20));
    ecs.scene("level2")->registry->add_component(txt2, Drawable());

    Entity obstacle2 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(obstacle2, SpawnPrefabAtRandomPosition("skull", 60, 1980, 2150, 1000, 1000));

    Entity player2 = ecs.scene("level2")->create_entity();
    ecs.scene("level2")->registry->add_component(player2, Position(100, 900));
    ecs.scene("level2")->registry->add_component(player2, Size(3, 3));
    ecs.scene("level2")->registry->add_component(player2, Drawable());
    ecs.scene("level2")->registry->add_component(player2, Sprite("assets/character/Player.png"));
    ecs.scene("level2")->registry->add_component(player2, BoxCollider("player", 70, 90, 0, 6, false, COLOR_RED_128));
    ecs.scene("level2")->registry->add_component(player2, OnCollideStop("ground"));
    ecs.scene("level2")->registry->add_component(player2, Gravity(8));
    ecs.scene("level2")->registry->add_component(player2, AddForce(-20, 200, "space"));
    ecs.scene("level2")->registry->add_component(player2, ShowCollisionsWithInput("d"));
    ecs.scene("level2")->registry->add_component(player2, OnCollideLoadScene("menu", "obstacle"));

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
    ecs.scene("level3")->registry->add_component(backgroundField8, Velocity(-6, 0));

    Entity backgroundField9 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(backgroundField9, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(backgroundField9, Size(1, 1));
    ecs.scene("level3")->registry->add_component(backgroundField9, Drawable());
    ecs.scene("level3")->registry->add_component(backgroundField9, Sprite("assets/field-day/field-parralax-9.png"));
    ecs.scene("level3")->registry->add_component(backgroundField9, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(backgroundField9, Velocity(-6, 0));

    Entity ground3 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(ground3, Position(1920, 540));
    ecs.scene("level3")->registry->add_component(ground3, Size(1, 1));
    ecs.scene("level3")->registry->add_component(ground3, Drawable());
    ecs.scene("level3")->registry->add_component(ground3, Sprite("assets/field-day/field-parralax-10.png"));
    ecs.scene("level3")->registry->add_component(ground3, Parralax(1920, 540, 0));
    ecs.scene("level3")->registry->add_component(ground3, Velocity(-6, 0));
    ecs.scene("level3")->registry->add_component(ground3, BoxCollider("ground", 3840, 58, 0, 520, false, COLOR_YELLOW_128));

    Entity txt3 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(txt3, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "PRESS [ D ] to show collisions", 32));
    ecs.scene("level3")->registry->add_component(txt3, Color(COLOR_BLACK));
    ecs.scene("level3")->registry->add_component(txt3, Position(1180, 20));
    ecs.scene("level3")->registry->add_component(txt3, Drawable());

    Entity obstacle3 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(obstacle3, SpawnPrefabAtRandomPosition("rock", 60, 1980, 2150, 1000, 1000));

    Entity player3 = ecs.scene("level3")->create_entity();
    ecs.scene("level3")->registry->add_component(player3, Position(100, 900));
    ecs.scene("level3")->registry->add_component(player3, Size(3, 3));
    ecs.scene("level3")->registry->add_component(player3, Drawable());
    ecs.scene("level3")->registry->add_component(player3, Sprite("assets/character/Player.png"));
    ecs.scene("level3")->registry->add_component(player3, BoxCollider("player", 70, 90, 0, 6, false, COLOR_RED_128));
    ecs.scene("level3")->registry->add_component(player3, OnCollideStop("ground"));
    ecs.scene("level3")->registry->add_component(player3, Gravity(8));
    ecs.scene("level3")->registry->add_component(player3, AddForce(-20, 200, "space"));
    ecs.scene("level3")->registry->add_component(player3, ShowCollisionsWithInput("d"));
    ecs.scene("level3")->registry->add_component(player3, OnCollideLoadScene("menu", "obstacle"));

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
    ecs.scene("level4")->registry->add_component(backgroundForest3, Velocity(-6, 0));

    Entity backgroundForest4 = ecs.scene("level4")->create_entity();
    ecs.scene("level4")->registry->add_component(backgroundForest4, Position(1920, 540));
    ecs.scene("level4")->registry->add_component(backgroundForest4, Size(1, 1));
    ecs.scene("level4")->registry->add_component(backgroundForest4, Drawable());
    ecs.scene("level4")->registry->add_component(backgroundForest4, Sprite("assets/forest-day/forest-parralax-4.png"));
    ecs.scene("level4")->registry->add_component(backgroundForest4, Parralax(1920, 540, 0));
    ecs.scene("level4")->registry->add_component(backgroundForest4, Velocity(-6, 0));

    Entity ground4 = ecs.scene("level4")->create_entity();
    ecs.scene("level4")->registry->add_component(ground4, Position(1920, 540));
    ecs.scene("level4")->registry->add_component(ground4, Size(1, 1));
    ecs.scene("level4")->registry->add_component(ground4, Drawable());
    ecs.scene("level4")->registry->add_component(ground4, Sprite("assets/forest-day/forest-parralax-5.png"));
    ecs.scene("level4")->registry->add_component(ground4, Parralax(1920, 540, 0));
    ecs.scene("level4")->registry->add_component(ground4, Velocity(-6, 0));
    ecs.scene("level4")->registry->add_component(ground4, BoxCollider("ground", 3840, 58, 0, 520, false, COLOR_YELLOW_128));

    Entity txt4 = ecs.scene("level4")->create_entity();
    ecs.scene("level4")->registry->add_component(txt4, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "PRESS [ D ] to show collisions", 32));
    ecs.scene("level4")->registry->add_component(txt4, Color(COLOR_BLACK));
    ecs.scene("level4")->registry->add_component(txt4, Position(1180, 20));
    ecs.scene("level4")->registry->add_component(txt4, Drawable());

    Entity obstacle4 = ecs.scene("level4")->create_entity();
    ecs.scene("level4")->registry->add_component(obstacle4, SpawnPrefabAtRandomPosition("shroom", 60, 1980, 2150, 1000, 1000));

    Entity player4 = ecs.scene("level4")->create_entity();
    ecs.scene("level4")->registry->add_component(player4, Position(100, 900));
    ecs.scene("level4")->registry->add_component(player4, Size(3, 3));
    ecs.scene("level4")->registry->add_component(player4, Drawable());
    ecs.scene("level4")->registry->add_component(player4, Sprite("assets/character/Player.png"));
    ecs.scene("level4")->registry->add_component(player4, BoxCollider("player", 70, 90, 0, 6, false, COLOR_RED_128));
    ecs.scene("level4")->registry->add_component(player4, OnCollideStop("ground"));
    ecs.scene("level4")->registry->add_component(player4, Gravity(8));
    ecs.scene("level4")->registry->add_component(player4, AddForce(-20, 200, "space"));
    ecs.scene("level4")->registry->add_component(player4, ShowCollisionsWithInput("d"));
    ecs.scene("level4")->registry->add_component(player4, OnCollideLoadScene("menu", "obstacle"));

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
    ecs.scene("level5")->registry->add_component(backgroundHills5, Velocity(-6, 0));

    Entity backgroundHills6 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(backgroundHills6, Position(1920, 540));
    ecs.scene("level5")->registry->add_component(backgroundHills6, Size(1, 1));
    ecs.scene("level5")->registry->add_component(backgroundHills6, Drawable());
    ecs.scene("level5")->registry->add_component(backgroundHills6, Sprite("assets/hills-days/hills-parralax-6.png"));
    ecs.scene("level5")->registry->add_component(backgroundHills6, Parralax(1920, 540, 0));
    ecs.scene("level5")->registry->add_component(backgroundHills6, Velocity(-6, 0));

    Entity ground5 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(ground5, Position(1920, 540));
    ecs.scene("level5")->registry->add_component(ground5, Size(1, 1));
    ecs.scene("level5")->registry->add_component(ground5, Drawable());
    ecs.scene("level5")->registry->add_component(ground5, Sprite("assets/hills-days/hills-parralax-7.png"));
    ecs.scene("level5")->registry->add_component(ground5, Parralax(1920, 540, 0));
    ecs.scene("level5")->registry->add_component(ground5, Velocity(-6, 0));
    ecs.scene("level5")->registry->add_component(ground5, BoxCollider("ground", 3840, 58, 0, 520, false, COLOR_YELLOW_128));

    Entity txt5 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(txt5, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "PRESS [ D ] to show collisions", 32));
    ecs.scene("level5")->registry->add_component(txt5, Color(COLOR_BLACK));
    ecs.scene("level5")->registry->add_component(txt5, Position(1180, 20));
    ecs.scene("level5")->registry->add_component(txt5, Drawable());

    Entity obstacle5 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(obstacle5, SpawnPrefabAtRandomPosition("palm", 60, 1980, 2150, 1000, 1000));

    Entity player5 = ecs.scene("level5")->create_entity();
    ecs.scene("level5")->registry->add_component(player5, Position(100, 900));
    ecs.scene("level5")->registry->add_component(player5, Size(3, 3));
    ecs.scene("level5")->registry->add_component(player5, Drawable());
    ecs.scene("level5")->registry->add_component(player5, Sprite("assets/character/Player.png"));
    ecs.scene("level5")->registry->add_component(player5, BoxCollider("player", 70, 90, 0, 6, false, COLOR_RED_128));
    ecs.scene("level5")->registry->add_component(player5, OnCollideStop("ground"));
    ecs.scene("level5")->registry->add_component(player5, Gravity(8));
    ecs.scene("level5")->registry->add_component(player5, AddForce(-20, 200, "space"));
    ecs.scene("level5")->registry->add_component(player5, ShowCollisionsWithInput("d"));
    ecs.scene("level5")->registry->add_component(player5, OnCollideLoadScene("menu", "obstacle"));

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
    ecs.scene("level6")->registry->add_component(backgroundMysterious4, Velocity(-6, 0));

    Entity backgroundMysterious5 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Position(1920, 540));
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Size(1, 1));
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Drawable());
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Sprite("assets/mysterious-forest/mysterious-parralax-5.png"));
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Parralax(1920, 540, 0));
    ecs.scene("level6")->registry->add_component(backgroundMysterious5, Velocity(-6, 0));

    Entity backgroundMysterious6 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Position(1920, 540));
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Size(1, 1));
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Drawable());
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Sprite("assets/mysterious-forest/mysterious-parralax-6.png"));
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Parralax(1920, 540, 0));
    ecs.scene("level6")->registry->add_component(backgroundMysterious6, Velocity(-6, 0));

    Entity txt6 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(txt6, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "PRESS [ D ] to show collisions", 32));
    ecs.scene("level6")->registry->add_component(txt6, Color(COLOR_BLACK));
    ecs.scene("level6")->registry->add_component(txt6, Position(1180, 20));
    ecs.scene("level6")->registry->add_component(txt6, Drawable());

    Entity ground6 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(ground6, Position(1920, 540));
    ecs.scene("level6")->registry->add_component(ground6, Size(1, 1));
    ecs.scene("level6")->registry->add_component(ground6, Drawable());
    ecs.scene("level6")->registry->add_component(ground6, Sprite("assets/mysterious-forest/mysterious-parralax-6.png"));
    ecs.scene("level6")->registry->add_component(ground6, Parralax(1920, 540, 0));
    ecs.scene("level6")->registry->add_component(ground6, Velocity(-6, 0));
    ecs.scene("level6")->registry->add_component(ground6, BoxCollider("ground", 3840, 58, 0, 520, false,
 COLOR_YELLOW_128));

    Entity obstacle6 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(obstacle6, SpawnPrefabAtRandomPosition("chest", 60, 1980, 2150, 1000, 1000));

    Entity player6 = ecs.scene("level6")->create_entity();
    ecs.scene("level6")->registry->add_component(player6, Position(100, 900));
    ecs.scene("level6")->registry->add_component(player6, Size(3, 3));
    ecs.scene("level6")->registry->add_component(player6, Drawable());
    ecs.scene("level6")->registry->add_component(player6, Sprite("assets/character/Player.png"));
    ecs.scene("level6")->registry->add_component(player6, BoxCollider("player", 70, 90, 0, 6, false, COLOR_RED_128));
    ecs.scene("level6")->registry->add_component(player6, OnCollideStop("ground"));
    ecs.scene("level6")->registry->add_component(player6, Gravity(8));
    ecs.scene("level6")->registry->add_component(player6, AddForce(-20, 200, "space"));
    ecs.scene("level6")->registry->add_component(player6, ShowCollisionsWithInput("d"));
    ecs.scene("level6")->registry->add_component(player6, OnCollideLoadScene("menu", "obstacle"));

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
    ecs.scene("level7")->registry->add_component(backgroundSnow8, Velocity(-6, 0));

    Entity ground7 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(ground7, Position(1920, 540));
    ecs.scene("level7")->registry->add_component(ground7, Size(1, 1));
    ecs.scene("level7")->registry->add_component(ground7, Drawable());
    ecs.scene("level7")->registry->add_component(ground7, Sprite("assets/snow-day/snow-parralax-9.png"));
    ecs.scene("level7")->registry->add_component(ground7, Parralax(1920, 540, 0));
    ecs.scene("level7")->registry->add_component(ground7, Velocity(-6, 0));
    ecs.scene("level7")->registry->add_component(ground7, BoxCollider("ground", 3840, 58, 0, 520, false, COLOR_YELLOW_128));

    Entity txt7 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(txt7, Text("assets/fonts/BruceForeverRegular-X3jd2.ttf", "PRESS [ D ] to show collisions", 32));
    ecs.scene("level7")->registry->add_component(txt7, Color(COLOR_BLACK));
    ecs.scene("level7")->registry->add_component(txt7, Position(1180, 20));
    ecs.scene("level7")->registry->add_component(txt7, Drawable());

    Entity obstacle7 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(obstacle7, SpawnPrefabAtRandomPosition("stalactite", 60, 1980, 2150, 1000, 1000));

    Entity player7 = ecs.scene("level7")->create_entity();
    ecs.scene("level7")->registry->add_component(player7, Position(100, 900));
    ecs.scene("level7")->registry->add_component(player7, Size(3, 3));
    ecs.scene("level7")->registry->add_component(player7, Drawable());
    ecs.scene("level7")->registry->add_component(player7, Sprite("assets/character/Player.png"));
    ecs.scene("level7")->registry->add_component(player7, BoxCollider("player", 70, 90, 0, 6, false, COLOR_RED_128));
    ecs.scene("level7")->registry->add_component(player7, OnCollideStop("ground"));
    ecs.scene("level7")->registry->add_component(player7, Gravity(8));
    ecs.scene("level7")->registry->add_component(player7, AddForce(-20, 200, "space"));
    ecs.scene("level7")->registry->add_component(player7, ShowCollisionsWithInput("d"));
    ecs.scene("level7")->registry->add_component(player7, OnCollideLoadScene("menu", "obstacle"));

    ecs.load_scene("menu");
    ecs.update();

    return 0;
}