#include "Player.h"

Player::Player(int id) : m_id(id), m_playerType(PlayerType::NotEvaluated), m_location(0,0) {}

void Player::SetPlayerType(PlayerType playertype)
{
	m_playerType = playertype;
}

void Player::SetLocation(Coordinate& location)
{
	m_location.SetPositionX(location.GetPositionX());
	m_location.SetPositionY(location.GetPositionY());
}

int Player::GetID()
{
	return m_id;
}

PlayerType Player::GetPlayerType()
{
	return m_playerType;
}

Coordinate Player::GetLocation()
{
	return m_location;
}