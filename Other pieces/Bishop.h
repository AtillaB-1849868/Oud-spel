#ifndef Bishop_h 
#define Bishop_h 

#include "Color2.h"
#include "Type.h"

class Bishop {
public:
	Color getBishopColor() const { return m_Color; }

	Bishop(Type type, Color Color) : m_Type{ type }, m_Color{ Color } {};
	bool checkBishopMove(int typeEnd, int rowStart, int colStart, int rowEnd, int colEnd); //type in checkXMove weg doen? 

private:
	Color m_Color;
	Type m_Type = Type::bishop;



	/*
	* FOR AI?
	int m_moves[56][2] = { {1 , 0}, {2 , 0}, {3 , 0}, {4 , 0}, {5 , 0}, {6 , 0}, {7 , 0},
						{-1 , 0}, {-2 , 0}, {-3 , 0}, {-4 , 0}, {-5 , 0}, {-6 , 0}, {-7 , 0},


						{-1 , 1}, {-2 , 2}, {-3 , 3}, {-4 , 4}, {-5 , 5}, {-6 , 6}, {-7 , 7},
						{-1 , -1}, {-2 , -2}, {-3 , -3}, {-4 , -4}, {-5 , -5}, {-6 , -6}, {-7 , -7},


						{1 , 1}, {2 , 2}, {3 , 3}, {4 , 4}, {5 , 5}, {6 , 6}, {7 , 7},
						{1 , -1}, {2 , -2}, {3 , -3}, {4 , -4}, {5 , -5}, {6 , -6}, {7 , -7},


						{0 , 1}, {0 , 2}, {0 , 3}, {0 , 4}, {0 , 5}, {0 , 6}, {0 , 7},
						{0 , -1}, {0 , -2}, {0 , -3}, {0 , -4}, {0 , -5}, {0 , -6}, {0 , -7}
						 };



	if (rowDiff
	*/
};

#endif