#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class FootSoldier : public Soldier
{

public:
    FootSoldier(uint player_id) : Soldier(player_id, 100, "FootSoldier", 10)
    {
        cout << "initial FootSoldier" << endl;
    }
    void activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location);
   
};
