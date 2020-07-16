#ifndef FOOTSOLDIER_H_
#define FOOTSOLDIER_H_
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class FootSoldier : public Soldier
{
    uint damage_per_activity;

public:
    FootSoldier(uint player_id) : Soldier(player_id, 100, "FootSoldier"), damage_per_activity(10);
    {
        cout << "initial FootSoldier" << endl;
    }
    void activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location);
    virtual ~FootSoldier();
};

FootSoldier::~FootSoldier()
{
}
#endif