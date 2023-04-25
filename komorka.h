#ifndef KOMORKA_H_INCLUDED
#define KOMORKA_H_INCLUDED
#include <iostream>

using namespace std;

class Cell{
private:
    bool stan;
public:
    Cell(bool s = false) : stan(s) {}
    ~Cell() {}
    bool getStan() const;
    void changeStan();
    void setStan(bool s) {stan = s;}
    char print() const;
};

bool Cell::getStan() const{
    return stan;
}

void Cell::changeStan(){
    stan = !stan;
}

char Cell::print() const{
    if(stan)
        return 'o';
    return '.';
}


#endif // KOMORKA_H_INCLUDED
