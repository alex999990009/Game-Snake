#include "GameController.h"

int main()
{
    size_t height = 10;
    size_t width = 10;
    snake::Coordinate head(0, 0);

    snake::Board board(height, width, head);

    snake::GameController gameController(board);
    gameController.run_game();

    return 0;
}