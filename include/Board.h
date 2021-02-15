#pragma once

#include <vector>
#include <queue>
#include <map>

namespace snake
{
    enum class Cell
    {
        X,
        Food,
        Empty
    };

    enum class Direction
    {
        Up,
        Down,
        Left,
        Rigth
    };

    struct Coordinate
    {
        Coordinate(size_t x_, size_t y_) : x(x_), y(y_) {}
        size_t x, y;
    };

    class Board
    {
    private:
        std::vector<std::vector<Cell>> board;
        std::deque<Coordinate> snake;

        size_t height;
        size_t width;

        const std::map<Cell, char> symbols{{Cell::X, 'X'},
                                           {Cell::Food, 'F'},
                                           {Cell::Empty, '.'}};

        void generate_food();

    public:
        Board(size_t height_, size_t width_, Coordinate &head_);

        ~Board();

        bool can_move(Direction &dir) const;

        void move(Direction &dir);

        void draw() const;
    };
} // namespace snake
