
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class Sniper : public Soldier
{
public:
    Sniper(uint player_id) : Soldier(player_id, 100, "Sniper", 50)
    {
        cout << "initial Sniper" << endl;
    }
     void activity(vector<vector<Soldier *>> &b, pair<int, int> location);
};

