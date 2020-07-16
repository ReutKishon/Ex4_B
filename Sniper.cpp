#include "Sniper.hpp"

#include <iostream>
#include <math.h>
using namespace std;


void Sniper::activity(vector<vector<Soldier *>> &b, pair<int, int> location)
{

    uint max_health_points = 0;
    Soldier *Strongest_soldier = nullptr;
    double curr_health_points = 0;

    // Traversing the whole matrix
    // to find the minimum distance.
    for (int row = 0; row < b.size(); row++)
        for (int col = 0; col < b[row].size(); col++)
        {
            // If cell contains soldier, check
            // for max health points.
            if (b[row][col] != nullptr && !(row == location.first && col== location.second) && b[row][col]->get_id() != this->get_id() ) // take care of not  the same location
            {
                curr_health_points = b[row][col]->get_health_points();
                max_health_points = max(max_health_points, curr_health_points);
                if (max_health_points < curr_health_points)
                {
                    Strongest_soldier = b[row][col]; // implememt operator =
                }
            }
        }
    int health_points_after_kill = Strongest_soldier->get_health_points() - this->damage_per_activity;
    Strongest_soldier->set_health_points(health_points_after_kill);
}