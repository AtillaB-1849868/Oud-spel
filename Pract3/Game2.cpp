#include "Game2.h"
#include "Player2.h"
#include "Color2.h"
#include <iostream>

void Game2::gameMode() {
	int gameMode;
	std::cout << "What gamemode do you want to play?\n" << "\tPvE = 1\n" << "\tPvP = 2\n";
	std::cin >> gameMode;
	if (gameMode == 2) //player chose PvP (2)
		Game2::PvPGame();
	else if (gameMode == 1) //player chose PvE (1)
		Game2::PvEGame();
	else {
		std::cout << "Why bother starting up if you can't even anwser this right?\n";
		return;
	}
	int restart;
	std::cout << "Want to play again?\n Yes = 1\n No = 0\n";
	std::cin >> restart; //not able to reset board yet
	std::cout << '\n';
	if (restart == 1){
		Game2::gameMode(); //restart the game
	}

	return;
}

void Game2::PvPGame() {
	std::string player1, player2;
	std::cout << "Player1, what is your name?\n";
	std::cin >> player1;
	std::cout << "Player2, what is your name?\n";
	std::cin >> player2;
	p1.setName(player1);
	p1.setColor(Color::white);
	p2.setName(player2);
	p2.setColor(Color::black);
	std::cout << "Use Q or q as input anytime you want to quit.\n";
	bool result = PvPRoutine();
	if (result) //check if it is a victory or a quit
		printVictory();
}

void Game2::PvEGame() {
	srand(time(NULL));
	std::string player;
	std::cout << "Player, what is your name?\n";
	std::cin >> player;
	p1.setName(player);
	p1.setColor(Color::white);
	p2.setName("AI");
	p2.setColor(Color::black);
	bool result = PvERoutine();
	if (result) //check if it is a victory or a quit
		printVictory();
}

bool Game2::PvPRoutine() {
	while (true) {
		c.printBoard();
		int num;
		num = playerMove();
		if (num == 0) //if player quit
			return false;
		if (checkPiecesTaken()) //check for victory
			return true;
		if (m_turn == Color::white)
			m_turn = Color::black;
		else
			m_turn = Color::white;
	}
	return 0;
}

bool Game2::checkPiecesTaken() {
	int afterMovePieces = c.checkPieces(m_turn);
	int currentPieces, currentScore;

	if (m_turn == Color::white){
		currentScore = p1.getScore();
		currentPieces = p2.getPieces();
		if (afterMovePieces != currentPieces) {
			p1.setScore(currentScore + 1);
			p2.setPieces(afterMovePieces);
		}
	}
	else {
		currentScore = p2.getScore();
		currentPieces = p1.getPieces();
		if (afterMovePieces != currentPieces) {
			p2.setScore(currentScore + 1);
			p1.setPieces(afterMovePieces);
		}
	}
	if (p2.getScore() == 10 || p1.getScore() == 10)
		return true;
	return false;
}

bool Game2::PvERoutine() {
	while (true) { //keep going untill a vicory or quit
		c.printBoard();
		int num;
		num = playerMove();
		if (num == 0) //if player quit
			return false;
		if (c.checkPieces(m_turn)) //check for victory
			return true;
		c.updateAILocList();
		c.printBoard();
		num = AIMove();
		if (c.checkPieces(m_turn)) {
			m_turn = Color::black;
			return true;
		}

		c.updateAILocList();
	}
}

int Game2::playerMove() {
	std::string startPos, endPos;
	bool moveMade = false;
	while (true) {
		startPos = playerStartMove();
		if (startPos == "q" || startPos == "Q")
			return 0;
		endPos = playerEndMove();
		if (endPos == "q" || endPos == "Q")
			return 0;
		moveMade = c.setPiece(startPos, endPos, m_turn);
		if (moveMade)
			return 1;
		std::cout << "Not a valid move!\n";
		c.printBoard();
	}
}

int Game2::AIMove() {
	std::string startPos, endPos;
	bool moveMade = false;
	while (true) {
		moveMade = c.AISetPiece();
		if (moveMade) {
			return 1;
		}
	}
}

std::string Game2::playerStartMove() {
	std::cout << '\n';
	if (m_turn == Color::white)
		std::cout << p1.getPlayerName();
	else
		std::cout << p2.getPlayerName();
	std::cout << ", choose a piece to move (e.g. A1): ";
	std::string pos;
	std::cin >> pos;
	return pos;
}

std::string Game2::playerEndMove() {
	std::cout << "Choose a location to place it: ";
	std::string pos;
	std::cin >> pos;
	return pos;
}

void Game2::printVictory() {
	std::cout << "Congratulations ";
	if (m_turn == Color::white) //chech who had last turn
		std::cout << p1.getPlayerName();
	else
		std::cout << p2.getPlayerName();
	std::cout << ", you won!\n";
}


/*
#ifndef GAME_H
#define GAME_H
#include "Color.h"
#include "Player.h"
#include "Board.h"

#include <iostream>
#include<string>

class Game {
public:
	void gameMode();
	Game();

private:

	bool PvE();
	bool PvP();
	std::string getMove();

	void finishGame();


	Color m_turn = Color::white;
};

#endif
*/


/*

#ifndef PLAYER_H
#define PLAYER_H

#include "Color.h"
#include <string>

class Player {
public:
	Player(Color color) : m_color(color){};
	void setColor(Color color) { m_color = color; }
	Color getColor() { return m_color; }
private:
	Color m_color;

};


#endif
*/


/*
#include "Game.h"




void Game::gameMode() {
	int gameMode;
	std::cout << "Select gamemode: \n" << "\tPvE = 1\n" << "\tPvP = 2\n";
	std::cin >> gameMode;
	if (gameMode == 1) //player chose PvP (2)
		PvE();
	else if (gameMode == 2) //player chose PvE (1)
		PvP();
	else {
		std::cout << "Wrong input, try again:\n" << "\tPvE = 1\n" << "\tPvP = 2\n";
		std::cin >> gameMode;
	}
	//reset hier?
	return;
}




bool Game::PvE() {
	Player p1(Color::white);
	bool result;
	//while (true) {

	//}
	if (result)
		finishGame(); //reset en victory?
}


bool Game::PvP() {
	Player p1(Color::white);
	Player p2(Color::white);
	bool result;
	std::string beginMove, endMove;
	while (true) {
		beginMove = getMove();
		endMove = getMove();
		bool valid = Board::checkValidMove();
	}
	if (result)
		finishGame(); //reset en victory?
}

std::string Game::getMove() {

}



*/