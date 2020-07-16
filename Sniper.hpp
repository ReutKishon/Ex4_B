#ifndef SNIPER_H_
#define SNIPER_H_
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class Sniper : public Soldier
{
    uint damage_per_activity;
public:
    Sniper(uint player_id) : Soldier(player_id, 100 , "Sniper") , damage_per_activity(50)
    {
        cout << "initial Sniper" << endl;
    }
    virtual void activity(vector<vector<Soldier *>> &b, pair<int, int> location);
    virtual ~Sniper();
};

Sniper::~Sniper()
{
}
#endif