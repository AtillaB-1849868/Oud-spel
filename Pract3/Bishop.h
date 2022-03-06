#ifndef Bishop_h 
#define Bishop_h 

#include "Color2.h"
#include "Type.h"
#include "Piece.h"
#include "Chessboard2.h"

class Bishop : public Piece{
public:
	
	Bishop(Color color) : Piece(color, m_type) {};
	//Color getColor() const { return m_color; }
	Type getType() const override { return m_type; }

	bool checkMove(Type typeEnd, Color colorEnd, int rowStart, int colStart, int rowEnd, int colEnd, const Piece* board[8][8]) const override; //check Bishop move validity 
private:
	//Color m_color;
	Type m_type = Type::bishop;
	

};

#endif