#ifndef Queen_h 
#define Queen_h 

#include "Color2.h"
#include "Type.h"
#include "Piece.h"

class Queen : public Piece {
public:
	//Color getColor() const { return m_color; }
	Type getType() const override { return m_type; }
	Queen(Color color) : Piece(color, m_type) {};
	bool checkMove(Type typeEnd, Color colorEnd, int rowStart, int colStart, int rowEnd, int colEnd) const override; //check Queen move validity   
private:
	//Color m_color;
	Type m_type = Type::queen;
	

	/*
	* prototype for AI, future...

	int m_moves[56][2] = { {1 , 0}, {2 , 0}, {3 , 0}, {4 , 0}, {5 , 0}, {6 , 0}, {7 , 0},
						{-1 , 0}, {-2 , 0}, {-3 , 0}, {-4 , 0}, {-5 , 0}, {-6 , 0}, {-7 , 0},
						{-1 , 1}, {-2 , 2}, {-3 , 3}, {-4 , 4}, {-5 , 5}, {-6 , 6}, {-7 , 7},
						{-1 , -1}, {-2 , -2}, {-3 , -3}, {-4 , -4}, {-5 , -5}, {-6 , -6}, {-7 , -7},
						{1 , 1}, {2 , 2}, {3 , 3}, {4 , 4}, {5 , 5}, {6 , 6}, {7 , 7},
						{1 , -1}, {2 , -2}, {3 , -3}, {4 , -4}, {5 , -5}, {6 , -6}, {7 , -7},
						{0 , 1}, {0 , 2}, {0 , 3}, {0 , 4}, {0 , 5}, {0 , 6}, {0 , 7},
						{0 , -1}, {0 , -2}, {0 , -3}, {0 , -4}, {0 , -5}, {0 , -6}, {0 , -7}
						 };
	*/
};

#endif