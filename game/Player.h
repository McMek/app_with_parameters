#pragma once

#include "types.h"
#include "Coordinate.h"

class Player
{
private:
	int m_id;
	PlayerType m_playerType;
	Coordinate m_location;

public:
	Player() = delete;
	Player(int id);
	
	void SetPlayertype(PlayerType playertype);
	void SetLocation(Coordinate& location);

	int GetID();
	PlayerType GetPlayerType();
	Coordinate GetLocation();
};