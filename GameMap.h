#pragma once
#include <bits/stdc++.h>
#include "Position.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"
//#include <curses.h>
using namespace std;
#define gotoxy(x, y) printf("\033[%d;%dH", (x), (y))

class Fresh
{
    public:
    static void freshing(int height=10, int width=44)
    {
        gotoxy(0, 0);
        for (int i = 0; i < height; i++)
        {
            for(int j=0;j<width;j++){
                cout<<" ";
            }
            cout<<endl;
        }
        gotoxy(0, 0);
    }
};

class Map
{
public:
    vector<vector<string>> game_map;
    Position player_pos;
    vector<Position> monster_pos;
    int monster_num;

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
        game_map[player_pos.x][player_pos.y] = "●";
    }
    Map(int n)
        : game_map(10, vector<string>(41)),monster_num(n)
    {
        monster_pos = vector<Position>(monster_num);
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
        game_map[player_pos.x][player_pos.y] = "●";
        for (int i=0;i<monster_num;i++)
        {
            game_map[monster_pos[i].x][monster_pos[i].y] = "☎";
        }
    }
    void Show_map(int n)
    {
        monster_num = n;
        for(int i=0;i<n;i++){
            monster_pos[i].show();
        }
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
        for (int i=0;i<monster_num;i++)
        {
            game_map[monster_pos[i].x][monster_pos[i].y] = "☎";
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