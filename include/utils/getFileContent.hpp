/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** getFileContent
*/

#ifndef GETFILECONTENT_HPP_
    #define GETFILECONTENT_HPP_

    #include <string>
    #include <vector>
    #include <fstream>
    #include <filesystem>

namespace Arc
{
    class FileContent
    {
        public:
            static std::vector<std::string> getContent(const std::string &filename);
            static void appendContentToFile(const std::string &filename, const std::string &content);
            static void truncContentToFile(const std::string &filename, const std::string &content);
            static std::vector<std::vector<char>> getArrayFromContent(const std::string &filename);
        private:
    };
}

#endif /* !GETFILECONTENT_HPP_ */
