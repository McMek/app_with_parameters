#pragma once

class Coordinate
{
private:
    int m_x;
    int m_y;

public:
    Coordinate();
    Coordinate(int x, int y);
    void SetPositionX(int x);
    void SetPositionY(int y);
    int GetPositionX();
    int GetPositionY();
};