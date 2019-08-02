#include "Player.h"

Player::Player() {}

Player::Player(std::string username, int wins, int loss) :
	username(username),
	wins(wins),
	loss(loss) {}

std::string Player::getUsername()
{
	return this->username;
}

int Player::getWins()
{
	return this->wins;
}

int Player::getLosses()
{
	return this->loss;
}

void Player::setUsername(std::string username)
{
	this->username = username;
}

void Player::setWins(int wins)
{
	this->wins = wins;
}

void Player::setLosses(int loss)
{
	this->loss = loss;
}

void Player::incrementWins()
{
	this->wins++;
}

void Player::incrementLoss()
{
	this->loss++;
}