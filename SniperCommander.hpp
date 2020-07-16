
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class SniperCommander : public Soldier
{
public:
    SniperCommander(uint player_id) : Soldier(player_id, 120, "SniperCommander", 100)
    {
        cout << "initial SniperCommander" << endl;
    }
    virtual void activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location);
};


