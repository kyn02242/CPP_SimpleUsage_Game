#pragma once
#include <bits/stdc++.h>
#include "Randomout.h"
using namespace std;
class Position
{
public:
    int x;
    int y;
    friend class Map;

public:
    Position()
    {
        *this = random_pos();
    }
    Position(int x, int y)
        : x(x), y(y) {}
    Position(Position &pos)
        : x(pos.x), y(pos.y)
    {
    }
    void up()
    {
        x--;
    }
    void right()
    {
        y += 2;
    }
    void left()
    {
        y -= 2;
    }
    void down()
    {
        x++;
    }
    void show()
    {
        cout << '(' << x << ',' << y << ')' << endl;
    }
    static Position random_pos()
    {
        int x = Randomout::zerotomax(8);
        int y = 2*Randomout::zerotomax(19);
        return Position(x,y);
    }
};
