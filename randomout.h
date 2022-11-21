#pragma once
#include <stdlib.h>
#include <time.h>
#include "Position.h"
using namespace std;

int randomout_zerotomax(int max)
{
    srand(time(NULL));
    int a = rand();
    a %= max;
    return a;
}

Position random_pos()
{
    int x = 0, y = 0;
    while (1)
    {
        srand(time(NULL));
        x = rand();
        x %= 8;
        x++;
        y = rand();
        y %= 19;
        y += 1;
        y *= 2;
        if(x!=1&&y!=2){
            break;
        }
    }
    Position out(x, y);
    cout<<"gg"<<endl;
    return out;
}