#ifndef Knight_h 
#define Knight_h 

#include "Color2.h"
#include "Type.h"
#include "Piece.h"

class Knight : public Piece {
public:
	//Color getColor() const { return m_color; }
	Type getType() const override { return m_type; }
	Knight(Color color) : Piece(color, m_type) {};
	bool checkMove(Type typeEnd, Color colorEnd, int rowStart, int colStart, int rowEnd, int colEnd) const override; //check Knight move validity  
private:
	//Color m_color;
	Type m_type = Type::knight;
	
};

#endif