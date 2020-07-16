#ifndef PARAMEDIC_H_
#define PARAMEDIC_H_
#pragma once

#include <iostream>
#include "Soldier.hpp"
using namespace std;

class Paramedic : public Soldier
{
    
public:
    Paramedic(uint player_id) : Soldier(player_id, 100 , "Paramedic")
    {
        cout << "initial Paramedic" << endl;
    }
    virtual void activity(vector<vector<Soldier *>> &b, pair<int, int> location);
    virtual ~Paramedic();
};

Paramedic::~Paramedic()
{
}
#endif