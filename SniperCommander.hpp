#ifndef SNIPERCOMMANDER_H_
#define SNIPERCOMMANDER_H_
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class SniperCommander : public Soldier
{
    uint damage_per_activity;
public:
    SniperCommander(uint player_id) : Soldier(player_id, 120 , "SniperCommander") , damage_per_activity(100)
    {
        cout << "initial SniperCommander" << endl;
    }
    virtual void activity();
    virtual ~SniperCommander();
};

SniperCommander::~SniperCommander()
{
}
#endif