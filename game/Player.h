#pragma once

#include "Coordinate.h"
#include "types.h"

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
	void setLocation(const Coordinate& location);

	int getID() const;
	PlayerType getPlayerType() const;
	Coordinate getLocation() const;
};