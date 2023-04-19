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
	int getSize() const;
	vector<int> getWorldMap() const;
	int GetMapIndex(const Coordinate& coord) const;
	void ClearWorld();
	bool MovePlayer(const Player& p, const Coordinate& c);
	void ClearCoordinate(const Coordinate& c);
	int GetCellValue(const Coordinate& c);

	int CountNeighbours(const Coordinate& c);
};