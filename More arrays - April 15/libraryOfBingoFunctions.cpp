#include "libraryOfBingoFunctions.h"

#include<iomanip>
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
	for (int i = 0; i < 5; ++i)	bColumn.push_back(distributionForB(rng));

	//second, let's do the 'I' column (values betwixt 16 and 30)
	std::uniform_int_distribution<> distributionForI(16, 30);
	std::vector<int> iColumn; 
	for (int i = 0; i < 5; ++i)	iColumn.push_back(distributionForI(rng)); 

	std::uniform_int_distribution<> distributionForN(31, 45);
	std::vector<int> nColumn;
	for (int i = 0; i < 5; ++i)	nColumn.push_back(distributionForN(rng));

	nColumn.at(2) = -99;  //let -99 indicate the "FREE" spot

	std::uniform_int_distribution<> distributionForG(46, 60); 
	std::vector<int> gColumn; 
	for (int i = 0; i < 5; ++i) gColumn.push_back(distributionForG(rng)); 

	std::uniform_int_distribution<> distributionForO(61, 75);
	std::vector<int> oColumn;
	for (int i = 0; i < 5; ++i) oColumn.push_back(distributionForO(rng));


	theRandomBingoCard.push_back(bColumn);
	theRandomBingoCard.push_back(iColumn);
	theRandomBingoCard.push_back(nColumn);
	theRandomBingoCard.push_back(gColumn);
	theRandomBingoCard.push_back(oColumn);


	return theRandomBingoCard;
}



std::vector<std::vector<int>> getTranspose(const std::vector<std::vector<int>>& originalMatrix)
{
	std::vector<std::vector<int>> transposedMatrix;

	//first, make a copy: 
	transposedMatrix = originalMatrix;

	for (int rowIndex = 0; rowIndex < originalMatrix.size(); ++rowIndex)
		for (int columnIndex = 0; columnIndex < originalMatrix.at(0).size(); ++columnIndex) //ASSUMING square matrix here -> with .at(0)
			transposedMatrix[rowIndex][columnIndex] = originalMatrix[columnIndex][rowIndex]; //switch row and column order

	return transposedMatrix;
}

void printMatrix(const std::vector<std::vector<int>>& theMatrix)
{
	constexpr int PADDING = 5; 

	for (const auto& row : theMatrix)
	{
		for (const int currentNumber : row)
		{
			std::cout << std::left << std::setw(PADDING) << currentNumber;
		}
		std::cout << "\n"; //newline to separate rows
	}
}
