#pragma once

#include <vector>
#include "Coordinate.h"
#include "Player.h"
using namespace std;

class World
{
private:
	int m_size;
	vector<int> m_worldmap;

public:
	World();
	World(int size);
	int GetMapIndex(const Coordinate& x) const;
	bool MovePlayer(const Player& p, const Coordinate& c);
	void ClearWorld();
	int GetCellValue(const Coordinate& c);
	int CountNeighbours(const Coordinate& c);
};