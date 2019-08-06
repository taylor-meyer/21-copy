#include "Player.h"

Player::Player() {}

Player::Player(std::string username, int wins, int loss) :
	username(username),
	wins(wins),
	loss(loss),
	fingers(5) {}

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

int Player::getFingers()
{
	return this->fingers;
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

void Player::setFingers(int fingers)
{
	this->fingers = fingers;
}

void Player::incrementWins()
{
	this->wins++;
}

void Player::incrementLoss()
{
	this->loss++;
}

void Player::loseFinger()
{
	this->fingers--;
}