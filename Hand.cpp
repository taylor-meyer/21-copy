#include "Hand.h"

Hand::Hand()
{

}

void Hand::fillShoe()
{
	if (!this->values.empty())
		this->values.clear();

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

std::string Hand::printHiddenSum()
{
	int sum = 0;
	std::vector<int>::iterator itr = this->values.begin() + 1;

	while (itr != this->values.end())
	{
		sum += *itr;
		itr++;
	}

	std::ostringstream ss;
	ss << "(? + " << sum << ")";
	return ss.str();
}

std::string Hand::printHidden()
{
	std::ostringstream ss;
	ss << "? ";

	std::vector<int>::iterator itr = this->values.begin() + 1;

	while (itr != this->values.end())
	{
		ss << std::setw(3) << *itr;
		itr++;
	}

	return ss.str();
}

std::string Hand::printReveal()
{
	std::ostringstream ss;
	std::vector<int>::iterator itr = this->values.begin();

	ss << *itr++;

	while (itr != this->values.end())
	{
		ss << std::setw(3) << *itr;
		itr++;
	}

	return ss.str();
}

void Hand::clear()
{
	this->values.clear();
}