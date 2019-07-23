/*

Code started:
07/23/2019

Last edit:
07/23/2019

I was playing the 21 dlc for Resident Evil 7
and thought, "I can probably re-create this!"

I'll start with text base, and then I can use this
as a way to learn unity and get some 2D graphics going!

:)

*/

#include <iostream>
#include <string>
#include <vector> // might need

// Function prototypes
int menu();


int main()
{
	// Print the introduction
	std::string intro = "Welcome to my recreation of 21 from the "
		"Resident Evil 7 DLC.\nEverything is bare bones for now, "
		"but I will do my best to implement the rest of the features!\n";

	std::cout << intro << std::endl;

	switch (menu())
	{
	// Play a round
	case 1:
		std::cout << "user chose play a round\n";
		break;

	// Exit
	case 0:
		exit(0);

	default:
		std::cout << "user entered something bad\n";
	}


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