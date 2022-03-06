#ifndef Piece_h
#define Piece_h
#include "Type.h"
#include "Color2.h"

class Piece {
public:
    virtual Type getType() const { return m_type; }
    Color getColor() const { return m_color; }

    //int getPawnNum() const { return m_pawnNum; }
    bool getHasMadeMove() const { return m_hasMadeMove; }
    virtual void setHasMadeMove(bool hasMoveMade) { m_hasMadeMove = hasMoveMade; }
    virtual bool checkMove(Type typeEnd, Color colorEnd, int rowStart, int colStart, int rowEnd, int colEnd) const { return false; }
protected:
    Piece(Color color, Type type) : m_color(color), m_type(type) {};
private:
    bool m_hasMadeMove;
    Type m_type;
    Color m_color;
    //int m_pawnNum;
};

#endif