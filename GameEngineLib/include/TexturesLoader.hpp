/*
** EPITECH PROJECT, 2024
** TexturesLoader.hpp
** File description:
** TexturesLoader
*/

/**
 * @file TexturesLoader.hpp
 * @brief This file contains the declaration of the `TextureLoader` class.
 */

#ifndef TEXTURESLOADER_HPP_
    #define TEXTURESLOADER_HPP_
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <memory>

    class TexturesLoader {
        public:
            TexturesLoader();
            ~TexturesLoader();
            std::shared_ptr<sf::Texture> get_texture(std::string texture_path) {
                return textures[texture_path];
            }
            std::shared_ptr<sf::Font> get_font(std::string font_path) {
                return fonts[font_path];
            }
            void set_texture(std::string texture_path) {
                std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
                if (!texture->loadFromFile(texture_path)) {
                    std::cout << "Error: could not load texture " << texture_path << std::endl;
                }
                textures[texture_path] = texture;
            }
            void set_font(std::string font_path) {
                std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
                if (!font->loadFromFile(font_path)) {
                    std::cout << "Error: could not load font " << font_path << std::endl;
                }
                fonts[font_path] = font;
            }
            std::map<std::string, std::shared_ptr<sf::Texture>> textures;
            std::map<std::string, std::shared_ptr<sf::Font>> fonts;
    };


    extern TexturesLoader texturesLoader;

#endif /* !TEXTURESLOADER_HPP_ */
