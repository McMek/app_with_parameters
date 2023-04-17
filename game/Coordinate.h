#pragma once

class Coordinate
{
private:
    int m_x;
    int m_y;

public:
    void SetPosition(int x, int y);
    void GetPosition(int& x, int& y) const;
};