/*
** EPITECH PROJECT, 2024
** parsing.cpp
** File description:
** parsing
*/

/**
 * @file parsing.cpp
 * @brief This file contains the implementation of the `parsing` functions.
 */

#include "parsing.hpp"

/**
 * The function separates a string into two parts, before and after a comma, and pads each part with
 * zeros to a length of 7 characters.
 * 
 * @param input The input parameter is a constant reference to a std::string, which means it cannot be
 * modified within the function. It represents the input string that needs to be separated.
 * @param beforeComma The `beforeComma` parameter is a reference to a `std::string` variable that will
 * store the substring of `input` before the comma (or period) character.
 * @param afterComma The `afterComma` parameter is a reference to a `std::string` variable. It is used
 * to store the substring of `input` that comes after the comma (if any).
 */

void separateString(const std::string& input, std::string& beforeComma, std::string& afterComma) {
    size_t commaPos = input.find('.');
    beforeComma = "";
    afterComma = "";
    if (commaPos != std::string::npos) {
        beforeComma = input.substr(0, commaPos);
        afterComma = input.substr(commaPos + 1);
    } else {
        beforeComma = input;
        afterComma = "";
    }

    while (beforeComma.length() < 7) {
        beforeComma = "0" + beforeComma;
    }

    while (afterComma.length() < 7) {
        afterComma += "0";
    }

}

/**
 * The function sets the size of a string by adding leading zeros until it reaches the desired size.
 * 
 * @param str The parameter `str` is a reference to a `std::string` object.
 * @param size The "size" parameter is of type std::size_t, which is an unsigned integer type used to
 * represent the size of objects in memory. In this context, it represents the desired size of the
 * string "str".
 */

void set_size_string_to(std::string &str, std::size_t size) {
    while (str.length() < size) {
        str = "0" + str;
    }
}
