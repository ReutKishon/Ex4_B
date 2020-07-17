#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include "FootCommander.hpp"

void FootCommander::activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location)
{

    double minimum_dist = INT64_MAX;
    Soldier *closest_soldier = nullptr;
    double curr_dist = 0;
    pair<int,int> closest_location;

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
                if (curr_dist < minimum_dist)
                {
                    closest_soldier = b[row][col];
                    minimum_dist = curr_dist;
                    closest_location = current_location;
                }
            }
        }
    if (closest_soldier != nullptr)
    {
        uint health_points_after_injury = closest_soldier->get_health_points() - this->get_damage_points();
        closest_soldier->set_health_points(health_points_after_injury);
        if (health_points_after_injury <= 0)
        {
            b[closest_location.first][closest_location.second] = nullptr;
        }
    }

    // wake up the other to attack

    for (row = 0; row < b.size(); row++)
        for (col = 0; col < b[row].size(); col++)
        {

            if (b[row][col] != nullptr && b[row][col]->get_name() == "FootSoldier" && b[row][col]->get_id() == this->get_id())
            {
                b[row][col]->activity(b, {row, col});
            }
        }
}