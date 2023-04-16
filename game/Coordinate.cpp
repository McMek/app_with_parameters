#include <iostream>
#include <Coordinate.h>

class Coordinate
{
private:
	int m_x;
	int m_y;

public:

	void setPosition(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	void getPosition(int &x, int &y)
	{
		x = m_x;
		y = m_y;
	}
};