#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <cctype> 
#include "board.h"
#include <windows.h>
using namespace std;

// Wooyong Yang 

int main() {

    board bsObj;

    bsObj.SetGrid();
    bsObj.setUserGrid();


    ship frigate(2, "Frigate", 'F');

    ship destroyer(3, "Destroyer", 'D');

    ship submarine(3, "Submarine", 'S');

    ship battleShip(4, "Battleship", 'B');

    ship aircraftCarrier(5, "Aircraft Carrier", 'A');
    

    ship array[5] = { frigate, destroyer, submarine, battleShip, aircraftCarrier };

    // allows program to continuously generate random numbers, otherwise will only repeat same randonly generated number
    srand((unsigned)time(NULL));

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        bsObj.shipPlacer(array[i]);
        // bsObj.printGrid(); //runs print multiple times to show each print
    }

    
    
    //cout << system("cls");
    cout << "                         ***** WELCOME TO BATTLESHIP *****\n\n" << endl;

    cout <<
"                                     |__                                       \n"
"                                     |\/                                       \n"
"                                     -- -                                      \n" 
"                                     / |[                                      \n"
"                              !      | |||                                     \n"
"                            _/|     _/|-++'                                    \n"
"                        +  +--|    |--|--|_ |-                                 \n"
"                     { /|__|  |/\__|  |--- |||__/                              \n"
"                    +---------------___[}-_===_.'____               /\         \n"
"                ____`-' ||___-{]_| _[}-  |     |_[___\==--          \/   _     \n"
" __..._____--==/___]_|__|_____________________________[___\==--___,-----' .7   \n"
"|                                                                   BB-61/     \n"
" \_______________________________________________________________________|     \n"
"  Credit to Matthew Bace  \n\n" << endl;

    cout << "\nDive into the thrilling world of Battleship, where strategy and intuition collide on the high seas! " << endl
         << "You'll take command of your fleet and engage in a tactical showdown against your opponent. Can you out" << endl
         << "smart them and sink their ships before they sink yours? " << endl

        << "\nThe enemies ships are placed on a hidden grid, plotting to destroy your fleet. Each turn, you'll " << endl
        << "call out coordinates to target your enemy’s vessels, and you must destroy the enemy within 17 turns! " << endl
        << "With every hit marked as X and miss as O, the tension mounts, and the excitement builds!" << endl
        << "I must warn you, you musn't miss the enemy's vessles more than 15 times. So best of luck!" << endl

        << "\nWhether you're a seasoned captain or a first-time sailor, Battleship offers endless fun and suspense." << endl
        << "Gather your crew, prepare for battle, and may the best strategist win! Are you ready to claim victory o" 
        << "n " "\nthe open waters ? Let the games begin!\n\n\n\n";
    system("pause");
    system("cls");

    bsObj.printUserGrid();

    int userRow = 0;
    char userCol = 'A';
    int numUserCol = 0;
    int shipHitCount = 0;
    int totalShipCount = 17;

    for (int i = 1; i < 18; i++)
    {
        cout << "\nEnter coordinate to attack, ";
        cout << "(input first column, then row, Z to exit): ";
        cin >> userCol;

        userCol = toupper(userCol);

        if (userCol == 'Z')
        {
            cout << "\nYou have ended the game!";
            cout << "\n\nHave a good day!";
            return 0;
        }

        cin >> userRow;

        // user validation
        bool validation = false;
        while (validation == false)
        {
            
            // if user coordiantes are out of bounds of 
            while (userCol < 'A' || userCol > 'J' || userRow < 1 || userRow > 10)
            {
                cout << "\nPlease enter coordinates within A-J and 1-10: ";
                cout << "(input first column, then row, Z to exit): ";
                cin >> userCol;

                userCol = toupper(userCol);

                if (userCol == 'Z')
                {
                    cout << "\nYou have ended the game!";
                    cout << "\n\nHave a good day!";
                    return 0;
                }
                cin >> userRow;
            }
            

            // continue flow of game
            
            bool repeatCoordinate = false;
            repeatCoordinate = bsObj.coordinateValidator(userRow, userCol);

            if (repeatCoordinate == false)
            {
                cout << "\nYou have already played this coordinate, please enter another coordinate!";
                userCol = int('A') - 1;
            }
            else {
                validation = true;
            }
        }

        numUserCol = int(userCol) - 65;


        shipHitCount = bsObj.shipDetector(userRow - 1, numUserCol, shipHitCount);

        int missCounter = bsObj.getMissShips();

        if (missCounter == 15)
        {
            cout << "\nYou have a miss of 15 strikes! Game ends!";
            return 0;
        }

        if (shipHitCount == 17)
        {
            bsObj.printUserGrid();
            cout << "\nGood Job! You have terminated the enemy!";

            return 0;
        }

        if (shipHitCount < 17 && i == 17)
        {
            cout << "\nThe enemy found your location! Game Over!";
            bsObj.printUserGrid();

            return 0;
        }

        // DELETE
        // bsObj.printGrid();

        bsObj.printUserGrid();
    }
    return 0;
};





