/*

Code started:
07/23/2019

Last edit:
07/30/2019

I was playing the 21 dlc for Resident Evil 7
and thought, "I can probably re-create this!"

I'll start with text base, and then I can use this
as a way to learn unity and get some 2D graphics going!

:)

*/

#include "Hand.h"
#include <iostream>
#include <time.h>

// Function prototypes
int menu();


int main()
{
	srand(time(NULL));
	// Introduction
	std::string intro = "Welcome to my recreation of 21 from the "
		"Resident Evil 7 DLC.\nEverything is bare bones for now, "
		"but I will do my best to implement the rest of the features!\n";

	// Rules
	std::string rules = "";

	std::cout << intro << std::endl << rules << std::endl;

	Hand shoe;
	shoe.fillShoe();
	std::cout << "Shoe:\n" << shoe.toString() << std::endl << std::endl;

	Hand p1;
	std::cout << "P1:\n" << p1.toString() << std::endl << std::endl;

	Hand p2;
	std::cout << "P2:\n" << p2.toString() << std::endl << std::endl;

	std::cout << "---\n\n";

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			p1.pushCard(shoe.dealCard());
		else
			p2.pushCard(shoe.dealCard());
	}




	std::cout << "Shoe:\n" << shoe.toString() << std::endl << std::endl;

	std::cout << "P1:\n" << p1.toString() << std::endl << std::endl;

	std::cout << "P2:\n" << p2.toString() << std::endl << std::endl;


	// sys(pause) is bad practice but we are just playing for now
	system("PAUSE");


}

// Prints the menu and returns what user wants to do in form of an integer
int menu()
{
	int choice = 0;

	std::string menu =
		"1) Play a round.\n"
		"0) Exit\n"
		"Enter: ";
	std::cout << menu;

	std::cin >> choice;

	return choice;
}