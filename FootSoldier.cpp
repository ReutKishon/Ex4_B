
#include <iostream>
#include <math.h>
using namespace std;

#include "FootSoldier.hpp"

void FootSoldier::activity(vector<vector<Soldier *>> &b, pair<int, int> location)
{

    double minimum_dist = 0;
    Soldier *closest_soldier = nullptr;
    double curr_dist = 0;

    // Traversing the whole matrix
    // to find the minimum distance.
    for (int row = 0; row < b.size(); row++)
        for (int col = 0; col < b[row].size(); col++)
        {
            // If cell contain soldier, check
            // for minimum distance.
            if (b[row][col] != nullptr && !(row == location.first && col== location.second) &&  b[row][col]->get_id() != this->get_id()  ) // take care of not  the same location
            {
                curr_dist = this->distance(location.first, row, location.second, col);
                minimum_dist = min(minimum_dist, curr_dist);
                if (curr_dist < minimum_dist)
                {
                    closest_soldier = b[row][col];
                }
            }
        }
    int curr_health_of_closest_soldier = closest_soldier->get_health_points() - this->damage;
    closest_soldier->set_health_points(curr_health_of_closest_soldier);
}