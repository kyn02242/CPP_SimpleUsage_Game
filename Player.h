#pragma once
#include "Character.h"
#include <bits/stdc++.h>
#include "Monster.h"



class Player : public Character
{
private:
    friend class Map;

public:
    Player()
        :Character(15, 10, "이준근", 1,2){
    }
    Player(int hp, int mp, string name, int x, int y)
        : Character(hp, mp, name, x, y)
    {
    }
    void hit(Monster &monster){
        hp--;
        monster.hp--;
    }
};