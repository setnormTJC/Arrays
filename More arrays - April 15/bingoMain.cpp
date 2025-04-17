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


	auto transposedCard = getTranspose(mySpecialBingoCard); 

	//let's suppose that the first B on the player's card gets called
	transposedCard.at(0).at(0) = -99; 

	char character = 'Z';

	std::cout << "\033[31m" << character << "\033[0m"; 
	// Red color -> consider using to indicate that a spot on player's card was called

	constexpr int PADDING = 5; 
	std::cout << std::left << std::setw(PADDING) << "B";
	std::cout << std::left << std::setw(PADDING) << "I";
	std::cout << std::left << std::setw(PADDING) << "N";
	std::cout << std::left << std::setw(PADDING) << "G";
	std::cout << std::left << std::setw(PADDING) << "O";
	std::cout << "\n";
	printMatrix(transposedCard);

	//printMatrix(mySpecialBingoCard); 


	//demoTransposingAMatrix(); 
	
}

