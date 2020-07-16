#include <iostream>
#include <vector>
using namespace std;
class Soldier
{
private:
    uint player_id;
    string name_of_soldier;
    uint initial_health_points;
    uint health_points;


    double distance(int x1, int x2, int y1, int y2) //(x1,y1) , (x2,y2)
    {
        return sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));
    }

public:
    Soldier(uint player_id, uint health_points, string name) : player_id(player_id), initial_health_points(health_points), health_points(health_points),
                                                               name_of_soldier(name)
    {
        cout << "initial Soldier" << endl;
    }
    void virtual void activity(std::vector<std::vector<Soldier *>> &b, std::pair<int, int> location) = 0;
    Soldier *Take_Hit(int damage_points, vector<vector<Soldier *>> &b, std::pair<int, int> location)
    {
        this->health_points -= damage_points;
        if (health_points <= 0)
        {
            b[location.first][location.second] = nullptr;
        }
        // if (this->HP > this->Maximum_Health)
        // {
        //     this->HP = this->Maximum_Health;
        // }
        return this;
    }
    void set_health_points(uint health_points);
    string get_name();
    uint get_id();
    uint get_initial_health_points();
    uint get_health_points();

    virtual ~Soldier() {}
};

uint Soldier::get_id()
{
    return player_id;
}
void Soldier::set_health_points(uint health_points)
{
    this->health_points = health_points;
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