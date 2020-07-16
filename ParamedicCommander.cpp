#include "ParamedicCommander.hpp"

void ParamedicCommander::activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location)
{

    uint initial_health_points = 0;

    if (location.first + 1 < b.size() && location.first + 1 >= 0 && location.second < b[location.first + 1].size() && location.second >= 0 && b[location.first + 1][location.second] != nullptr)
    {
        initial_health_points = b[location.first + 1][location.second]->get_initial_health_points();
        b[location.first + 1][location.second]->set_health_points(initial_health_points);
    }

    if (location.first - 1 < b.size() && location.first - 1 >= 0 && location.second < b[location.first - 1].size() && location.second >= 0 && b[location.first - 1][location.second] != nullptr)
    {
        initial_health_points = b[location.first - 1][location.second]->get_initial_health_points();
        b[location.first - 1][location.second]->set_health_points(initial_health_points);
    }

    if (location.first < b.size() && location.first >= 0 && location.second + 1 < b[location.first].size() && location.second + 1 >= 0 && b[location.first][location.second + 1] != nullptr)
    {
        initial_health_points = b[location.first][location.second + 1]->get_initial_health_points();
        b[location.first][location.second + 1]->set_health_points(initial_health_points);
    }

    if (location.first < b.size() && location.first >= 0 && location.second - 1 < b[location.first].size() && location.second - 1 >= 0 && b[location.first][location.second - 1] != nullptr)
    {
        initial_health_points = b[location.first][location.second - 1]->get_initial_health_points();
        b[location.first][location.second - 1]->set_health_points(initial_health_points);
    }
    // wake up all the paramedic
    for (int row = 0; row < b.size(); row++)
        for (int col = 0; col < b[row].size(); col++)
        {
            if (b[row][col] != nullptr && b[row][col]->get_name() == "Paramedic" && b[row][col]->get_id() == this->get_id())
            {
                b[row][col]->activity(b, {row, col});
            }
        }
}