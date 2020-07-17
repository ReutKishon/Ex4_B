#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <iostream>
#include <stdexcept>

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>

TEST_CASE("Test 1: Sniper vs FootSoldier:")
{
    WarGame::Board board(5, 5);
    board[{0, 0}] = new Sniper(1);      //player 1
    board[{4, 4}] = new FootSoldier(2); //player 2
    //Sniper moves

    board.move(1, {0, 0}, WarGame::Board::Right);
    // CHECK(board.has_soldiers(1));
    // CHECK(board.has_soldiers(2));
    board.move(1, {0, 1}, WarGame::Board::Up);
    //     // CHECK(board.has_soldiers(1));
    //     // CHECK(board.has_soldiers(2));
    board.move(1, {1, 1}, WarGame::Board::Up);
    // CHECK(board.has_soldiers(1));
    // CHECK(board.has_soldiers(2));
    board.move(1, {2, 1}, WarGame::Board::Up); // moves to {3,1}
    // CHECK(board.has_soldiers(1));
    // CHECK(board.has_soldiers(2));
    //FootSoldier moves (player 2)
    CHECK_THROWS(board.move(2, {4, 4}, WarGame::Board::Right));
    CHECK_THROWS(board.move(2, {4, 4}, WarGame::Board::Up));

    CHECK_THROWS(board.move(2, {4, 4}, WarGame::Board::Left)); // was killed
    //     // CHECK(board.has_soldiers(1));
    //     // CHECK(board.has_soldiers(2));
    board.move(1, {3, 1}, WarGame::Board::Left); // to {3,0}
    //     // CHECK(board.has_soldiers(1));
    //     // CHECK(board.has_soldiers(2));
    board.move(1, {3, 0}, WarGame::Board::Down); // to {2,0}
    //     // CHECK(board.has_soldiers(1));
    //     // CHECK(board.has_soldiers(2));
    CHECK_THROWS(board.move(2, {3, 2}, WarGame::Board::Left)); // player 1 in in that place!
    //     // CHECK(board.has_soldiers(1));
    //     // CHECK(board.has_soldiers(2));
    CHECK_THROWS(board.move(2, {3, 2}, WarGame::Board::Down));
    //     // CHECK(board.has_soldiers(1));
    //     // CHECK(board.has_soldiers(2));
    // } //23
}

TEST_CASE("Test 2: FootSoldier vs FootSoldier:")
{
    WarGame::Board board(5, 5);
    board[{1, 0}] = new FootSoldier(1); //player 1
    board[{3, 4}] = new FootSoldier(2); //player 2
    //Sniper moves
    CHECK_THROWS(board.move(1, {1, 0}, WarGame::Board::Left));

    board.move(1, {1, 0}, WarGame::Board::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1, 1}, WarGame::Board::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {2, 1}, WarGame::Board::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {2, 2}, WarGame::Board::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {3, 2}, WarGame::Board::Up); // moves to {4,2}
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    //FootSoldier moves (player 2)
    CHECK_THROWS(board.move(2, {3, 4}, WarGame::Board::Right));

    board.move(2, {3, 4}, WarGame::Board::Left);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {3, 3}, WarGame::Board::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {4, 3}, WarGame::Board::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {3, 3}, WarGame::Board::Left);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    CHECK_THROWS(board.move(2, {3, 2}, WarGame::Board::Up)); // player 1 in in that place!
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {3, 2}, WarGame::Board::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
} //25

TEST_CASE("Test 3: 3 soldiers vs 3 soldiers")
{

    WarGame::Board board(6, 6);
    //player 1 soldiers
    board[{0, 0}] = new FootSoldier(1);
    board[{1, 0}] = new Sniper(1);
    board[{2, 2}] = new Sniper(1);
    //player 2 soldiers
    board[{1, 5}] = new FootSoldier(2);
    board[{5, 1}] = new Paramedic(2);
    board[{3, 3}] = new Sniper(2);

    CHECK_THROWS(board.move(1, {0, 0}, WarGame::Board::Left));
    CHECK_THROWS(board.move(1, {0, 0}, WarGame::Board::Down));
    CHECK_THROWS(board.move(1, {1, 0}, WarGame::Board::Left));
    CHECK_THROWS(board.move(2, {1, 5}, WarGame::Board::Right));
    // CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::Up));

    board.move(1, {0, 0}, WarGame::Board::Right); //{0,1}
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {2, 2}, WarGame::Board::Left); //{2,1}
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {2, 1}, WarGame::Board::Up); //{3,1}
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {1, 5}, WarGame::Board::Left); //{1,4}
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {5, 1}, WarGame::Board::Down); //{4,1}
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {3, 3}, WarGame::Board::Right); //{3,4}
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    CHECK_THROWS(board.move(2, {3, 3}, WarGame::Board::Left)); //{3,2}
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    CHECK_THROWS(board.move(2, {3, 2}, WarGame::Board::Left)); //{3,1}
    CHECK_THROWS(board.move(1, {3, 1}, WarGame::Board::Up));   //{4,1}
    board.move(1, {3, 1}, WarGame::Board::Left);               //{3,0}
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
} //25
