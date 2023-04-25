#ifndef SIATKA_H_INCLUDED
#define SIATKA_H_INCLUDED
#pragma once

#include <iostream>

#include "komorka.h"

using namespace std;

class Board {
private:
    int n;
    int m;
    Cell** tab;
public:
    Board(int n, int m);
    ~Board();
    Board(const Board&);
    Board& operator=(const Board&);
    friend ostream& operator<<(ostream& os, const Board& b);
    void cykcle();
    int liczbaSasiadow(int i, int j);
    void print(int i, int j) {cout << tab[i][j].print() << endl;}
};

Board::Board(int n, int m) {
    this->n = n;
    this->m = m;

    tab = new Cell * [n];
    for (int i = 0; i < n; i++) {
        tab[i] = new Cell[m] { false };
    }

    int b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b = rand() % 2;
            if (b == 1) {
                tab[i][j].setStan(true);
            }
            else {
                tab[i][j].setStan(false);
            }
        }
    }
}

Board& Board::operator=(const Board& b) {
    if(this == &b)
        return *this;

    delete[] tab;

    n = b.n;
    m = b.m;

    tab = new Cell * [n];
    for (int i = 0; i < n; i++) {
        tab[i] = new Cell[m]{ false };
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tab[i][j] = b.tab[i][j];
        }
    }

    return *this;
}

int Board::liczbaSasiadow(int i, int j) {
    int result = 0;
    if (i - 1 >=0 && i - 1 < n && j - 1 >=0 && j -1 <m)
        if (tab[i - 1][j - 1].getStan())
            result++;
    if (i - 1 >=0 && i - 1 < n && j >=0 && j <m)
        if (tab[i - 1][j].getStan())
            result++;
    if (i - 1 >=0 && i - 1 < n && j + 1 >=0 && j +1 <m)
        if (tab[i - 1][j + 1].getStan())
            result++;
    if (i >=0 && i < n && j - 1 >=0 && j -1 <m)
        if (tab[i][j - 1].getStan())
            result++;
    if (i >=0 && i < n && j + 1 >=0 && j +1 <m)
        if (tab[i][j + 1].getStan())
            result++;
    if (i + 1 >=0 && i + 1 < n && j >=0 && j <m)
        if (tab[i + 1][j].getStan())
            result++;
    if (i + 1 >=0 && i + 1 < n && j + 1 >=0 && j +1 <m)
        if (tab[i + 1][j + 1].getStan())
            result++;
    if (i + 1 >=0 && i + 1 < n && j - 1 >=0 && j -1 <m)
        if (tab[i + 1][j - 1].getStan())
            result++;
    return result;
}

ostream& operator<<(ostream& os, const Board& b) {

    for (int i = 0; i < b.n; i++) {
        for (int j = 0; j < b.m; j++) {
            os << b.tab[i][j].print() << " ";
        }
        os << endl;
    }

    return os;
}

void Board::cykcle(){
    Board kopia = *this;
    int l;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            l = liczbaSasiadow(i, j);
            if (kopia.tab[i][j].getStan()) {
                if (l > 3)
                    kopia.tab[i][j].changeStan();
                if (l < 2)
                    kopia.tab[i][j].changeStan();
            }
            else {
                if (l == 3) {
                    kopia.tab[i][j].changeStan();
                }
            }
        }
    }
    *this = kopia;
}

Board::~Board() {
    delete[] tab;
}

Board::Board(const Board& b){
    this->n = b.n;
    this->m = b.m;

    this->tab = new Cell*[n];
    for(int i = 0; i < n; i++){
        tab[i] = new Cell[m];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tab[i][j] = b.tab[i][j].getStan();
        }
    }
}

#endif // SIATKA_H_INCLUDED
