#pragma once

#include <vector>
#include "World.h"
#include "Player.h"

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

public:
	Simulation() = delete;
	void ResetSimulation(int worldSize, long maxSteps, int numberOfPlayers);
	long GetMaxSteps() const;
	long GetCurrentStep() const;
	bool IsEndOfSimulation();
	World* GetNextEvolution();
};