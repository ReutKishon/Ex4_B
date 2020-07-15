#ifndef FOOTSOLDIER_H_
#define FOOTSOLDIER_H_
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class FootSoldier : public Soldier
{
public:
    FootSoldier(uint player_id, uint health_points, uint damage_points) : Soldier(player_id, health_points, damage_points)
    {
        cout << "initial FootSoldier" << endl;
    }
    virtual void activity();
    virtual ~FootSoldier();
};

FootSoldier::~FootSoldier()
{
}
#endif