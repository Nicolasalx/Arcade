/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_

    #include "AGameModule.hpp"
    #include "Pos.hpp"
    #include <vector>
    #include <cstdlib>
    #include <ctime>
    #include <string>

    #define PATH_IMG "./game_src/snake/"

namespace Arc
{
    class Snake : public AGameModule
    {
        enum typeOfTile {
            SNAKE,
            MAP,
            FOOD
        };
        public:
            Snake();
            ~Snake();

            void init();
            const Arc::GameData &update(const Arc::Event &event);
            void stop();

        private:
            void createText(const std::string &name, Pos pos);
            void createTile(Pos pos, Size sizeTile, typeOfTile typeOfTile);
            void createPlayer(Pos pos, Size sizeTile, char character);
            void moveSnakeLeft();
            void moveSnakeRight();
            void endTheGame();
            void displayScreenEnd();
            void checkHighScore();
            void isSnakeFillingAllTheMap();
            void snakeEatAFood();
            void moveNextCase();

            std::vector<Arc::Tile> _map;
            std::vector<Arc::Tile> _snake;
            Arc::Tile _food;
            std::size_t _actualScore = 4;
            std::size_t _highScore = 0;
    };
}

#endif /* !SNAKE_HPP_ */
