#pragma once
#include <bits/stdc++.h>
//#include "Game.h"
#include "Character.h"
#include "Monster.h"
#include "Player.h"

using namespace std;

#define gotoxy(x, y) printf("\033[%d;%dH", (x), (y))

int log_count = 1;

void logprint(string log){
    gotoxy(log_count,42);
    cout<<log<<endl;;
    log_count++;
}
void logdamage(Player &player,Monster &monster){
    gotoxy(log_count,42);
    cout<<player.name<<" hp : "<<player.hp<<"  "<<monster.name<<" hp : "<<monster.hp<<endl;
    log_count++;
}