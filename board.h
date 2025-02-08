#ifndef board_H
#define board_H

#include <string>
#include "ship.h"
#include <vector>

const int ROWS = 10;
const int COLS = 10;


class board { 
private:
    std::string PrivateBoard[ROWS][COLS];
    std::string userBoard[ROWS][COLS];
    std::vector<ship> ships;

public:
    int missShips = 0;
    void printGrid();
    void SetGrid();
    void shipPlacer(ship);
    void printUserGrid();
    void setUserGrid();
    int shipDetector(int, int, int);
    bool coordinateValidator(int, int);
    int getMissShips();
};

#endif board_H