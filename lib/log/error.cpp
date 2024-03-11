/*
** EPITECH PROJECT, 2024
** my_cpplib
** File description:
** err
*/

#include "my_log.hpp"
#include <iostream>

#ifdef MY_DEBUG

void my::log::error(const std::string &msg, std::source_location info)
{
    std::cerr << std::format("\033[1m{}:\033[96m{}\033[0;1m: "
        "\033[91merror: \033[0m{}\n", info.file_name(), info.line(), msg);
}

#else

void my::log::error(
    const std::string &msg, [[maybe_unused]] std::source_location info)
{
    std::cerr << "\033[1;91merror: \033[0m" << msg << '\n';
}

#endif
