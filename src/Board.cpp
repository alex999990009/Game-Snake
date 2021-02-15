#include "Board.h"

#include <ncurses.h>

#include <random>
#include <ctime>

namespace snake
{
    Board::Board(size_t height_, size_t width_, Coordinate &head_) : height(height_), width(width_)
    {
        initscr();
        curs_set(0);
        keypad(stdscr, true);

        snake.push_front(head_);
        board.resize(height, std::vector<Cell>(width, Cell::Empty));
        board[head_.x][head_.y] = Cell::X;
        generate_food();
        generate_food();
    }

    Board::~Board()
    {
        endwin();
    }

    void Board::generate_food()
    {
        while (true)
        {
            std::mt19937 gen;
            gen.seed(time(0));
            size_t food_x = gen() % height;
            size_t food_y = gen() % width;
            if (board[food_x][food_y] == Cell::Empty)
            {
                board[food_x][food_y] = Cell::Food;
                break;
            }
        }
    }

    bool Board::can_move(Direction &dir) const
    {
        Coordinate head = snake.front();
        size_t x = head.x;
        size_t y = head.y;

        if (dir == Direction::Up)
        {
            if (x == 0)
            {
                return false;
            }
            if (board[x - 1][y] == Cell::X)
            {
                return false;
            }
            return true;
        }

        if (dir == Direction::Down)
        {
            if (x == height - 1)
            {
                return false;
            }
            if (board[x + 1][y] == Cell::X)
            {
                return false;
            }
            return true;
        }

        if (dir == Direction::Left)
        {
            if (y == 0)
            {
                return false;
            }
            if (board[x][y - 1] == Cell::X)
            {
                return false;
            }
            return true;
        }

        // Direction::Right
        if (y == width - 1)
        {
            return false;
        }
        if (board[x][y + 1] == Cell::X)
        {
            return false;
        }
        return true;
    }

    void Board::move(Direction &dir)
    {
        Coordinate head = snake.front();
        size_t x = head.x;
        size_t y = head.y;

        size_t new_x = 0;
        size_t new_y = 0;

        if (dir == Direction::Up)
        {
            new_x = x - 1;
            new_y = y;
        }
        if (dir == Direction::Down)
        {
            new_x = x + 1;
            new_y = y;
        }
        if (dir == Direction::Left)
        {
            new_x = x;
            new_y = y - 1;
        }
        if (dir == Direction::Rigth)
        {
            new_x = x;
            new_y = y + 1;
        }

        if (board[new_x][new_y] != Cell::Food)
        {
            Coordinate tail = snake.back();
            board[tail.x][tail.y] = Cell::Empty;
            snake.pop_back();
        }
        else
        {
            generate_food();
        }

        snake.push_front(Coordinate(new_x, new_y));
        board[new_x][new_y] = Cell::X;
    }

    void Board::draw() const
    {
        clear();
        for (size_t i = 0; i < height; ++i)
        {
            for (size_t j = 0; j < width; ++j)
            {
                addch(symbols.at(board[i][j]));
                addch(' ');
            }
            printw("\n");
        }
        refresh();
    }
} // namespace snake