#include "World.h"
using namespace std;

World::World() : m_size(100), m_worldmap(10000, 0) {}

World::World(int size) 
{
	if (size < 50)
	{
		size = 50;
	}
	else if (size > 1000)
	{
		size = 1000;
	}

	m_size = size;
	m_worldmap.resize(size * size);
}

int World::getSize() const
{
	return m_size;
}

vector<int> World::getWorldMap() const
{
	return m_worldmap;
}

int World::GetMapIndex (const Coordinate& coord) const
{
	int x = coord.GetPositionX();
	int y = coord.GetPositionY();

	return y * m_size + x;
}

void World::ClearWorld()
{
	fill(m_worldmap.begin(), m_worldmap.end(), 0);
}

bool World::MovePlayer(const Player& p, const Coordinate& c)
{
	int index = GetMapIndex(c);

	if (index < 0 || index >= m_worldmap.size())
	{
		return false;
	}

	if (m_worldmap[index] != 0)
	{
		return false;
	}

	for (int i = 0; i < m_worldmap.size(); i++)
	{
		if (m_worldmap[i] == p.getID())
		{
			m_worldmap[i] = 0;
			break;
		}
	}

	m_worldmap[index] = p.getID();

	return true;
}

void World::ClearCoordinate(const Coordinate& c)
{
	int index = GetMapIndex(c);

	if (index >= 0 && index < m_worldmap.size())
	{
		m_worldmap[index] = 0;
	}
}

int World::GetCellValue(const Coordinate& c)
{
	int index = GetMapIndex(c);

	if (index >= 0 && index < m_worldmap.size())
	{
		return m_worldmap[index];
	}
	else
	{
		return -1;
	}
}

int World::CountNeighbours(const Coordinate& c)
{
	int count = 0;

	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (dx == 0 && dy == 0)
				continue;

			Coordinate neighbour
			{
				c.GetPositionX() + dx, c.GetPositionY() + dy
			};

			int index = GetMapIndex(neighbour);

			if (index >= 0 && index < m_worldmap.size())
			{
				if (m_worldmap[index] != 0)
				{
					count++;
				}
			}
		}
	}

	return count;
}