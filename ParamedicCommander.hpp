#ifndef PARAMEDICCOMMANDER_H_
#define PARAMEDICCOMMANDER_H_
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class ParamedicCommander : public Soldier
{
public:
    ParamedicCommander(uint player_id) : Soldier(player_id, 200 , "ParamedicCommander")
    {
        cout << "initial ParamedicCommander" << endl;
    }
    virtual void activity();
    virtual ~ParamedicCommander();
};

ParamedicCommander::~ParamedicCommander()
{
}
#endif