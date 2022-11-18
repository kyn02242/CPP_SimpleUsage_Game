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
    x%=10;
    int y = rand();
    y%=10;
    y*=2;
    Position out(x,y);
    return out;
}