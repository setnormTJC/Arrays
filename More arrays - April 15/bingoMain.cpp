// More arrays - April 15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include"libraryOfBingoFunctions.h"

#include <iostream>
#include<vector> 
#include <iomanip>


//std::vector<std::vector<std::string>> carNamesOnTheLot =
//{
//	{"Ford Transit 2016", "Dodge Promaster 2018"}, //row 1 
//	{}, //row 2 is EMPTY 
//	{"Sprinter 2015"}, //row 3 -> just a single car here
//};


void demoTransposingAMatrix()
{
	using Matrix = std::vector<std::vector<int>>; //an ALIAS (shorter, more "readable" type name)

	Matrix someMatrix =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	auto transposedMatrix = getTranspose(someMatrix); 

	printMatrix(transposedMatrix); 
}

int main()
{
	auto mySpecialBingoCard = Bingo::generateRandomBingoCard();
	//std::cout << "The data type of `mySpecialBingoCard` is: " << typeid(mySpecialBingoCard).name() << "\n";
	auto transposedCard = getTranspose(mySpecialBingoCard); 

	//let's suppose that the first B on the player's card gets called
	transposedCard.at(0).at(0) = -99; 

	std::cout << "Initial card\n";
	printMatrix(transposedCard);

	bool thatsABingo = false; //"Inglourious Basterds" reference here

	while (!thatsABingo)
	{
		//call random numbers (between 1 and 99), check if they're on the card, and then check for win: 
		int currentRandomNumber;// = 7; //this would be called "B7" in a real BINGO game 
		std::cout << "Enter the number, bingo master (1 - 99)\n";
		std::cin >> currentRandomNumber;

		Bingo::checkIfNumberIsOnCard(transposedCard, currentRandomNumber);

		printMatrix(transposedCard); 

		std::cout << "Any key to continue\n";
		std::cin.get(); 

		thatsABingo = Bingo::checkIfThatsABingo(transposedCard);
	}

	std::cout << "\n\nWon!\n";
}

