#pragma once
#include <bits/stdc++.h>
#include "logprint.h"
#include "GameMap.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"

int getch(void)
{
    int ch;

    struct termios old;
    struct termios nw;

    tcgetattr(0, &old);

    nw = old;
    nw.c_lflag &= ~(ICANON | ECHO);
    nw.c_cc[VMIN] = 1;
    nw.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &nw);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &old);

    return ch;
}

class Game{
    public:
        Map gamemap;
        Player player;
        //Monster *monster;
        Monster monster;
    public:
        Game()
            :gamemap(),player(),monster(){
                freshing();
                gamemap.player_pos = player.pos;
                gamemap.monster_pos = monster.pos;
        }
        void gameover(){
            freshing();
            cout<<"===============Game Over================="<<endl;
            exit(0);
        }
        void gamewin(){
            freshing();
            cout<<"===============Game Win================="<<endl;
            exit(0);
        }
        void playermove()
        {
        int key;
        for (int i = 0;; i++)
        {
            key = getch();
            //cout << key << endl; // w=119,a=97,s-=115,d=100
            switch (key)
            {
            case (119):
                if(gamemap.game_map[player.pos.x-1][player.pos.y]=="■"){
                    logprint("위쪽은 벽으로 막혀있습니다.");
                    break;
                }
                if(gamemap.game_map[player.pos.x-1][player.pos.y]=="☎"){
                    logprint("몬스터를 만났습니다. 서로를 공격합니다.");
                    logdamage(player,monster);
                    player.hit(monster);
                    logdamage(player,monster);
                    break;
                }
                player.pos.up();
                logprint("위로 이동");
                break;
            case (97):
                if(gamemap.game_map[player.pos.x][player.pos.y-2]=="■"){
                    logprint("왼쪽은 벽으로 막혀있습니다.");
                    break;
                }
                if(gamemap.game_map[player.pos.x][player.pos.y-2]=="☎"){
                    logprint("몬스터를 만났습니다. 서로를 공격합니다.");
                    player.hit(monster);
                    logdamage(player,monster);
                    break;
                }
                player.pos.left();
                logprint("왼쪽으로 이동");
                break;
            case (115):
                if(gamemap.game_map[player.pos.x+1][player.pos.y]=="■"){
                    logprint("아래쪽은 벽으로 막혀있습니다.");
                    break;
                }
                if(gamemap.game_map[player.pos.x+1][player.pos.y]=="☎"){
                    logprint("몬스터를 만났습니다. 서로를 공격합니다.");
                    player.hit(monster);
                    logdamage(player,monster);
                    break;
                }
                player.pos.down();
                logprint("아래로 이동");
                break;
            case (100):
                if(gamemap.game_map[player.pos.x][player.pos.y+2]=="■"){
                    logprint("오른쪽은 벽으로 막혀있습니다.");
                    break;
                }
                if(gamemap.game_map[player.pos.x][player.pos.y+2]=="☎"){
                    logprint("몬스터를 만났습니다. 서로를 공격합니다.");
                    player.hit(monster);
                    logdamage(player,monster);
                    break;
                }
                player.pos.right();
                logprint("오른쪽으로 이동");
                break;
            }
            if(player.hp<=0){
                gameover();
            }
            else if(monster.hp<=0){
                gamemap.monster_num--;
            }
            gamemap.player_pos = player.pos;
            //player.pos.show();
            gamemap.Show_map();
        }
        
    }

};