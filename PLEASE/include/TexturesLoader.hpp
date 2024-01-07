/*
** EPITECH PROJECT, 2024
** TexturesLoader.hpp
** File description:
** TexturesLoader
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
            sf::Texture get_texture(std::string texture_path) {
                std::cout << "GETTING TEXTURE " << texture_path << std::endl;

                std::cout << "TEXTURES:" << std::endl;
                for (auto it = textures.begin(); it != textures.end(); ++it) {
                    std::cout << "texture " << it->first << std::endl;
                }
                return *textures[texture_path].get();
            }
            void set_texture(std::string texture_path) {
                std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
                if (!texture->loadFromFile(texture_path)) {
                    std::cout << "Error: could not load texture " << texture_path << std::endl;
                }
                textures[texture_path] = texture;
            }
            std::map<std::string, std::shared_ptr<sf::Texture>> textures;
    };

    extern TexturesLoader texturesLoader;

#endif /* !TEXTURESLOADER_HPP_ */
