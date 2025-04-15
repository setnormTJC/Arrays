#include "libraryOfBingoFunctions.h"

#include<random> 

//this cpp file contains implementation details on the functions
//declared in the corresponding header file (same name as this file) 

Bingo::bingoCard Bingo::generateRandomBingoCard()
{
	Bingo::bingoCard theRandomBingoCard;
	/*the algorithm goodness (details)*/
	
	//first, the B column has 5 random values betwixt 1 and 15:
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<> distributionForB(1, 15);


	std::vector<int> bColumn; 
	for (int i = 0; i < 5; ++i)
	{
		bColumn.push_back(distributionForB(rng));
	}

	theRandomBingoCard.push_back(bColumn);

	//second, let's do the 'I' column (values betwixt 16 and 30)
	std::uniform_int_distribution<> distributionForI(16, 30);
	std::vector<int> iColumn; 
	for (int i = 0; i < 5; ++i)	iColumn.push_back(distributionForI(rng)); 

	theRandomBingoCard.push_back(iColumn); 


	return theRandomBingoCard;
}

void Bingo::printBingoCard(const Bingo::bingoCard& theBingoCard)
{
	//use a NESTED for loop to print the rows and columns: 

	for (const auto& row : theBingoCard) //range-based for loop 
	{
		for (const int currentNumber : row) //inner loop
		{
			std::cout << currentNumber << " "; //better to use std::setw() here ... 
		}
		std::cout << "\n";
	}
}
