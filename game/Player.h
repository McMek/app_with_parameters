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
	
	void setPlayertype(PlayerType playertype);
	void setLocation(Coordinate& location);

	int getID();
	PlayerType getPlayerType();
	Coordinate getLocation();
};