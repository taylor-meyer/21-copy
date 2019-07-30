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

void Hand::removeCard(int value)
{
	std::vector<int>::iterator itr = this->values.begin();
	while (itr != this->values.end())
	{
		if (*itr == value)
		{
			this->values.erase(itr);
			break;
		}
		itr++;
	}
}

int Hand::dealCard()
{
	int r = rand() % 11 + 1; // 1 to 11, inclusive
	this->removeCard(r);
	return r;
}

std::string Hand::toString()
{
	std::ostringstream ss;

	for (int v : this->values)
		ss << std::setw(3) << v;

	return ss.str();
}