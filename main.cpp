#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "Position.h"
#include "GameMap.h"
#include "Game.h"

using namespace std;

#define gotoxy(x,y) printf("\033[%d;%dH",(x),(y))

int main(){
    freshing();
    Game game;
    game.gamemap.Show_map();
    game.playermove();
    return 0;    
}