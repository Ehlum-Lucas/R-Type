/*
** EPITECH PROJECT, 2023
** GameEngine.hpp
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
    #define GAMEENGINE_HPP_
    #include "Systems.hpp"

    class GameEngine {
        public:
            GameEngine(std::string const &title, std::string const &mode, int framerate, bool fullscreen, int width = 800, int height = 800);
            ~GameEngine();

            void update();

            std::shared_ptr<Registry> registry;
        private:
    };

#endif /* !GAMEENGINE_HPP_ */
