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
#include <random>
#include <string>
#include <time.h>
#include <vector>

// Function prototypes
int menu();
void playRound();


int main()
{
	// Introduction
	std::string intro = "Welcome to my recreation of 21 from the "
		"Resident Evil 7 DLC.\nEverything is bare bones for now, "
		"but I will do my best to implement the rest of the features!\n";

	// Rules
	std::string rules = "";

	std::cout << intro << std::endl << rules << std::endl;

	switch (menu())
	{
	// Play a round
	case 1:
		//std::cout << "user chose play a round\n";
		std::cout << std::endl;
		playRound();
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

// Plays one round of blackjack
void playRound()
{
	// Seed rand
	srand(time(NULL));

	// 11 cards numbered 1 - 11, no duplicates
	// If a card has been dealt, this vector will change it to 0
	std::vector<int> available_cards
	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	// Declare vectors to hold player's and opponent's hands
	std::vector<int> player_cards;
	std::vector<int> opponent_cards;

	// Deal player and opponent two cards,
	// starting with player.
	// Opponent first card not hidden for now.
	for (int i = 0; i < 4; i++)
	{
		//std::cout << "current i:  " << i << std::endl;
		int r = rand() % 11;
		r = available_cards[r];
		//std::cout << "r: " << r << std::endl;

		// Check if it has been dealt
		if (!r)
		{
			//std::cout << "entered error area\n";
			//std::cout << "old i: " << i << std::endl;
			i--; // Decrement once to offset income increment.
			//std::cout << "new i: " << i << std::endl;
			continue; // Next iteration.
		}
		// Has not been dealt
		else
		{
			//std::cout << "dealt: " << r << std::endl;
			available_cards[r - 1] = 0;
			//std::cout << "check: " << available_cards[r - 1] << std::endl;
		}

		// Deal to player
		if (i % 2 == 0)
			player_cards.push_back(r);
		else
			opponent_cards.push_back(r);
	}

	// Sums of player's and opponent's cards
	int oSum = 0;
	int pSum = 0;

	// Do the addition
	for (int i : player_cards)
		pSum += i;

	for (int i : opponent_cards)
		oSum += i;

	// Print hands
	std::vector<int>::iterator itr = opponent_cards.begin();
	std::cout << "Opponent's cards: ";
	while (itr != opponent_cards.end())
	{
		std::cout << *itr << " ";
		itr++;
	}

	std::cout << std::endl;

	itr = player_cards.begin();
	std::cout << "Player's cards:   ";
	while (itr != player_cards.end())
	{
		std::cout << *itr << " ";
		itr++;
	}

	std::cout << std::endl << std::endl;

	// Available cards error check
	/*
	itr = available_cards.begin();
	while (itr != available_cards.end())
	{
		std::cout << *itr << " ";
		itr++;
	}
	*/
	
	std::cout << std::endl;

	/*
		End condtions:
		
		Both bust						(draw)
		Same count						(draw)
		Player <= 21 && > Opponent		(Player wins)
		Opponent <= 21 && Player		(Opponent wins)
	*/

	std::cout << "Opponent: " << oSum << std::endl
		<< "Player:   " << pSum << std::endl << std::endl;

	// Both bust
	if (pSum > 21 && oSum > 21)
		std::cout << "You both bust! It's a draw!\n";
	else if (pSum == oSum)
		std::cout << "Same count! It's a draw!\n";
	else if (pSum <= 21 && pSum > oSum)
		std::cout << "Player wins!\n";
	else if (oSum <= 21 && oSum > pSum)
		std::cout << "Opponent wins!\n";

	return;
}