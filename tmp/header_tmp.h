#pragma once
#include <bits/stdc++.h>
#include "Namespace.h"
#include <curses.h>
#include "map.h"
#define gotoxy(x,y) printf("\033[%d;%dH",(x),(y))
using namespace std;



void gameover(int status)
{
    if (status == Ending::DIE)
    {
        cout << "GAME OVER" << endl;
    }
    else
    {
        cout << "Congratuation You Finished the Game!!" << endl;
    }
    exit(1);
}


class Status
{
private:
    char *name;
    int hp;
    int mp;
    Position pos;
    friend class Map;

public:
    Status(int hp, int mp, const char *name)
        : hp(hp), mp(mp)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void Damaged(int damage)
    {
        hp -= damage;
        if (hp <= 0)
        {
            gameover(Ending::DIE);
        }
    }
    void Attack(Status &enemy)
    {
        enemy.Damaged(5);
    }
    void ShowStatus()
    {
        cout << "hp : " << hp << endl;
        cout << "mp : " << mp << endl;
    }
    Position& where(){
        return pos;
    }
    ~Status()
    {
        cout<<"dest status"<<endl;
        delete[] name;
    }
};
class Main_Character : public Status
{ //=====================================메인 캐릭터=========================================
private:
    int ability;
    friend class Map;

public:
    Main_Character(int hp, int mp, const char *name, int ability)
        : Status(hp, mp, name), ability(ability) {}
};
class Monster : public Status
{ //=====================================몬스터=========================================
private:
    int cc;
    friend class Map;

public:
    Monster(int hp, int mp, const char *name, int cc)
        : Status(hp, mp, name), cc(cc) {}
};
