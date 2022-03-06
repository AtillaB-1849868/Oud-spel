#include "Chessboard2.h"
#include "Pawn2.h"
#include "Color2.h"
#include <iostream>

Chessboard2::Chessboard2() : m_board
{
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	{new Pawn2(11, Color::black, false), new Pawn2(11, Color::black, false), new Pawn2(11, Color::black, false),
	new Pawn2(11, Color::black, false), new Pawn2(11, Color::black, false), new Pawn2(11, Color::black, false),
	new Pawn2(11, Color::black, false), new Pawn2(11, Color::black, false)},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	{new Pawn2(1, Color::white, false), new Pawn2(1, Color::white, false), new Pawn2(1, Color::white, false),
	new Pawn2(1, Color::white, false), new Pawn2(1, Color::white, false), new Pawn2(1, Color::white, false),
	new Pawn2(1, Color::white, false), new Pawn2(1, Color::white, false)},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}
} {}


void Chessboard2::printBoard() {
	std::cout << '\n' << "  ";
	for (int i = 0; i < m_boardWidth; i++)
		std::cout << '-';
	std::cout << '\n';
	for (int k = 0; k < m_numRowCol; k++) {
		std::cout << m_numRowCol - k << " | ";
		for (int l = 0; l < m_numRowCol; l++) {
			if (m_board[k][l] == nullptr)
				std::cout << "  " << " | ";
			else if (m_board[k][l]->getPawnColor() == Color::white)
				std::cout << "PW" << " | ";
			else if (m_board[k][l]->getPawnColor() == Color::black)
				std::cout << "PB" << " | ";
		}
		std::cout << '\n' << "  ";
		for (int j = 0; j < m_boardWidth; j++)
			std::cout << '-';
		std::cout << '\n';
	}
	std::cout << "     ";
	for (int m = 0; m < m_numRowCol; m++) {
		std::cout << (char)('A' + m) << "    ";
	}
	std::cout << "\n";
}

bool Chessboard2::setPiece(std::string startPos, std::string endPos, Color turn) {
	int colStart = startPos[0] - 'A'; //get column from piece as int
	int rowStart = 7 - (startPos[1] - '1'); //get row from piece as int        
	int colEnd = endPos[0] - 'A';
	int rowEnd = 7 - (endPos[1] - '1');
	int typeStart, typeEnd;
	bool valid = false;

	typeStart = selectPiece(rowStart, colStart); //get start location
	typeEnd = selectPiece(rowEnd, colEnd); //get end location
	
	if (typeStart == 0 || typeEnd == 0)
		return false;
	if ((typeStart == 1 && turn == Color::white) || (typeStart == 11 && turn == Color::black)) //if moving Pawn						//if type fixed -> getColor == turn + type
		valid = m_board[rowStart][colStart]->checkPawnMove(typeEnd, rowStart, colStart, rowEnd, colEnd); //check validity
	
	if (valid) { //if valid: move piece
		m_board[rowStart][colStart] = nullptr;
		m_board[rowEnd][colEnd] = new Pawn2(typeStart, turn, true);
		return true;
	}
	return false;
}

bool Chessboard2::AISetPiece() {			// AI goes offmap? A and H colom dissapear during second move
	bool valid = false;
	int rowStart, colStart;
	int randomNum = rand() % 7;
	rowStart = m_AILocList[randomNum][0];
	colStart = m_AILocList[randomNum][1];
	int typePiece = selectPiece(rowStart, colStart);
	if (typePiece == 11) {
		int typeEnd = selectPiece(rowStart + 1, colStart);

		if (typeEnd == 0)
			return false;

		int typeLeftUnder = selectPiece(rowStart + 1, colStart - 1);
		if (typeLeftUnder != 0 && typeLeftUnder != -1) {
			valid = m_board[rowStart][colStart]->checkPawnMove(typeLeftUnder, rowStart, colStart, rowStart + 1, colStart + 1);
			if (valid) {
				m_board[rowStart][colStart] = nullptr;
				m_board[rowStart + 1][colStart - 1] = new Pawn2(typePiece, Color::black, true);
				return true;
			}
		}
		int typeRightUnder = selectPiece(rowStart + 1, colStart + 1);
		if (typeRightUnder != 0 && typeRightUnder != -1) {
			valid = m_board[rowStart][colStart]->checkPawnMove(typeRightUnder, rowStart, colStart, rowStart + 1, colStart - 1);
			if (valid) {
				m_board[rowStart][colStart] = nullptr;
				m_board[rowStart + 1][colStart + 1] = new Pawn2(typePiece, Color::black, true);
				return true;
			}
		}
		if (m_board[rowStart][colStart]->getHasMadeMove() == false) {
			int randomMoveNum = rand() % 2;
			int move = moves[randomMoveNum];
			typeEnd = selectPiece(rowStart, colStart + move);
			valid = m_board[rowStart][colStart]->checkPawnMove(typeEnd, rowStart, colStart, rowStart + move, colStart);
			if (valid) {
				m_board[rowStart][colStart] = nullptr;
				m_board[rowStart + move][colStart] = new Pawn2(typePiece, Color::black, true);
				return true;
			}
		}
		
		valid = m_board[rowStart][colStart]->checkPawnMove(typeEnd, rowStart, colStart, rowStart + 1, colStart);
		if (valid) {
			m_board[rowStart][colStart] = nullptr;
			m_board[rowStart + 1][colStart] = new Pawn2(typePiece, Color::black, true);
			return true;
		}
		else
			return false;
	}
	return false;
}

void Chessboard2::updateAILocList() {
	int z = 0;
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			int type = selectPiece(i, j);
			if (type != -1) {
				if (m_board[i][j]->getPawnColor() == Color::black) {
					m_AILocList[z][0] = i;
					m_AILocList[z][1] = j;
					++z;
				}
			}
			if (i == BOARDSIZE - 1 && j == BOARDSIZE - 1) {
				m_numPieces -= 1;
				m_AILocList[z][0] = -1;
				m_AILocList[z][1] = -1;
			}
			if (z == m_numPieces)
				return;
		}
	}
}

int Chessboard2::selectPiece(int row, int col) {
	if (col >= BOARDSIZE && row >= BOARDSIZE && col < 0 && row < 0) // if out of range
		return 0;
	if (m_board[row][col] == nullptr) //if empty space
		return -1;
	return m_board[row][col]->getPawnNum(); //take piece
}

bool Chessboard2::checkVictory() {
	for (int i = 0; i < BOARDSIZE; i++) {
		if (m_board[0][i] != nullptr) {
			if (m_board[0][i]->getPawnNum() == 1) { //pawns... 
				printBoard();
				return true;
			}
		}
		else if (m_board[7][i] != nullptr) {
			if (m_board[7][i]->getPawnNum() == 11) { //pawns... 
				printBoard();
				return true;
			}
		}
	}
	return false;
}