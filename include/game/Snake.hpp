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
    #include <ctime>
    #include <string>
    #include "Clock.hpp"
    #include <iostream>
    #include <cmath>
    #include <utility>

    #define PATH_IMG "./game_src/snake/"
    #define SIZE_MAP 20
    #define SIZE_BORDER 40
    #define X_POS_MAP 500
    #define Y_POS_MAP 100
    #define SIZE_SNAKE_START 4

struct Rect {
    double x = 0;
    double y = 0;
    double w = 0;
    double h = 0;
};

namespace Arc
{
    enum TypeOfTile {
        MAP,
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

    struct SnakeMoove {
        Pos pos;
        NextDirection nextDirection;
    };

    class Snake : public AGameModule
    {
        public:
            Snake();
            ~Snake() override;

            const Arc::GameData &update(const Arc::Event &event) override;

        private:
            void createText(const std::string &name, Pos pos, Color color);
            void createTile(Pos pos, Size sizeTile, TypeOfTile typeOfTile);
            void createPlayer(Pos pos, Size sizeTile, SnakeBody snakeBody);
            void createAllTexts();
            void createMap();
            Pos computeNewSizeItem();
            static Rect calculateRect(const Pos &pos, double size);
            static bool areaRectsInContact(const Rect &rect1, const Rect &rect2);
            void addElemBackSnake();
            void initHighScore();
            bool appleIsOnSnake(Pos pos);
            void createNewBoxMap(std::size_t i, size_t j, double posX, double posY);
            void putNewBoxInMap(TypeOfTile type, Pos pos);
            void isSnakeEatHimself();
            void checkLooseSnake(std::size_t i, Rect snakeHeadRect, Rect snakePartRect);
            void endTheGame();
            void checkHighScore();
            void snakeEatAFood();
            void moveNextCase();
            static double getRandomPos(double min, double max);
            void createSnake();
            void createApple();
            void switcDirEvent(const Arc::Event &event);
            void changeDirection(NextDirection nextDir);
            void animateSnakeBody();
            void setNewHighScore(std::vector<std::string> &stockLines);
            void animateHead(std::size_t index);
            void animateTail(std::size_t index);
            void animateBodyUp(std::size_t index);
            void animateBodyDown(std::size_t index);
            void animateBodyLeft(std::size_t index);
            void animateBodyRight(std::size_t index);
            void animatePartBody(std::size_t index);
            void appendScore();
            void initUsername();
            void createLeaderBoard();
            void printLeaderBoard(std::vector<std::pair<std::string, int>> &linesLexing);
            void fillLeaderBoard(std::vector<std::pair<std::string, int>> &linesLexing, std::vector<std::string> &allGame);
            void switchDirection(SnakeMoove &snakeMoove);
            void initEndGame();

            std::size_t _actualScore = SIZE_SNAKE_START;
            std::size_t _highScore = 0;
            Arc::Clock _clockMove;
            Arc::Clock _clockEvent;
            std::vector<std::string> _highScoreFromFile;
            NextDirection _direction = LEFT;
            std::vector<SnakeMoove> _snake;
            bool _hasInitDir = false;
    };
}

#endif /* !SNAKE_HPP_ */
