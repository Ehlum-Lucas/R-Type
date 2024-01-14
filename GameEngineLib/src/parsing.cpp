/*
** EPITECH PROJECT, 2024
** parsing.cpp
** File description:
** parsing
*/

#include "parsing.hpp"

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

    // while (afterComma.length() > 1 && afterComma.back() == '0') {
    //     afterComma.pop_back();
    // }

    while (beforeComma.length() < 7) {
        beforeComma = "0" + beforeComma;
    }

    while (afterComma.length() < 7) {
        afterComma += "0";
    }

}

void set_size_string_to(std::string &str, std::size_t size) {
    while (str.length() < size) {
        str = "0" + str;
    }
}
