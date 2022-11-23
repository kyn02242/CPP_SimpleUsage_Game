#pragma once
#include <stdlib.h>
#include <time.h>
#include "Position.h"
using namespace std;

class Randomout
{
public:
    static int zerotomax(int max)
    {
       
        int a = rand();
        a %= max;
        a++;
        return a;
    }
};
