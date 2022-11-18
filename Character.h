#pragma once
#include <bits/stdc++.h>
#include"Character_namespace.h"
#include "Position.h"
using namespace std;

class Character{
    private:
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
        Character(int hp,int mp,string name,Position posi)
            :hp(hp),mp(mp),name(name),pos(posi){
                pos.show();
        }
};