// #include <iostream>
using namespace std;
class Soldier
{
private:
    uint player_id;
    uint initial_health_points;
    uint damage_points;

public:
    Soldier(uint player_id, uint health_points, uint damage_points) : player_id(player_id), initial_health_points(health_points), damage_points(damage_points)
    {
        cout << "initial Soldier" << endl;
    }
    virtual void activity() {}
    virtual ~Soldier() {}
};
