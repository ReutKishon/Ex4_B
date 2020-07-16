
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class ParamedicCommander : public Soldier
{
public:
    ParamedicCommander(uint player_id) : Soldier(player_id, 200 , "ParamedicCommander",0)
    {
        cout << "initial ParamedicCommander" << endl;
    }
    virtual void activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location);
};


