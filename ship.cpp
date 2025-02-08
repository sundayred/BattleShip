#include "ship.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

ship::ship(int S, string N, char C) {
    size = S;
    name = N;
    lable = C;
    health = S;
}

void ship::TakeHit() {
    health--;

    if (health <= 0) {
        cout << endl << "\n\n\nFantastic, you sunk the " << name << "!" << endl;
    }
}
