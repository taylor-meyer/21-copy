/*

Code started:
07/23/2019

Last edit:
07/32/2019

I was playing the 21 dlc for Resident Evil 7
and thought, "I can probably re-create this!"

I'll start with text base, and then I can use this
as a way to learn Unity and get some 2D graphics going!

:)

*/

#include "ClearScreen.h" // ClearScreen()
#include "Hand.h" // Opponent/Player/Shoe
#include "Player.h"
#include <algorithm>
#include <chrono> //std::chrono::seconds
#include <fstream> // Read/write stats
#include <iostream> // std::cout,std::cin
#include <time.h> // Seed rand
#include <thread> //std::this_thread::sleep_for

// Function prototypes
int menu();
void exitSeconds(int);

// Main
int main()
{
	// Seed random
	srand((unsigned int)time(NULL));

	// Introduction
	std::string intro = "Welcome to my recreation of 21 from the "
		"Resident Evil 7 DLC.\nEverything is bare bones for now, "
		"but I will do my best to implement the rest of the features!";
	// Rules
	std::string rules = "Computer opponent will stay on 17 and will not reveal their hand until you stay or bust.\n"
		"If both you and opponent bust, smaller count wins.";
	// Printout
	std::cout << intro << std::endl << rules << std::endl << std::endl;






	// Get login
	std::string username;
	std::string password;

	std::cout << "Username: ";
	std::getline(std::cin, username);
	std::cout << "Password: ";
	std::getline(std::cin, password);

	// Process login
	std::string line;
	int linesread = 0; // To read every third line of file
	std::ifstream logins("logins.dat", std::ios::in); // File
	if (logins.is_open())
	{
		while (!logins.eof())
		{
			std::getline(logins, line);
			if (linesread % 3 == 0)
			{
				if (line.compare(username) == 0) // Matching username
				{
					std::getline(logins, line); // Get password for that username
					break;
				}
			}
			linesread++;
		}
	}
	else
	{
		std::cout << "Logins file not open.\n\n";
		exitSeconds(2);
	}

	// Check password
	if (line.compare(password) != 0)
	{
		std::cout << "Incorrect password.\n";
		exitSeconds(2);
	}
	else
		std::cout << "\nWelcome, " << username << std::endl << std::endl;




	// Load stats file into a vector
	std::vector<Player> players;

	std::string username2;
	int wins;
	int loss;

	std::ifstream stats("stats.dat", std::ios::in);
	if (!stats.is_open())
	{
		std::cout << "Stats file not open.\n\n";
		exitSeconds(2);
	}
	else
	{
		while (!stats.eof())
		{
			stats >> username2 >> wins >> loss;
			players.push_back(Player(username2, wins, loss));
		}
	}
	stats.close();
	
	/*
	// Test print stats
	std::vector<Player>::iterator itr = players.begin();
	while (itr != players.end())
	{
		std::cout << "\nUsername: " << (*itr).getUsername()
			<< "\nWins: " << (*itr).getWins()
			<< "\nLosses: " << (*itr).getLosses()
			<< std::endl;
		itr++;
	}
	*/
	

	// Search for user to assign player Object
	Player P;
	int index;
	auto it = std::find_if(players.begin(), players.end(), [&username](Player &obj)
	{
		return obj.getUsername() == username;
	});
	if (it != players.end())
	{
		// Index for later
		index = std::distance(players.begin(), it);
		// Set values
		P.setUsername(username);
		P.setWins((*it).getWins());
		P.setLosses((*it).getLosses());
		P.setFingers(5);
	}



	// Declare shoe and players
	Hand shoe; shoe.fillShoe(); // Shoe with all cards loaded
	Hand p1; // Player
	Hand opp; // Opponent
	

	// Menu
	switch (menu())
	{
	case 1:
	{
		int rounds_won = 0;
		while (true)
		{
			ClearScreen();

			// Deal player, opp, player, opp
			p1.pushCard(shoe.dealCard());
			opp.pushCard(shoe.dealCard());
			p1.pushCard(shoe.dealCard());
			opp.pushCard(shoe.dealCard());

			// Show opponent (first card hidden)
			std::cout << "Opponent:\n" << opp.printHidden() << std::endl << opp.printHiddenSum() << std::endl << std::endl;

			// Show what player has to start
			std::cout << "Player:\n" << p1.printReveal() << "\n(" << p1.sum() << ")"
				"\n\nFingers left: " << P.getFingers() << std::endl
				<< "Rounds won: " << rounds_won << std::endl;

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
				std::cout << "Opponent:\n" << opp.printHidden() << std::endl << opp.printHiddenSum() << std::endl << std::endl;

				// Show what player has
				std::cout << "Player:\n" << p1.printReveal() << "\n(" << p1.sum() << ")\n" << std::endl
					<< "\n\nFingers left: " << P.getFingers() << std::endl
					<< "Rounds won: " << rounds_won << std::endl;
			}

			// Opponent hits until 17
			while (opp.sum() < 17)
				opp.pushCard(shoe.dealCard());

			ClearScreen();

			// Show opponent (first card hidden)
			std::cout << "Opponent:\n" << opp.printReveal() << std::endl << "(" << opp.sum() << ")\n" << std::endl;

			// Show what player has to start
			std::cout << "Player:\n" << p1.printReveal() << "\n(" << p1.sum() << ")\n" << std::endl;

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
				rounds_won++;
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
				P.loseFinger();
			}
			else
				std::cout << "ERROR, ELSE-IF WIN CONDITIONS!\n\n";

			system("PAUSE");

			if (rounds_won == 5 || P.getFingers() == 0)
			{
				if (rounds_won == 5)
					P.incrementWins();
				else
					P.incrementLoss();
				break;
			}

			/*
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
			*/
			shoe.fillShoe();
			p1.clear();
			opp.clear();
		}

		players[index] = P;

		
		// Write new stats
		// Open outfile and clear it because we are saving the entire vector back
		std::ofstream statsout("stats.dat", std::ofstream::out | std::ofstream::trunc);

		for (auto outitr = players.begin(); outitr != players.end(); outitr++)
		{
			statsout << (*outitr).getUsername() << "\n"
				<< (*outitr).getWins() << "\n"
				<< (*outitr).getLosses();
			if (outitr != players.end() - 1) // Do this to avoid trailing endl
				statsout << "\n";
		}
		statsout.close();
	}
	case 0:
		exitSeconds(2);
	default:
		std::cout << "ERROR, DEFAULT MENU SWITCH STATEMENT!\n";
		exitSeconds(2);
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

void exitSeconds(int n)
{
	std::cout << "Exiting...\n";
	std::this_thread::sleep_for(std::chrono::seconds(n));
	exit(0);
}