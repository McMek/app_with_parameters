#include "World.h"

World::World() : m_size(100), m_worldmap(10000, 0) {}

World::World(int size) : m_size(size), m_worldmap(size* size, 0) {}