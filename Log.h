#pragma once
#include <bits/stdc++.h>
#include "GameMap.h"
#include "Character.h"
#include "Monster.h"
#include "Player.h"

using namespace std;

//#define gotoxy(x, y) printf("\033[%d;%dH", (x), (y))

class Log
{
public:
    static int log_count;
    const static int START;

    static void logprint(string log)
    {
        gotoxy(log_count, START);
        cout << log << endl;
        log_count++;
    }
    static void logdamage(Player &player, Monster &monster)
    {
        gotoxy(log_count, START);
        cout << player.name << " hp : " << player.hp << "  " << monster.name << " hp : " << monster.hp << endl;
        log_count++;
    }
};
int Log::log_count = 1;
const int Log::START = 46;