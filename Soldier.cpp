
#include "Soldier.hpp"

double Soldier::distance(int x1, int x2, int y1, int y2) //(x1,y1) , (x2,y2)
{
    return sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

Soldier *Soldier::Take_Hit(int damage_points, vector<vector<Soldier *>> &b, std::pair<int, int> location)
{
    this->health_points -= damage_points;
    if (health_points <= 0)
    {
        b[location.first][location.second] = nullptr;
    }

    return this;
}
// setters and getters:

void Soldier::set_health_points(uint health_points)
{
    this->health_points = health_points;
}
uint Soldier::get_id()
{
    return player_id;
}
uint Soldier::get_health_points()
{
    return this->health_points;
}
uint Soldier::get_initial_health_points()
{
    return initial_health_points;
}
string Soldier::get_name()
{
    return name_of_soldier;
}

uint Soldier::get_damage_points()
{
    return damage_per_activity;
}