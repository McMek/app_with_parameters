#include "Simulation.h"

Player* Simulation::CreatePlayer(int id)
{
	Player* player = new Player(id);
	return player;
}

World* Simulation::CreateWorld(int worldSize)
{
	World* world = new World(worldSize);
	return world;
}

void Simulation::PopulateWorld(int numberOfPlayers)
{
	srand(m_randomSeed);
	for (int i = 0; i < numberOfPlayers; i++)
	{
		Player* player = CreatePlayer(i);
		m_players.push_back(player);
		int x = rand() % m_world->GetSize();
		int y = rand() % m_world->GetSize();
		m_world->AddPlayer(player, x, y);
	}
}

void Simulation::ResetSimulation(int worldSize, long maxSteps, int numberOfPlayers)
{
	if (m_world != nullptr)
	{
		delete m_world;
		m_world = nullptr;
	}

	for (Player* player : m_players)
	{
		delete player;
	}

	m_players.clear();

	m_world = CreateWorld(worldSize);
	PopulateWorld(numberOfPlayers);

	m_maxSteps = maxSteps;
	m_currentStep = 0;
}

long Simulation::GetMaxSteps() const
{
	return m_maxSteps;
}

long Simulation::GetCurrentStep() const
{
	return m_currentStep;
}

bool Simulation::IsEndOfSimulation()
{
	return m_currentStep >= m_maxSteps;
}

void Simulation::GetNextEvolution()
{
	m_currentStep++;

	World* currentWorld = m_world;
	World* nextWorld = new World(currentWorld->GetSize());

	for (int i = 0; i < currentWorld->GetSize(); i++)
	{
		for (int j = 0; j < currentWorld->GetSize(); j++)
		{
			Coordinate currentLoc(i, j);

			int numNeighbors = currentWorld->CountNeighbours(currentLoc);
			PlayerType newType = player->GetPlayerType();

			if (player->GetPlayerType() == PlayerType::Alive)
			{
				if (numNeighbors <= 1 || numNeighbors >= 4)
				{
					newType = PlayerType::Dead;
				}
			}
			else if (player->GetPlayerType() == PlayerType::Dead)
			{
				if (numNeighbors == 3)
				{
					newType = PlayerType::Alive;
				}
			}

			nextWorld->SetPlayertype(currentLoc, newType);
		}
	}

	delete currentWorld;
	m_world = nextWorld;
}

