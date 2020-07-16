#include "SniperCommander.hpp"

void SniperCommander::activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location)
{

    for (int row = 0; row < b.size(); row++)
        for (int col = 0; col < b[row].size(); col++)
        {
            Soldier *s b[row][col];
            if (s !=nullptr && s->get_name()  == "Sniper" && s->get_id == this->get_id())
            {
                s->activity(b,{row,col});
            }
            

        }
}