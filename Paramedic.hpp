
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class Paramedic : public Soldier
{

public:
    Paramedic(uint player_id) : Soldier(player_id, 100, "Paramedic", 0)
    {
        cout << "initial Paramedic" << endl;
    }
    virtual void activity(vector<vector<Soldier *>> &b, pair<int, int> location);
};

