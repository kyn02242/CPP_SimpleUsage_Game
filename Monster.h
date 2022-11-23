#pragma once
#include <bits/stdc++.h>
#include "Randomout.h"
#include "Character.h"
#include "Position.h"
using namespace std;

class Monster : public Character{
    private:
        friend class Map;
    public:
        Monster()
            :Character(10,10,nameset[Randomout::zerotomax(9)],Position::random_pos()){ 
        }
        Monster(int hp,int mp,string name,int x,int y)
            :Character(hp,mp,name,x,y){
        }
};