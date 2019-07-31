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
#include <thread> //std::this_thread::sleep_for
#include <chrono> //std::chrono::seconds

// Function prototypes
int menu();


int main()
{
	// Seed random
	srand(time(NULL));

	// Introduction
	std::string intro = "Welcome to my recreation of 21 from the "
		"Resident Evil 7 DLC.\nEverything is bare bones for now, "
		"but I will do my best to implement the rest of the features!\n";
	// Rules
	std::string rules = "Computer opponent will stay on 17 and will not reveal their hand until you stay or bust.\n"
		"If both you and opponent bust, smaller count wins.\n";
	// Printout
	std::cout << intro << rules << std::endl;

	// Declare shoe and players
	Hand shoe; shoe.fillShoe(); // Shoe with all cards loaded
	Hand p1; // Player
	Hand opp; // Opponent

	// Menu
	switch (menu())
	{
	case 1:

		// Deal player, opp, player, opp
		p1.pushCard(shoe.dealCard());
		opp.pushCard(shoe.dealCard());
		p1.pushCard(shoe.dealCard());
		opp.pushCard(shoe.dealCard());

		// Show what player has to start
		std::cout << "P1:\n" << p1.printReveal() << "\n   Sum: " << p1.sum() << std::endl << std::endl;

		// Loop will break when player stays or busts.
		while (true)
		{
			if (p1.sum() > 21) // Break if bust
				break;
			int hitorstay;
			std::cout << "Enter 1 to hit (anything else to stay): ";
			std::cin >> hitorstay; // Ask to hit or stay
			if (hitorstay != 1)
				break; // Break if stay
			p1.pushCard(shoe.dealCard()); // Deal a card
			std::cout << "P1:\n" << p1.printReveal() << "\n   Sum: " << p1.sum() << std::endl << std::endl;
		}

		// Opponent hits until 17
		while (opp.sum() < 17)
			opp.pushCard(shoe.dealCard());

		std::cout << "Opponent:\n" << opp.printReveal() << "\n   Sum: " << opp.sum() << std::endl << std::endl;

		// Determine winner

		// Draw
		if (p1.sum() == opp.sum())
			std::cout << "Draw!\n\n";
		// Player wins
		else if(

			 (p1.sum() <= 21 && (p1.sum() > opp.sum()) || (opp.sum() > 21))
				||
				(p1.sum() > 21 && opp.sum() > 21 && p1.sum() < opp.sum())
				)
			std::cout << "You win!\n\n";
		// Opponent wins
		else if
			(
			(opp.sum() <= 21 && (opp.sum() > p1.sum()) || (p1.sum() > 21))
				||
				(opp.sum() > 21 && p1.sum() > 21 && opp.sum() < p1.sum())
				)
			std::cout << "Opponent wins!\n\n";
		else
			std::cout << "ERROR, ELSE-IF WIN CONDITIONS!\n\n";

		//std::cout << "Shoe:\n" << shoe.toString() << "\n   Sum: " << shoe.sum() << std::endl << std::endl;


		// sys(pause) is bad practice but we are just playing for now
		system("PAUSE");
		exit(0);

	case 0:
		std::cout << "Exiting...\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		exit(0);

	default:
		std::cout << "ERROR, DEFAULT MENU SWITCH STATEMENT!\n";
	}




	std::cout << "Shoe:\n" << shoe.printReveal() << "\n   Sum: " << shoe.sum() << std::endl << std::endl;

	std::cout << "P1:\n" << p1.printReveal() << "\n   Sum: " << p1.sum() << std::endl << std::endl;

	//std::cout << "P2:\n" << p2.toString() << "\n   Sum: " << p2.sum() << std::endl << std::endl;


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