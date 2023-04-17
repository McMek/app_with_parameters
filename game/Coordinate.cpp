#include <iostream>
#include <Coordinate.h>

void Coordinate::SetPosition(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Coordinate::GetPosition(int& x, int& y) const
{
    x = m_x;
    y = m_y;
}