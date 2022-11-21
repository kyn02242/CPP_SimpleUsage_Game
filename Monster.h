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
        Monster()
            :Character(10,10,"이원진",5,16){        
        }
        Monster(int hp,int mp,string name,int x,int y)
            :Character(hp,mp,name,x,y){
        }
};