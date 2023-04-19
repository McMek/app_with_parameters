#include "Player.h"

Player::Player(int id) : m_id(id), m_location(0,0) {}

void Player::setPlayertype(PlayerType playertype)
{
	m_playerType = playertype;
}

void Player::setLocation(Coordinate& location)
{
	m_location = location;
}

int Player::getID()
{
	return m_id;
}

PlayerType Player::getPlayerType()
{
	return m_playerType;
}

Coordinate Player::getLocation()
{
	return m_location;
}