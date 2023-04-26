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
	if (m_currentStep >= m_maxSteps)
	{
		return;
	}

	for (int x = 0; x < m_world->GetSize(); x++)
	{
		for (int y = 0; y < m_world->GetSize(); y++)
		{
			Coordinate coord(x, y);
			int cellValue = m_world->GetCellValue(coord);
			Player* currentPlayer = nullptr;

			if (cellValue != 0)
			{
				for (auto player : m_players)
				{
					if (player->GetID() == cellValue)
					{
						currentPlayer = player;
						break;
					}
				}
			}

			int liveNeighbors = m_world->CountNeighbours(coord);

			if (currentPlayer != nullptr)
			{
				if (liveNeighbors < 2 || liveNeighbors > 3)
				{
					m_world->ClearCoordinate(coord);
					m_players.erase(std::remove(m_players.begin(), m_players.end(), currentPlayer), m_players.end());
					delete currentPlayer;
				}
			}
			else
			{
				if (liveNeighbors == 3)
				{
					Player* newPlayer = CreatePlayer(0);
					m_players.push_back(newPlayer);
					m_world->AddPlayer(newPlayer, x, y);
				}
			}
		}
	}

	m_currentStep++;
}

