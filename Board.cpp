#include "Board.hpp"
#include <iostream>
using namespace std;
using namespace WarGame;

Soldier *&Board::operator[](std::pair<int, int> location)
{
    return this->board[location.first][location.second];
}

Soldier *Board::operator[](std::pair<int, int> location) const
{
    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
{

    if ((*this)[source] == nullptr)
    {
        throw std::invalid_argument("There is no soldier at source location!");
    }

    if ((*this)[source]->get_id() != player_number)
    {
        throw std::invalid_argument("This soldier belongs to the second player!");
    }

    pair<int, int> target;

    switch (direction)
    {

    case Up:
        target.first = source.first + 1;
        target.second = source.second;
        break;

    case Down:
        target.first = source.first - 1;
        target.second = source.second;
    case Right:
        target.first = source.first;
        target.second = source.second + 1;
    case Left:
        target.first = source.first;
        target.second = source.second - 1;
        break;
    }

    if (target.first >= board.size() || target.first < 0 || target.second >= board.size() || target.second < 0)
    {
        throw invalid_argument("out of board's bounds!");
    }
    if ((*this)[target] != nullptr)
    {
        throw("There is already another soldier!");
    }
    board[target.first][target.second] = board[source.first][source.second];
    board[source.first][source.second] = nullptr;
    board[target.first][target.second]->activity(board, target);
}

bool Board::has_soldiers(uint player_number) const
{
    for (int i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != nullptr && board[i][j]->get_id() == player_number)
            {
                return true;
            }
        }
    }
    return false;
}