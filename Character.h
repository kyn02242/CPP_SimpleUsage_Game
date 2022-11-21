#pragma once
#include <bits/stdc++.h>
#include"Character_nameset.h"
#include "Position.h"
using namespace std;

class Character{
    public:
        int hp;
        int mp;
        string name;
        Position pos;
        friend class Map;
    public:
        Character(){};
        Character(int hp,int mp,int num,Position pos)
            :hp(hp),mp(mp),pos(pos){
                name = nameset[num];
        }
        Character(int hp,int mp,string name,Position pos)
            :hp(hp),mp(mp),name(name),pos(pos){
        }
        Character(int hp,int mp,string name,int x,int y)
            :hp(hp),mp(mp),name(name){
                pos=Position(x,y);
        }
};