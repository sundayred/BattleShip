#include "board.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

void board::SetGrid()
{
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            PrivateBoard[r][c] = "[ ]";
        }
    }
}

void board::printGrid()
{
    // Show the current position on the board
    cout << "\n   A  B  C  D  E  F  G  H  I  J\n";

    for (int r = 0; r < ROWS; r++) {
        cout << setw(2) << r + 1;
        for (int c = 0; c < COLS; c++) {
            cout << PrivateBoard[r][c];
        }

        cout << endl;
    }
}

void board::setUserGrid()
{
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            userBoard[r][c] = "[ ]";
        }
    }
}

void board::printUserGrid()
{ 

    // Show the current position on the board
    cout << "\n   A  B  C  D  E  F  G  H  I  J\n";

    for (int r = 0; r < ROWS; r++) {
        cout << setw(2) << r + 1;
        for (int c = 0; c < COLS; c++) {
            cout << userBoard[r][c];
        }

        cout << endl;
    }
    //printGrid(); // DELETE DELETE
}

void board::shipPlacer(ship s)
{
    ships.push_back(s);
    while (true) {
        int r = rand() % 10;
        int c = rand() % 10;

        bool spotWorks = true;
        if (c + s.size < 10) {
            //Checks Right of placement
            for (int i = c; i < s.size + c; i++) { // s.size + c to run up to size of ship starting at beginning of column
                if (PrivateBoard[r][i] != "[ ]") {

                    spotWorks = false;
                    break;
                }
            }

            if (spotWorks) {
                for (int i = c; i < s.size + c; i++) {
                    PrivateBoard[r][i] = "[" + s.lable + "]"; // fill board with lable of ship
                }
                return;
            }
        }

        if (r + s.size < 10) {
            spotWorks = true;
            //Checks Below of placement
            for (int i = r; i < s.size + r; i++) { // start at row, check up to above size of ship
                if (PrivateBoard[i][c] != "[ ]") {
                    spotWorks = false;
                    break;
                }
            }

            if (spotWorks) {
                for (int i = r; i < s.size + r; i++) {
                    PrivateBoard[i][c] = "[" + s.lable + "]";
                }
                return;
            }
        }

        if (c - s.size > 0) {
            spotWorks = true;
            //Checks Left of placement
            for (int i = c - s.size + 1; i <= c; i++) { // int i = c - s.size + 1, checks at the left "beginning" placement of ship, run untilreaching column 
                if (PrivateBoard[r][i] != "[ ]") {
                    spotWorks = false;
                    break;
                }
            }

            if (spotWorks) {
                for (int i = c - s.size + 1; i <= c; i++) {
                    PrivateBoard[r][i] = "[" + s.lable + "]";
                }
                return;
            }
        }



        if (r - s.size > 0) {
            spotWorks = true;
            //Checks Above of placement
            for (int i = r - s.size + 1; i <= r; i++) {
                if (PrivateBoard[i][c] != "[ ]") {
                    spotWorks = false;
                    break;
                }
            }

            if (spotWorks) {
                for (int i = r - s.size + 1; i <= r; i++) {
                    PrivateBoard[i][c] = "[" + s.lable + "]";
                }
                return;
            }
        }
    }
}

int board::shipDetector(int r, int c, int shipCount)
{
    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    if (PrivateBoard[r][c] == "[ ]")
    {
        PrivateBoard[r][c] = "[O]";

        userBoard[r][c] = "[O]";
        //31
        SetConsoleTextAttribute(console_color, 4);

        cout << string(100, '\n');
        system("cls");
    
        cout << "\nMissed try again!The enemy is one step closer to engaging our ships!\n";

        missShips++;
    }


    else
    { //1 text is blue 2 green 3 light blue  4 red 6 gold
        int count = 0;
        for (auto i : ships) {
            string t = "[" + i.lable + "]";
            if (t == PrivateBoard[r][c]) {
                i.TakeHit();
                ships[count] = i;
                break;
            }
            count++;
        }
        
        
        PrivateBoard[r][c] = "[X]";
        shipCount++;
        userBoard[r][c] = "[X]";


        SetConsoleTextAttribute(console_color, 2);
        
    

        cout << string(100, '\n');
        system("cls");
        cout << "You struck an enemy ship!";
        cout << "\nKeep engaging the enemy!\n";
    }

    return shipCount;

}

int board::getMissShips()
{
    return missShips;
}

bool board::coordinateValidator(int r, int c)
{
    int row = r - 1;
    int col = c - int('A');
    if (PrivateBoard[row][col] == "[X]" || PrivateBoard[row][col] == "[O]")
    {
        return false;
    }

    else
    {
        return true;
    }
}