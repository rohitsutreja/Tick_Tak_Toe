#pragma once
#include <iostream>
class Tile
{
public:
    enum Symbol : char
    {
        CROSS = 'X',
        ZERO = 'O',
        EMPTY = ' '
    };

    Tile(Symbol s) : state{s} {}

    void cross()
    {
        state = CROSS;
    }

    void zero()
    {
        state = ZERO;
    }

    void reset()
    {
        state = EMPTY;
    }

    Symbol getState()
    {
        return state;
    }

    void print()
    {
        switch (state)
        {
        case Tile::CROSS:
            std::cout << 'X';
            break;
        case Tile::ZERO:
            std::cout << 'O';
            break;
        case Tile::EMPTY:
            std::cout << ' ';
            break;
        default:
            break;
        }
    }

private:
    Symbol state{EMPTY};
};
