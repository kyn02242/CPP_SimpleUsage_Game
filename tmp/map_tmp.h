#pragma once
#include <bits/stdc++.h>
#include "Namespace.h"
#include <curses.h>
#define gotoxy(x,y) printf("\033[%d;%dH",(x),(y))
using namespace std;

void freshing(){
    gotoxy(0,0);
    for(int i=0;i<20;i++){
        cout<<"                                             "<<endl;
    }
    gotoxy(0,0);
}

class Position{
    private:
        int x;
        int y;
    public:
        Position()
            :x(2),y(3){}
        Position(int x,int y)
            :x(x+2),y(y+3){}
        Position(Position &pos)
            :x(pos.x),y(pos.y){}
        void Up(){
            x--;
        }
        void Down(){
            x++;
        }
        void left(){
            y-=2;
        }
        void right(){
            y+=2;
        }
};

class Map{
    private:
        //Position player_pos;
        vector<vector<string>> mapp;
    public:
        Map()
            //:player_pos(player.where()),
            :mapp(vector<vector<string>>(20,vector<string>(40))){
                for(int i=0;i<40;i++){
                    mapp[0][i] = "■";
                    mapp[19][i] = "■";
                }
                for(int i=0;i<20;i++){
                    mapp[i][0] = "■";
                    mapp[i][39]="■";
                }
            }
        void refresh(){
            freshing();
            for(int i=0;i<20;i++){
                for(int j=0;j<40;j++){
                    cout<<mapp[i][j];
                }
                cout<<endl;
            }
        }

};