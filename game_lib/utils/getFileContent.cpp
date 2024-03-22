/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** getFileContent
*/

#include "getFileContent.hpp"
#include "my_tracked_exception.hpp"

std::vector<std::string> Arc::FileContent::getContent(const std::string &filename)
{
    std::ifstream inFile;
    std::string line;
    std::vector<std::string> tokensByLine;

    if (std::filesystem::is_directory(filename)) {
        throw my::tracked_exception("The provided file is a directory.");
    }
    inFile.open(filename);
    if (!inFile) {
        throw my::tracked_exception("Invalid file name");
    }
    while (std::getline(inFile, line)) {
        tokensByLine.push_back(line);
    }
    inFile.close();
    return tokensByLine;
}

std::vector<std::vector<char>> Arc::FileContent::getArrayFromContent(const std::string &filename)
{
    std::ifstream inFile;
    std::string line;
    std::vector<std::vector<char>> tokensByLine;
    std::vector<char> elemLines;

    if (std::filesystem::is_directory(filename)) {
        throw my::tracked_exception("The provided file is a directory.");
    }
    inFile.open(filename);
    if (!inFile) {
        throw my::tracked_exception("Invalid file name");
    }
    while (std::getline(inFile, line)) {
        elemLines.clear();
        for (const auto &info : line) {
            elemLines.push_back(info);
        }
        tokensByLine.push_back(elemLines);
    }
    inFile.close();
    return tokensByLine;
}

void Arc::FileContent::printContentToFile(const std::string &filename, const std::string &content)
{
    std::ofstream myFile(filename, std::ios::app);

    myFile << content;
    myFile.close();
}
