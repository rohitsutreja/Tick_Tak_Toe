#pragma once

#include "Tile.h"
class Board
{

    Tile state[3][3]{
        {Tile{Tile::EMPTY}, Tile{Tile::EMPTY}, Tile{Tile::EMPTY}},
        {Tile{Tile::EMPTY}, Tile{Tile::EMPTY}, Tile{Tile::EMPTY}},
        {Tile{Tile::EMPTY}, Tile{Tile::EMPTY}, Tile{Tile::EMPTY}}};

public:
    Tile &getTile(int i, int j)
    {
        return state[i][j];
    }
    void print()
    {
        std::cout << '\n';
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                state[i][j].print();
                if (j == 0 || j == 1)
                {
                    std::cout << " | ";
                }
            }
            if (i == 0 || i == 1)
            {
                std::cout << "\n---------\n";
            }
            else
            {
                std::cout << '\n';
            }
        }
    }

    bool isOver()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (state[i][j].getState() == Tile::EMPTY)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isWinningPosition()
    {
        for (int i = 0; i < 3; i++)
        {
            if (isRowComplete(i, Tile::CROSS) || isRowComplete(i, Tile::ZERO))
                return true;
        }
        for (int j = 0; j < 3; j++)
        {
            if (isColumnComplete(j, Tile::CROSS) || isColumnComplete(j, Tile::ZERO))
                return true;
        }
        if (isFirstDigonalComplete(Tile::CROSS) || isFirstDigonalComplete(Tile::ZERO))
            return true;
        if (isSecondDigonalComplete(Tile::CROSS) || isFirstDigonalComplete(Tile::ZERO))
            return true;

        return false;
    }

    bool isColumnComplete(int j, Tile::Symbol s)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (state[i][j].getState() != s)
            {
                return false;
            }
        }
        return true;
    }

    bool isRowComplete(int i, Tile::Symbol s)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (state[i][j].getState() != s)
            {
                return false;
            }
        }
        return true;
    }

    bool isFirstDigonalComplete(Tile::Symbol s)
    {
        if (state[0][0].getState() == s && state[1][1].getState() == s && state[2][2].getState() == s)
            return true;
        return false;
    }

    bool isSecondDigonalComplete(Tile::Symbol s)
    {
        if (state[0][2].getState() == s && state[1][1].getState() == s && state[2][0].getState() == s)
            return true;
        return false;
    }
};
