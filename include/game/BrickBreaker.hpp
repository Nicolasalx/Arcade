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
            void createBrick(Pos pos, ColorBrick color);
            void createWall(Pos pos);
            void createPlayer(Pos pos);
            void createBall(Pos pos);
            void chooseElemCreate(char c, Pos pos);

            // Update
            void switchDirEvent(const Arc::Event &event);

            // Moove Player
            void moovePlayerLeft();
            void moovePlayerRight();

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
            static bool areaRectsInContact(const Rect &rect1, const Rect &rect2);
            static Rect calculateRect(const Pos &pos, double size);
            static TypeOfContact areaRectsWithContactType(const Rect &rect1, const Rect &rect2);

            // Random Pos
            double getRandomPos(double min, double max);

            Arc::Clock _clockGame;
            std::vector<std::vector<char>> _mapArray;
            Velocity _velocity;
    };
}

#endif /* !BRICKBREAKER_HPP_ */
