#pragma once
#include <stdlib.h>
#include <time.h>
#include "Position.h"
using namespace std;

int randomout_zerotomax(int max){
    srand(time(NULL));
    int a = rand();
    a%=max;
    return a;
}

Position random_pos(){
    srand(time(NULL));
    int x = rand();
    x%=8;
    x++;
    int y = rand();
    y%=19;
    y+=1;
    y*=2;
    Position out(x,y);
    return out;
}