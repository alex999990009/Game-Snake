#include "GameController.h"

#include <unistd.h>
#include <ncurses.h>

namespace snake
{
    GameController::GameController(Board &board_) : board(board_) {}

    void GameController::run_game()
    {
        while (true)
        {
            board.draw();
            handle_move();
            if (board.can_move(dir))
            {
                board.move(dir);
            }
            else
            {
                printw("Thank you for game. Good buy!\n");
                halfdelay(10);
                getch();
                break;
            }
        }
    }

    void GameController::handle_move()
    {
        halfdelay(2);
        switch (getch())
        {
        case KEY_UP:
            if (dir != Direction::Down)
            {
                dir = Direction::Up;
            }
            break;
        case KEY_DOWN:
            if (dir != Direction::Up)
            {
                dir = Direction::Down;
            }
            break;
        case KEY_LEFT:
            if (dir != Direction::Rigth)
            {
                dir = Direction::Left;
            }
            break;
        case KEY_RIGHT:
            if (dir != Direction::Left)
            {
                dir = Direction::Rigth;
            }
            break;
        }
    }
} // namespace snake