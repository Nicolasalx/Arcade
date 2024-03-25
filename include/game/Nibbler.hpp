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

    #define PATH_IMG "./game_src/snake/"
    #define SIZE_MAP 20
    #define SIZE_BORDER 40
    #define X_POS_MAP 500
    #define Y_POS_MAP 170
    #define SIZE_SNAKE_START 4
    #define NB_ITEM 10
    #define TIME_IN_MILI 20000

struct Rect {
    double x = 0;
    double y = 0;
    double w = 0;
    double h = 0;
};

namespace Arc
{
    enum TypeOfTile {
        WALL,
        FLOOR,
        SNAKE,
        TIME_BAR
    };
    struct BoxMap {
        TypeOfTile type;
        Pos posScreen;
        Pos posArray;
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

    class Nibbler : public AGameModule
    {
        public:
            Nibbler();
            ~Nibbler() override;

            const Arc::GameData &update(const Arc::Event &event) override;

        private:
            void createText(const std::string &name, Pos pos, Color color);
            void createTile(Pos pos, Size sizeTile, TypeOfTile typeOfTile);
            void createPlayer(Pos pos, Size sizeTile, SnakeBody snakeBody);
            void createAllTexts();
            void createMap();
            static Rect calculateRect(const Pos &pos, double size);
            static bool areaRectsInContact(const Rect &rect1, const Rect &rect2);
            void addElemBackSnake();
            void initHighScore();
            void putNewBoxInMap(TypeOfTile type, Pos pos);
            void isSnakeEatHimself();
            static bool checkWall(Arc::Tile &part, Rect snakePartRect, Rect appleRect);
            void updateTimeBar();
            bool appleIsOnApple(Rect appleRect, Rect snakePartRect);
            Arc::Pos computeNewSizeItem();
            bool appleIsOnSnake(Pos pos);
            void chooseBoxType(std::size_t i, size_t j, Pos posScreen);
            void endTheGame();
            void checkHighScore();
            void snakeEatAFood();
            void moveNextCase();
            static double getRandomPos(double min, double max);
            void createApple();
            void switchDirEvent(const Arc::Event &event);
            void changeDirection(NextDirection nextDir);
            void increaseNibbler(std::size_t i, Rect snakeHeadRect, Pos tail);
            void animateSnakeBody();
            void checkLoose(std::size_t i, Rect snakeHeadRect, Rect snakePartRect);
            void animateHead(std::size_t index);
            void animateTail(std::size_t index);
            void animateBodyUp(std::size_t index);
            void animateBodyDown(std::size_t index);
            void animateBodyLeft(std::size_t index);
            void animateBodyRight(std::size_t index);
            void animatePartBody(std::size_t index);

            void createTextEnd();
            void highScoreAtEnd();

            void initUsername();

            void createNewBoxMap(TypeOfTile type, Pos posScreen);
            void initEndGame();

            static int getRandomPosToInt(int min, int max);
            void createLeaderBoard();
            void printLeaderBoard(std::vector<std::pair<std::string, int>> &linesLexing);
            void fillLeaderBoard(std::vector<std::pair<std::string, int>> &linesLexing, std::vector<std::string> &allGame);

            void appendScore();

            void mooveUp(SnakeMoove &snakeMoove);
            void mooveDown(SnakeMoove &snakeMoove);
            void mooveLeft(SnakeMoove &snakeMoove);
            void mooveRight(SnakeMoove &snakeMoove);

            void automaticMooveVertical(SnakeMoove &snakeMoove);
            void automaticMooveHorizontal(SnakeMoove &snakeMoove);
            void setNewHighScore(std::vector<std::string> &stockLines, std::string &line);

            void switchDirection(SnakeMoove &snakeMoove);

            std::size_t _actualScore = SIZE_SNAKE_START;
            std::size_t _highScore = 0;
            Arc::Clock _clockMove;
            Arc::Clock _clockEvent;
            Arc::Clock _clockGame;
            std::vector<std::string> _highScoreFromFile;
            NextDirection _direction;
            std::vector<SnakeMoove> _snake;
            std::vector<std::vector<char>> _mapArray;
            Pos _headSnake;
            bool _hasMoved;
            bool _hasInitDir;
            std::size_t _nbApple = 0;
    };
}

#endif /* !SNAKE_HPP_ */
