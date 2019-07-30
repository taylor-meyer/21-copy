#ifndef HAND_H
#define HAND_H

#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <vector>

class Hand
{
private:
	std::vector<int> values;
public:
	Hand();
	void fillShoe();
	void pushCard(int);
	void removeCard(int);
	int dealCard();
	int sum();
	std::string toString();
};
#endif