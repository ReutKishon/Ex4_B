
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class FootCommander : public Soldier
{
public:
    FootCommander(uint player_id) : Soldier(player_id, 150, "FootCommander", 20)
    {
        cout << "initial FootCommander" << endl;
    }
    void activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location);
};
