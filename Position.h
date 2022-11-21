#pragma once
#include <bits/stdc++.h>
using namespace std;
class Position{
    public:
        int x;
        int y;
        friend class Map;
    public:
        Position(){}
        Position(int x,int y)
            :x(x),y(y){}
        Position(Position &pos)
            :x(pos.x),y(pos.y){
                cout<<"copyconst("<<x<<','<<y<<')'<<endl;
        }
        void up(){
            x--;
        }
        void right(){
            y+=2;
        }
        void left(){
            y-=2;
        }
        void down(){
            x++;
        }
        void show(){
            cout<<'('<<x<<','<<y<<')'<<endl;
        }
};