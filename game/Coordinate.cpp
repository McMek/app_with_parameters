#include "Coordinate.h"

Coordinate::Coordinate(int x, int y) : m_x(x), m_y(y) {}

void Coordinate::SetPositionX(int x)
{
    m_x = x;
}

void Coordinate::SetPositionY(int y)
{
    m_y = y;
}

int Coordinate::GetPositionX()
{
    return m_x;
}

int Coordinate::GetPositionY()
{
    return m_y;
}