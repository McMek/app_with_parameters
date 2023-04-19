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
	int getSize();
	vector<int> getWorldMap() const;
	int GetMapIndex(Coordinate& coord);
	void ClearWorld();
	bool MovePlayer(Player& p, Coordinate& c);
	void ClearCoordinate(Coordinate& c);
	int GetCellValue(Coordinate& c);
	int CountNeighbours(Coordinate& c);
};