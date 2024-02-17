#include "Board.h"

class Game
{
    Board b{};
    int currentPlayer{1};
    int currentRow{0};
    int currentColumn{0};
    std::string p1;
    std::string p2;
    int turnCount{0};

public:
    Game()
    {
    }

    void getUserInput()
    {
        while (1)
        {
            std::cout << "--------------------------------- " << ((currentPlayer == 1) ? p1 : p2) << "'s turn. ---------------------------------\n";
            std::cout << "Please enter row: ";
            std::cin >> currentRow;
            if (currentRow <= 0 || currentRow > 3)
            {
                std::cout << "Please Enter Valid Row\n";
                continue;
            }
            std::cout << "Please enter column: ";
            std::cin >> currentColumn;

            if (currentColumn <= 0 || currentColumn > 3)
            {
                std::cout << "Please Enter Valid Column\n";
                continue;
            }
            break;
        }
    }

    void getPlayerNames(){
        std::string p1;
        std::string p2;

        std::cout << "Player 1, Enter Your Name: ";
        std::cin >> p1;
        this->p1 = p1;
        std::cout << "Player 2, Enter Your Name: ";
        std::cin >> p2;
        this->p2 = p2;

    }

    void start()
    {
        std::cout << "\n --------------------------------- WELCOME --------------------------------- \n";

        getPlayerNames();

        while (1)
        {

            if (b.isWinningPosition())
            {   
                b.print();
                std::cout << "Hurrayy!!! Congratulations, " << (currentPlayer == 1 ? p2 : p1) << ". You Won !!\n";
                break;
            }

            if (turnCount == 9)
            {
                b.print();
                std::cout << "\nIt's a DRAW!! \n";
                break;
            }

            b.print();

            getUserInput();

            if (b.getTile(currentRow - 1, currentColumn - 1).getState() == Tile::EMPTY)
            {
                b.getTile(currentRow - 1, currentColumn - 1) = (currentPlayer == 1 ? Tile::CROSS : Tile::ZERO);
                turnCount++;
                currentPlayer = currentPlayer == 1 ? 2 : 1;
                continue;
            }
            else
            {
                std::cout << "Invalid: Please choose empty slot\n";
                getUserInput();
            }
        }
    }
};