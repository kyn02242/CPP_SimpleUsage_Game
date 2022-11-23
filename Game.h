#pragma once
#include <bits/stdc++.h>
#include "Log.h"
#include "GameMap.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include <termio.h>

using namespace std;

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
        int monster_num;
        vector<Monster> monster;
    public:
        Game()
            {
                monster_num = Randomout::zerotomax(5);
                gamemap = Map(monster_num);
                Fresh::freshing();
                monster = vector<Monster>(monster_num);
                gamemap.player_pos = player.pos;
                cout<<monster_num<<endl;
                for(int i=0;i<monster_num;i++){
                    monster[i] = Monster();
                    cout<<"new Monster"<<monster[i].name<<" "<<monster[i].hp<<endl;
                }
                gamemap.Show_map(monster_num);
        }
        void gameover(){
            Fresh::freshing();
            cout<<"===============Game Over================="<<endl;
            exit(0);
        }
        void gamewin(){
            Fresh::freshing();
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
                    Log::logprint("위쪽은 벽으로 막혀있습니다.");
                    break;
                }
                if(gamemap.game_map[player.pos.x-1][player.pos.y]=="☎"){
                    Log::logprint("몬스터를 만났습니다. 서로를 공격합니다.");
                    for(int i=0;i<monster_num;i++){
                        if(monster[i].pos.x==player.pos.x-1&&monster[i].pos.y==player.pos.y){
                            player.hit(monster[i]);
                            Log::logdamage(player,monster[i]);
                            break;
                        }
                    }
                    
                    break;
                }
                player.pos.up();
                Log::logprint("위로 이동");
                break;
            case (97):
                if(gamemap.game_map[player.pos.x][player.pos.y-2]=="■"){
                    Log::logprint("왼쪽은 벽으로 막혀있습니다.");
                    break;
                }
                if(gamemap.game_map[player.pos.x][player.pos.y-2]=="☎"){
                    Log::logprint("몬스터를 만났습니다. 서로를 공격합니다.");
                    for(int i=0;i<monster_num;i++){
                        if(monster[i].pos.x==player.pos.x&&monster[i].pos.y==player.pos.y-2){
                            player.hit(monster[i]);
                            Log::logdamage(player,monster[i]);
                            break;
                        }
                    }
                    
                    break;
                }
                player.pos.left();
                Log::logprint("왼쪽으로 이동");
                break;
            case (115):
                if(gamemap.game_map[player.pos.x+1][player.pos.y]=="■"){
                    Log::logprint("아래쪽은 벽으로 막혀있습니다.");
                    break;
                }
                if(gamemap.game_map[player.pos.x+1][player.pos.y]=="☎"){
                    Log::logprint("몬스터를 만났습니다. 서로를 공격합니다.");
                    for(int i=0;i<monster_num;i++){
                        if(monster[i].pos.x==player.pos.x+1&&monster[i].pos.y==player.pos.y){
                            player.hit(monster[i]);
                            Log::logdamage(player,monster[i]);
                            break;
                        }
                    }
                    
                    break;
                }
                player.pos.down();
                Log::logprint("아래로 이동");
                break;
            case (100):
                if(gamemap.game_map[player.pos.x][player.pos.y+2]=="■"){
                    Log::logprint("오른쪽은 벽으로 막혀있습니다.");
                    break;
                }
                if(gamemap.game_map[player.pos.x][player.pos.y+2]=="☎"){
                    Log::logprint("몬스터를 만났습니다. 서로를 공격합니다.");
                    for(int i=0;i<monster_num;i++){
                        if(monster[i].pos.x==player.pos.x&&monster[i].pos.y==player.pos.y+2){
                            player.hit(monster[i]);
                            Log::logdamage(player,monster[i]);
                            break;
                        }
                    }
                    
                    break;
                }
                player.pos.right();
                Log::logprint("오른쪽으로 이동");
                break;
            }
            if(player.hp<=0){
                gameover();
            }
            for(int i=0;i<monster_num;i++){
                if(monster[i].hp==0){
                    Log::logprint(monster[i].name+"을 무찔렀습니다.");
                    gamemap.monster_num--;
                    monster_num--;
                    monster.erase(monster.begin()+i);
                }
            }
            if(monster_num==0){
                gamewin();
            }
            gamemap.player_pos = player.pos;
            gamemap.Show_map(monster_num);
        }
        
    }

};