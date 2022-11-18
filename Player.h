#pragma once
#include "Character.h"
#include <bits/stdc++.h>

class Player : public Character{
    private:
        friend class Map;

    public:
        Player(){
            Position player_pos(1,2);
            Character(10,10,"이준근",player_pos);
        }
        Player(int hp,int mp,string name,int x,int y)
        {
            Position player_pos(x,y);
            Character(hp,mp,name,player_pos);        
        }      
};