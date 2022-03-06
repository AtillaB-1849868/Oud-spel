#ifndef Game2_h
#define Game2_h
#include <string>

#include "Player2.h"
#include "Chessboard2.h"
#include "Color2.h"

class Game2 {
public:
	void gameMode(); //startup to select gamemode
	Game2(Color turn) : m_turn{ turn } {};
private:
	void PvPGame(); //start pvp game
	void PvEGame(); //start pve game
	bool PvPRoutine(); //loop routine till victory in pvp 
	bool PvERoutine(); //loop routine till victory in pve
	int playerMove(); //loop for player moves
	int AIMove(); //loop for ai moves
	std::string playerStartMove(); //asks player start location
	std::string playerEndMove(); //asks players end location
	void printVictory(); //prints victory depending on turn
	bool checkPiecesTaken();
	Player2 p1;
	Player2 p2;
	Chessboard2 c;
	Color m_turn;
};

#endif