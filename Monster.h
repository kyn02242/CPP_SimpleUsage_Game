#pragma once
#include <bits/stdc++.h>
#include "randomout.h"
#include "Character.h"
#include "Position.h"
using namespace std;

class Monster : public Character{
    private:
        friend class Map;
    public:
        Monster(){
            //Position monster_pos = random_pos();
            Position monster_pos(4,10);
            Character(1,1,nameset[0],monster_pos);            
        }
        Monster(int hp,int mp,string name,int x,int y){
            Position monster_pos(x,y);
            Character(hp,mp,name,monster_pos);
        }
};