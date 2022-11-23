#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "Position.h"
#include "GameMap.h"
#include "Game.h"

using namespace std;

//#define gotoxy(x,y) printf("\033[%d;%dH",(x),(y))

int main(){
    srand(time(NULL));
    Fresh::freshing(10,100);
    Game game;
    game.playermove();
    
    //test TTest;
    return 0;    
}