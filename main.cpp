#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "Position.h"
#include "GameMap.h"
#include <curses.h>

using namespace std;

#define gotoxy(x,y) printf("\033[%d;%dH",(x),(y))

int main(){
    freshing();
    Player mainplayer(10,10,"이준근",1,3);
    Monster badone(1,1,"이원진",5,15);
    Map mainmap(mainplayer,badone);
    
    //mainmap.Show_map();
    
    return 0;
}