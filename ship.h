#ifndef ship_H
#define ship_H
#include <string>

class ship {
public:
    int size;
    int health;
    std::string name;
    std::string lable; // first letter of ship 

    void TakeHit();
    ship(int, std::string, char);
};

#endif ship_H