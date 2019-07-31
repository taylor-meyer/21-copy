/*

Code started:
07/23/2019

Last edit:
07/31/2019

I was playing the 21 dlc for Resident Evil 7
and thought, "I can probably re-create this!"

I'll start with text base, and then I can use this
as a way to learn Unity and get some 2D graphics going!

:)

*/

#include "ClearScreen.h" // ClearScreen()
#include "Hand.h" // Opponent/Player/Shoe
#include <chrono> //std::chrono::seconds
#include <fstream> // Read/write stats
#include <iostream> // std::cout,std::cin
#include <time.h> // Seed rand
#include <thread> //std::this_thread::sleep_for

// Function prototypes
int menu();

// Main
int main()
{
	// Seed random
	srand((unsigned int)time(NULL));

	// Stats
	int wins = 0;
	int loss = 0;

	// File for stats
	std::string line;
	std::ifstream infile;
	infile.open("stats.dat", std::ios::in);
	infile >> wins >> loss; // Load stats
	infile.close();

	// Introduction
	std::string intro = "Welcome to my recreation of 21 from the "
		"Resident Evil 7 DLC.\nEverything is bare bones for now, "
		"but I will do my best to implement the rest of the features!";
	// Rules
	std::string rules = "Computer opponent will stay on 17 and will not reveal their hand until you stay or bust.\n"
		"If both you and opponent bust, smaller count wins.";
	// Printout
	std::cout << intro << std::endl << rules << std::endl << std::endl;

	// Print stats
	std::cout << "Wins: " << wins << "\nLosses: " << loss << std::endl << std::endl;

	// Declare shoe and players
	Hand shoe; shoe.fillShoe(); // Shoe with all cards loaded
	Hand p1; // Player
	Hand opp; // Opponent
	

	// Menu
	switch (menu())
	{
	case 1:
	{
		while (true)
		{
			ClearScreen();

			// Deal player, opp, player, opp
			p1.pushCard(shoe.dealCard());
			opp.pushCard(shoe.dealCard());
			p1.pushCard(shoe.dealCard());
			opp.pushCard(shoe.dealCard());

			// Show opponent (first card hidden)
			std::cout << "Opp:\n" << opp.printHidden() << std::endl << opp.printHiddenSum() << std::endl << std::endl;

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

				ClearScreen();

				if (hitorstay != 1)
					break; // Break if stay
				p1.pushCard(shoe.dealCard()); // Deal a card

				// Show opponent (first card hidden)
				std::cout << "Opp:\n" << opp.printHidden() << std::endl << opp.printHiddenSum() << std::endl << std::endl;

				// Show what player has
				std::cout << "P1:\n" << p1.printReveal() << "\n   Sum: " << p1.sum() << std::endl << std::endl;
			}

			// Opponent hits until 17
			while (opp.sum() < 17)
				opp.pushCard(shoe.dealCard());

			ClearScreen();

			// Show opponent (first card hidden)
			std::cout << "Opp:\n" << opp.printReveal() << std::endl << opp.sum() << std::endl << std::endl;

			// Show what player has to start
			std::cout << "P1:\n" << p1.printReveal() << "\n   Sum: " << p1.sum() << std::endl << std::endl;

			// Determine winner

			// Draw
			if (p1.sum() == opp.sum())
				std::cout << "Draw!\n\n";
			// Player wins
			else if (

				(p1.sum() <= 21 && (p1.sum() > opp.sum()) || (opp.sum() > 21))
				||
				(p1.sum() > 21 && opp.sum() > 21 && p1.sum() < opp.sum())
				)
			{
				std::cout << "You win!\n\n";
				wins++;
			}
			// Opponent wins
			else if
				(
				(opp.sum() <= 21 && (opp.sum() > p1.sum()) || (p1.sum() > 21))
					||
					(opp.sum() > 21 && p1.sum() > 21 && opp.sum() < p1.sum())
					)
			{
				std::cout << "Opponent wins!\n\n";
				loss++;
			}
			else
				std::cout << "ERROR, ELSE-IF WIN CONDITIONS!\n\n";

			bool again = false;
			std::cout << "\nPlay again (0 for no)? ";
			std::cin >> again;

			if (!again)
				break;
			else // Reset hands & shoe
			{
				shoe.fillShoe();
				p1.clear();
				opp.clear();
			}
		}

		// Write new stats
		std::ofstream outfile;
		outfile.open("stats.dat", std::ofstream::out | std::ofstream::trunc);
		outfile << wins << std::endl << loss;
		outfile.close();
	}


	case 0:
		std::cout << "Exiting...\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		exit(0);

	default:
		std::cout << "ERROR, DEFAULT MENU SWITCH STATEMENT!\n";
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