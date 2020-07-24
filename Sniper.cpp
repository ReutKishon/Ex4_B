#include "Sniper.hpp"

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void Sniper::activity(vector<vector<Soldier *>> &b, pair<int, int> location)
{

    uint max_health_points = 0;
    Soldier *Strongest_soldier = nullptr;
    uint curr_health_points = 0;
    pair<int, int> strongest_location;
    int row, col;
    // Traversing the whole matrix
    // to find the minimum distance.
    for (row = 0; row < b.size(); row++)
        for (col = 0; col < b[row].size(); col++)
        {
            pair<int, int> current_location = {row, col};
            // If cell contains soldier, check
            // for max health points.
            if (b[row][col] != nullptr && (current_location != location) && b[row][col]->get_id() != this->get_id()) // take care of not  the same location
            {
                curr_health_points = b[row][col]->get_health_points();
                if (max_health_points < curr_health_points)
                {
                    Strongest_soldier = b[row][col]; // implememt operator =
                    max_health_points = curr_health_points;
                    strongest_location = current_location;
                }
            }
        }
    if (Strongest_soldier != nullptr)
    {

        uint health_points_after_injury = Strongest_soldier->get_health_points() - this->get_damage_points();
        Strongest_soldier->set_health_points(health_points_after_injury);
        if (health_points_after_injury <= 0)
        {
            delete b[strongest_location.first][strongest_location.second];
            b[strongest_location.first][strongest_location.second] = nullptr;
        }
    }
}