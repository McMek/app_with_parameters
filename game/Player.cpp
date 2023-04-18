#include "Player.h"

Player::Player(int id) : m_id(id) {}

void Player::setPlayertype(PlayerType playertype)
{
	m_playerType = playertype;
}

void Player::setLocation(const Coordinate& location)
{
	m_location = location;
}

int Player::getID() const
{
	return m_id;
}

PlayerType Player::getPlayerType() const
{
	return m_playerType;
}

Coordinate Player::getLocation() const
{
	return m_location;
}