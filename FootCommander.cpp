#include "FootCommander.hpp"

void FootCommander::activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location)
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
    closest_soldier->Take_Hit(this->get_damage_points(), b, {row, col});
}

// wake up the other to attack

for (int row = 0; row < b.size(); row++)
    for (int col = 0; col < b[row].size(); col++)
    {

        if (b[row][col] != nullptr && b[row][col]->get_name() == "FootSoldier" && b[row][col]->get_id() == this->get_id())
        {
            b[row][col]->activity(b, {row, col});
        }
    }
}