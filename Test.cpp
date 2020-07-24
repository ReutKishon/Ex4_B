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




	TEST_CASE("3 VS 3") {
	    WarGame::Board board(8,8);
	    CHECK(!board.has_soldiers(1));
	    board[{0,1}] = new FootSoldier(1);//player 1 footSoldier1 {0,1}
	   // CHECK_THROWS((board[{0,1}] = new FootSoldier(1))); //there is already soldier there
	    board[{0,0}] = new FootCommander(1); //player 1 commanderSoldier {0,0}
	    board[{0,2}] = new FootSoldier(1);//player 1 footSoldier2 {0,2}
	    CHECK(board.has_soldiers(1)); //there is no need to write this any time

	    CHECK(!board.has_soldiers(2));
	    board[{7,0}] = new FootCommander(2);//player 2 commanderSoldier {7,0}
		board[{7,1}] = new FootSoldier(2);//player 2 footSoldier1 {7,1}
	    board[{7,2}] = new FootSoldier(2);//player 2 footSoldier2 {7,2}

	    CHECK(board.has_soldiers(2));

	    board.move(1,{0,1},WarGame::Board::MoveDIR::Up); //player 2 footsoldier1 - 90
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));
	    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up)); //no soldier there
	    board.move(1,{1,1},WarGame::Board::MoveDIR::Up); //player 2 footsoldier1 - 80 
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));

	    CHECK_THROWS(board.move(2,{7,0},WarGame::Board::MoveDIR::Left)); // cant move left
	    board.move(2,{7,0},WarGame::Board::MoveDIR::Down); //player 1 commanderSoldier - 130, player 1 footsoldier1 - 70,   player 1 footsoldier2 - 90, 
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));

	    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);//player 2 commanderSoldier - 130, player 2 footsoldier1 - 70,   player 2 footsoldier2 - 90, 
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));
	    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));
	    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));
	    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));

	     board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));
	    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));
	    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));
	    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
	    CHECK(board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));

	    board.move(1,{0,2},WarGame::Board::MoveDIR::Up);
	    board.move(1,{1,2},WarGame::Board::MoveDIR::Up);
	    CHECK(!board.has_soldiers(2));
	    CHECK(board.has_soldiers(1));

		// the winner is team 1
	}









TEST_CASE("Exceptions")
{
    WarGame::Board p (6,6);
    //Out of board
    CHECK_THROWS(p.move(1, {5, 1}, WarGame::Board::Up));
    CHECK_THROWS(p.move(1, {0, 0}, WarGame::Board::Down));
    CHECK_THROWS(p.move(2, {3, 5}, WarGame::Board::Right));
    CHECK_THROWS(p.move(1, {4, 5}, WarGame::Board::Right));
    CHECK_THROWS(p.move(1, {5, 0}, WarGame::Board::Left));
    //Busy place
    CHECK_THROWS(p.move(2, {4, 0}, WarGame::Board::Up));
    CHECK_THROWS(p.move(2, {3, 0}, WarGame::Board::Up));
    CHECK_THROWS(p.move(2, {0, 3}, WarGame::Board::Up));
    CHECK_THROWS(p.move(2, {1, 3}, WarGame::Board::Down));
    CHECK_THROWS(p.move(1, {0, 1}, WarGame::Board::Left));
    // //Null Place
    CHECK_THROWS(p.move(1, {2, 0}, WarGame::Board::Up));
    CHECK_THROWS(p.move(1, {4, 3}, WarGame::Board::Up));
    CHECK_THROWS(p.move(1, {2, 2}, WarGame::Board::Down));
    CHECK_THROWS(p.move(2, {1, 0}, WarGame::Board::Right));
    CHECK_THROWS(p.move(2, {5, 4}, WarGame::Board::Left));
    // //Source out of bound
    CHECK_THROWS(p.move(1, {6, 0}, WarGame::Board::Up));
    CHECK_THROWS(p.move(1, {7, 3}, WarGame::Board::Up));
    CHECK_THROWS(p.move(1, {8, 2}, WarGame::Board::Down));
    CHECK_THROWS(p.move(2, {9, 0}, WarGame::Board::Right));
    CHECK_THROWS(p.move(2, {10, 4}, WarGame::Board::Left));
}

TEST_CASE("Sniper VS Sniper")
{ //good
    WarGame::Board board(3, 3);
    // CHECK(!board.has_soldiers(1));
    board[{0, 1}] = new Sniper(1);
    // CHECK(board.has_soldiers(1));

    // CHECK(!board.has_soldiers(2));
    board[{1, 2}] = new Sniper(2);
    // CHECK(board.has_soldiers(2));

    board.move(1, {0, 1}, WarGame::Board::MoveDIR::Up);
    // CHECK(board.has_soldiers(2));
    // CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1, {0, 1}, WarGame::Board::MoveDIR::Up));
    board.move(1, {1, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

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
