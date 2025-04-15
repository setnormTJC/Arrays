// More arrays - April 15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include"libraryOfBingoFunctions.h"

#include <iostream>
#include<vector> 


//std::vector<std::vector<std::string>> carNamesOnTheLot =
//{
//	{"Ford Transit 2016", "Dodge Promaster 2018"}, //row 1 
//	{}, //row 2 is EMPTY 
//	{"Sprinter 2015"}, //row 3 -> just a single car here
//};

int main()
{
	auto mySpecialBingoCard = Bingo::generateRandomBingoCard();


	Bingo::printBingoCard(mySpecialBingoCard); 
}

