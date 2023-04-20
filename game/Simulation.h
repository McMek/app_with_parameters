#pragma once

#include "World.h"

class Simulation
{
private:
	const int m_randomSeed = 41;
	World* m_world;
	std::vector<Player*> m_players;
	long m_maxSteps = 5000;
	long m_currentStep = 0;

	Player* CreatePlayer(int id);
	World* CreateWorld(int worldSize);

	void PopulateWorld(int numberOfPlayers);
};