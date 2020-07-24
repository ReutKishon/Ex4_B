#pragma once

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Soldier
{
private:
    uint player_id; // player number
    string name_of_soldier;
    uint initial_health_points;
    uint health_points; // generic health points
    uint damage_per_activity;

public:
    Soldier(uint player_id, uint health_points, string name, uint damage) : player_id(player_id), initial_health_points(health_points), health_points(health_points),
                                                                            name_of_soldier(name), damage_per_activity(damage)
    {
        cout << "initial Soldier" << endl;
    }
    double distance(int x1, int x2, int y1, int y2); //(x1,y1) , (x2,y2)  pitagoras

    virtual void activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location) = 0;
    // setters and getters:
    void set_health_points(uint health_points);
    string get_name();
    uint get_id();
    uint get_initial_health_points();
    uint get_health_points();
    uint get_damage_points();

};
