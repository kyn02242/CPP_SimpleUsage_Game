#pragma once
#include <bits/stdc++.h>
#include "Position.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"
//#include <curses.h>
using namespace std;
#define gotoxy(x, y) printf("\033[%d;%dH", (x), (y))

void freshing()
{
    gotoxy(0, 0);
    for (int i = 0; i < 10; i++)
    {
        cout << "                                                                                                                                                                                      " << endl;//62개의 빈칸
    }
    gotoxy(0, 0);
}

class Map
{
public:
    vector<vector<string>> game_map;
    Position player_pos;
    //Position *monster_posarr;
    Position monster_pos;
    int monster_num=1;

public:
    Map()
        : game_map(10, vector<string>(41))
    {
        for (int i = 0; i < 41; i += 2)
        {
            game_map[0][i] = "■";
            game_map[9][i] = "■";
        }
        for (int i = 0; i < 10; i++)
        {
            game_map[i][0] = "■";
            game_map[i][40] = "■";
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 41; j++)
            {
                if (game_map[i][j] != "■")
                {
                    game_map[i][j] = " ";
                }
            }
        }
        player_pos = Position(1, 2);
        monster_pos = Position(1, 4);
        game_map[player_pos.x][player_pos.y] = "●";
        if(monster_num>0){
            game_map[monster_pos.x][monster_pos.y] = "☎";
        }
    }
    Map(Player &player, Monster &monster)
        : player_pos(player.pos), monster_pos(monster.pos), game_map(10, vector<string>(41))
    {
        for (int i = 0; i < 41; i += 2)
        {
            game_map[0][i] = "■";
            game_map[9][i] = "■";
        }
        for (int i = 0; i < 10; i++)
        {
            game_map[i][0] = "■";
            game_map[i][40] = "■";
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 41; j++)
            {
                if (game_map[i][j] != "■")
                {
                    game_map[i][j] = " ";
                }
            }
        }
        game_map[player_pos.x][player_pos.y] = "●";
        if(monster_num>0){
            game_map[monster_pos.x][monster_pos.y] = "☎";
        }
    }
    void Show_map()
    {
        //freshing();
        gotoxy(0,0);

        for (int i = 0; i <= 40; i += 2)
        {
            game_map[0][i] = "■";
            game_map[9][i] = "■";
        }
        for (int i = 0; i < 10; i++)
        {
            game_map[i][0] = "■";
            game_map[i][40] = "■";
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j <= 40; j++)
            {
                if (game_map[i][j] != "■" )
                {
                    game_map[i][j] = " ";
                }
            }
        }
        game_map[player_pos.x][player_pos.y] = "●";
        if(monster_num>0){
            game_map[monster_pos.x][monster_pos.y] = "☎";
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 41; j++)
            {
                cout << game_map[i][j];
            }
            cout << endl;
        }
    }
};