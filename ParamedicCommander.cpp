#include "ParamedicCommander.hpp"

void ParamedicCommander::activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location)
{

    for (int row = 0; row < b.size(); row++)
        for (int col = 0; col < b[row].size(); col++)
        {
            if (b[row][col] != nullptr && b[row][col]->get_name() == "Paramedic" && b[row][col]->get_id() == this->get_id())
            {
                b[row][col]->activity(b, {row, col});
            }
        }
}