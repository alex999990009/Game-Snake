#pragma once

#include "Board.h"

namespace snake
{
    class GameController
    {
    private:
        Board board;
        Direction dir = Direction::Rigth;

    public:
        GameController(Board &board);

        void run_game();

        void handle_move();
    };
} // namespace snake
