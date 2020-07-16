
#include <iostream>
#include <math.h>
#include "FootSoldier.hpp"
using namespace std;

void FootSoldier::activity(vector<vector<Soldier *>> &b, pair<int, int> location)
{

    double minimum_dist = 0;
    Soldier *closest_soldier = nullptr;
    double curr_dist = 0;

    // Traversing the whole matrix
    // to find the minimum distance.
    int row, col;
    for (row = 0; row < b.size(); row++)
        for (col = 0; col < b[row].size(); col++)
        {
            pair<int, int> current_location = {row, col};
            // If cell contain soldier, check
            // for minimum distance.
            if (b[row][col] != nullptr && (current_location != location) && b[row][col]->get_id() != this->get_id()) // take care of not  the same location
            {
                curr_dist = this->distance(location.first, row, location.second, col);
                minimum_dist = min(minimum_dist, curr_dist);
                if (curr_dist < minimum_dist)
                {
                    closest_soldier = b[row][col];
                }
            }
        }
    uint health_points_after_injury = closest_soldier->get_health_points() - this->get_damage_points();
    closest_soldier->set_health_points(health_points_after_injury);
    if (health_points_after_injury <= 0)
    {
        b[row][col] = nullptr;
    }
}