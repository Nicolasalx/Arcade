/*
** EPITECH PROJECT, 2024
** my_cpplib
** File description:
** info
*/

#include "my_log.hpp"
#include <iostream>

void my::log::info(
    const std::string &msg, [[maybe_unused]] std::source_location info)
{
    std::cerr << "\033[1;96minfo: \033[0m" << msg << '\n';
}

void my::log::warning(
    const std::string &msg, [[maybe_unused]] std::source_location info)
{
    std::cerr << "\033[1;95mwarning: \033[0m" << msg << '\n';
}

void my::log::error(
    const std::string &msg, [[maybe_unused]] std::source_location info)
{
    std::cerr << "\033[1;91merror: \033[0m" << msg << '\n';
}
