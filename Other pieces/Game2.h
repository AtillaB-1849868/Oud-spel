#ifndef Game2_h
#define Game2_h
#include <string>

#include "Player2.h"
#include "Chessboard2.h"
#include "Color2.h"

class Game2 {
public:
	void gameMode();
	Game2(Color turn) : m_turn { turn } {};
private:
	void PvPGame();
	void PvEGame();
	bool PvPRoutine();
	bool PvERoutine();
	int playerMove();
	int AIMove();
	std::string playerStartMove();
	std::string playerEndMove();
	void printVictory();
	Player2 p1;
	Player2 p2;
	Chessboard2 c;
	Color m_turn;
};

#endif