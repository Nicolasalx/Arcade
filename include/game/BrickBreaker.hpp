/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** BrickBreaker
*/

#ifndef BRICKBREAKER_HPP_
    #define BRICKBREAKER_HPP_

    #include <iostream>
    #include <string>
    #include "AGameModule.hpp"
    #include "Clock.hpp"

    #define BOX_WIDTH_MAP 25
    #define BOX_HEIGHT_MAP 15
    #define SIZE_BORDER 40

    #define BALL_RADIUS 10

    #define X_POS_MAP 700
    #define Y_POS_MAP 100

    #define PATH_IMG "./game_src/brickBreaker/"

struct Rect {
    double x = 0;
    double y = 0;
    double w = 0;
    double h = 0;
};

struct Velocity {
    double x;
    double y;
};

namespace Arc {
    class BrickBreaker : public AGameModule
    {
        public:
            enum TypeOfContact {
                HORIZONTAL,
                VERTICAL,
                NONE
            };

            enum TypeOfContactPlayer {
                LEFT,
                MIDDLE,
                RIGHT,
                NON
            };

            enum ColorBrick {
                BLUE,
                GREEN,
                PURPLE,
                RED,
                YELLOW
            };

            BrickBreaker();
            ~BrickBreaker() override;

            const Arc::GameData &update(const Arc::Event &event) override;

        private:
            // Creation
            void createMap();
            void createBrick(ColorBrick color);
            void createWall();
            void createPlayer();
            void createBall();
            void chooseElemCreate(char c);
            void initBricks();
            static void createBrickBlue(Tile &tile);
            static void createBrickColorGreen(Tile &tile);
            static void createBrickColorPurple(Tile &tile);
            static void createBrickColorRed(Tile &tile);
            static void createBrickColorYellow(Tile &tile);
            void createEachElemMap(std::size_t &indexPlayer, std::size_t i, std::size_t j);
            void createLifeGame();

            // Update
            void switchDirEvent(const Arc::Event &event);

            // Moove Player
            void moovePlayerLeft();
            void moovePlayerRight();

            void mooveRight();
            void mooveLeft();

            // Moove Ball
            void mooveBall();
            void contactWithBrick(Rect ballRect, Rect partRect);
            void contactWithWall(Rect ballRect, Rect partRect);
            void contactWithPlayer(Rect ballRect, Rect partRect);
            void mooveNextPoint();

            // End Game
            void checkEndGame();
            void initEndGame();

            // Interaction Rect
            TypeOfContactPlayer areaRectsInContact(const Rect &rect1, const Rect &rect2);
            static Rect calculateRect(const Pos &pos, double size);
            TypeOfContact areaRectsWithContactType(const Rect &rect1, const Rect &rect2);

            // Random Pos
            static double getRandomPos(double min, double max);
            static int getRandomPosToInt(int min, int max);

            // Loose One Life
            void playerLooseOneLife();

            // Create Text
            void createAllTexts();
            void createText(const std::string &name, Pos pos, Color color);

            // Handle Username
            void initUsername();

            // Handle HighScore
            void initHighScore();
            void setNewHighScore(std::vector<std::string> &stockLines);
            void checkHighScore();
            void appendScore();
            void checkPlayerWin();

            // Handle LeaderBoard
            void createLeaderBoard();
            void printLeaderBoard(std::vector<std::pair<std::string, int>> &linesLexing);
            void fillLeaderBoard(std::vector<std::pair<std::string, int>> &linesLexing, std::vector<std::string> &allGame);

            // Update Text
            void updateText();

            Arc::Clock _clockGame;
            std::vector<std::vector<char>> _mapArray;
            Velocity _velocity;
            Pos _iniPosBall;
            std::size_t _highScore = 0;
            Pos _posScreen;
            std::size_t _actualScore = 0;
            Arc::Clock _clockMove;
            Arc::Clock _clockEvent;

            bool _rightMoove = false;
            bool _leftMoove = false;
            int _posRightStock = 0;
            int _posLeftStock = 0;
    };
}

#endif /* !BRICKBREAKER_HPP_ */
