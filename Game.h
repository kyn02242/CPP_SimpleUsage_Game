#include <bits/stdc++.h>
#include "GameMap.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"
class Game{
    private:
        Map GameMap;
        Player player;
        Monster monster;
        //Monster *monster;
    public:
        Game(){
            Map GameMap();
            Player player;
            Monster monster;
        }

};