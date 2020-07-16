
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
            // If cell contain soldier, check
            // for minimum distance.
            if (b[row][col] != nullptr && !(row == location.first && col == location.second) && b[row][col]->get_id() != this->get_id()) // take care of not  the same location
            {
                curr_dist = this->distance(location.first, row, location.second, col);
                minimum_dist = min(minimum_dist, curr_dist);
                if (curr_dist < minimum_dist)
                {
                    closest_soldier = b[row][col];
                }
            }
        }
    closest_soldier->Take_Hit(this->get_damage_points(), b, {row, col});
}