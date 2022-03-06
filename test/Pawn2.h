#ifndef Pawn2_h
#define Pawn2_h

#include "Color2.h"
#include "Piece.h"

class Pawn2 : public Piece {
public:
	//int getPawnNum() const { return m_pawnNum; } //moet later weg 
	//Color getColor() const { return m_color; }
	Type getType() const override { return m_type; }
	bool getHasMadeMove() const { return m_hasMadeMove; }
	void setHasMadeMove(bool hasMadeMove) override { m_hasMadeMove = hasMadeMove; }
	Pawn2(Color color, bool hasMadeMove) : Piece(color, m_type), m_hasMadeMove{ hasMadeMove } {};
	bool checkMove(Type typeEnd, Color colorEnd, int rowStart, int colStart, int rowEnd, int colEnd) const override; //check Pawn move validity  
private:
	//int m_pawnNum;
	//Color m_color;
	bool m_hasMadeMove;
	Type m_type = Type::pawn;
	
};

#endif