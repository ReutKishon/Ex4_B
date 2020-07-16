#include "Board.original.hpp"
using namespace std;
using namespace WarGame;

Soldier *&operator[](std::pair<int, int> location);
{
    return this->board[location.first][location.second];
}

Soldier *Board::operator[](std::pair<int, int> location) const
{
    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
{
    // Soldier *s = (*this)[source];

    // if (s == nullptr || player_number != s->get_player_id())
    // {
    //     throw std::invalid_argument("illegal argument!");
    // }

    // pair<int, int> target;

    // switch (direction)
    // {
    //     if (target.first >= board.size() || target.first < 0 || target.second >= board.size() || target.second < 0)
    //     {
    //         throw invalid_argument("out of board's bounds!");
    //     }

    // case Up:
    //     target.first = source.first + 1;
    //     target.second = source.second;
    //     break;

    // case Down:
    //     target.first = source.first - 1;
    //     target.second = source.second;
    // case Right:
    //     target.first = source.first;
    //     target.second = source.second + 1;
    // case Left:
    //     target.first = source.first;
    //     target.second = source.second - 1;
    //     break;
    // }
    // // if ((*this)[target] != nullptr)
    // {
    //     throw("There is already another soldier!");
    // }
    // (*this)[target] = s;
    // (*this)[source] = nullptr;
    // s->attack();
    return;
}

bool Board::has_soldiers(uint player_number) const
{
    for (int i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[i].size(); j++)
        {
            Soldier *s = (*this)[{i, j}];
            if (s != nullptr && s->get_player_id() == player_number)
            {
                return true;
            }
        }
    }
    return false;
}