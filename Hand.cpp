#include "Hand.h"

Hand::Hand()
{

}

void Hand::fillShoe()
{
	for (int i = 1; i < 12; i++)
	{
		this->values.push_back(i);
	}
}

void Hand::pushCard(int value)
{
	this->values.push_back(value);
}

int Hand::dealCard()
{
	// Assigns card a value from vector based on random index, 0 - sizeof(values)
	int r = rand() % this->values.size();
	int card = this->values[r];
	// Remove that from vector
	this->values.erase(this->values.begin() + r);
	// Return
	return card;
}

int Hand::sum()
{
	int sum = 0;
	std::vector<int>::iterator itr = this->values.begin();
	while (itr != this->values.end())
	{
		sum += *itr;
		itr++;
	}
	return sum;
}

std::string Hand::toString()
{
	std::ostringstream ss;

	for (int v : this->values)
		ss << std::setw(3) << v;

	return ss.str();
}