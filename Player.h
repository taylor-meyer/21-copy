#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
private:
	std::string username;
	int wins;
	int loss;
public:
	Player();
	Player(std::string, int, int);
	std::string getUsername();
	int getWins();
	int getLosses();
	void setUsername(std::string);
	void setWins(int);
	void setLosses(int);
	void incrementWins();
	void incrementLoss();
};
#endif
