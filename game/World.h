#pragma once

#include <vector>
#include "Coordinate.h"
#include "Player.h"

class World
{
private:
	int m_size;
	std::vector<int> m_worldmap;

public:
	World();
	World(int size);
	int GetSize();
	std::vector<int> GetWorldMap() const;
	int GetMapIndex(Coordinate& coord);
	void ClearWorld();
	bool MovePlayer(Player& p, Coordinate& c);
	void ClearCoordinate(Coordinate& c);
	int GetCellValue(Coordinate& c);
	int CountNeighbours(Coordinate& c);
	void AddPlayer(Player* player, int x, int y);
	//void ConvertWorldMapTo2D();
};