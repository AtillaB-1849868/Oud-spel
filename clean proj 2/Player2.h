#ifndef Player2_h
#define Player2_h

#include <string>
#include "Color2.h"
#include "Chessboard2.h"

class Player2 {
public:
	//Player2(std::string name, Color color) : m_name{ name }, m_color{ color } {};
	void setName(std::string name) { m_name = name; }
	void setColor(Color color) { m_color = color; }
	Color getPlayerColor() const { return m_color; }
	std::string getPlayerName() const { return m_name; }
private:
	std::string m_name;
	Color m_color;
};

#endif