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
    #include "Clock.hpp"

    #define PATH_IMG "./game_src/snake/"
    #define SIZE_MAP 20
    #define SIZE_BORDER 40
    #define X_POS_MAP 500
    #define Y_POS_MAP 100
    #define SIZE_SNAKE_START 4

namespace Arc
{
    enum TypeOfTile {
        MAP,
        FOOD,
        FLOOR
    };
    struct BoxMap {
        TypeOfTile type;
        Pos pos;
    };
    enum SnakeBody {
        SNAKE_HEAD,
        SNAKE_BODY,
        SNAKE_TAIL
    };
    enum NextDirection {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    struct SnakeMove {
        SnakeBody snakeBody;
        NextDirection nextDirection;
        Pos pos;
        Pos nextPos;
        //bool has
    };
    class Snake : public AGameModule
    {
        public:
            Snake();
            ~Snake();

            void init();
            const Arc::GameData &update(const Arc::Event &event);
            void stop();

        private:
            void createText(const std::string &name, Pos pos);
            void createTile(Pos pos, Size sizeTile, TypeOfTile typeOfTile);
            void createPlayer(Pos pos, Size sizeTile, SnakeBody snakeBody);
            void moveSnakeLeft();
            void moveSnakeRight();
            void endTheGame();
            void displayScreenEnd();
            void checkHighScore();
            void isSnakeFillingAllTheMap();
            void snakeEatAFood();
            void moveNextCase();
            void putNewBoxInMap(TypeOfTile type, Pos pos, std::vector<BoxMap> &tmpBox);
            double getRandomPos(double min, double max);
            Pos findBoxPos(std::size_t idxSearch);
            void createSnake();
            void createApple();
            void moveSnakeUp();
            void moveSnakeDown();

            std::vector<std::vector<BoxMap>> _map;
            std::vector<SnakeMove> _snakeMove;

            std::size_t _actualScore = SIZE_SNAKE_START;
            std::size_t _highScore = 0;

            Arc::Clock _clockMove;
            bool _directionHasChanged = false;
    };
}

#endif /* !SNAKE_HPP_ */
