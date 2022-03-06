#ifndef Player2_h
#define Player2_h

#include <string>
#include "Color2.h"
#include "Chessboard2.h"

class Player2 {
public:
	//constructor voor naam and stuff
	void setName(std::string name) { m_name = name; }
	void setColor(Color color) { m_color = color; }
	void setScore(int score) { m_score = score; }
	void setPieces(int pieces) { m_piecesLeft = pieces; }
	Color getPlayerColor() const { return m_color; }
	std::string getPlayerName() const { return m_name; }
	int getPieces() const { return m_piecesLeft; }
	int getScore() const { return m_score; }
private:
	std::string m_name;
	Color m_color;
	int m_score = 0;
	int m_piecesLeft = 13;
};

#endif