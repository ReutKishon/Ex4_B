#ifndef FOOTCOMMANDER_H_
#define FOOTCOMMANDER_H_
#pragma once

#include <iostream>
#include "Soldier.hpp"
#include "FootSoldier.hpp"
using namespace std;

class FootCommander : public Soldier
{
public:
    FootCommander(uint player_id) : Soldier(player_id, 150, 20) 
    {
        cout << "initial FootCommander" << endl;
    }
    virtual void activity();
    virtual ~FootCommander();
};

FootCommander::~FootCommander()
{
}
#endif