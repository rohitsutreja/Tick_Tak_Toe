#pragma once
#include <iostream>

void changeColor(WORD desiredColor){ 
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
} 
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
            changeColor(9);
            std::cout << 'X';
            changeColor(15);
            break;

        case Tile::ZERO:
            changeColor(FOREGROUND_GREEN);
            std::cout << 'O';
            changeColor(15);
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
