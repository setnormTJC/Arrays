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

void Bingo::checkIfNumberIsOnCard(bingoCard& theCard, const int numberToSearchFor)
{
	for (auto& currentRow : theCard)
	{
		for (int& currentNumber : currentRow)
		{
			if (numberToSearchFor == currentNumber)
			{
				currentNumber = -99; //again -99 is a somewhat goofy way of indicating that the number was called
			}
		}
	}
}

bool Bingo::checkIfThatsABingo(const bingoCard& theCard)
{
	bool thatsABingo = false; 

	//one way to win: along main diagonal 
	bool wonOnMainDiagonal = checkForMainDiagonalWin(theCard); 

	//another way: horizontally: 
	bool wonOnHorizontal = checkForHorizontalWin(theCard); 
	
	//another way: diagonally: 

	if (wonOnMainDiagonal || wonOnHorizontal /*etc.*/)
		thatsABingo = true; 

	return thatsABingo; 
}

bool Bingo::checkForMainDiagonalWin(const bingoCard& theCard)
{
	//"hard-coded" way: 
	//if (theCard[0][0] == theCard[1][1]
	//	&&
	//	theCard[1][1] == theCard[2][2]
	//	&&
	//	theCard[2][2] == theCard[3][3]
	//	&&
	//	theCard[3][3] == theCard[4][4]
	//	)
	//{
	//	return true;
	//}

	//else
	//{
	//	return false; 
	//}

	//what if the "bingo" card were a 100 by 100 grid ....? 

	//for (int i = 0; i < theCard.size() - 1; ++i) //note the -1 
	//{
	//	for (int j = 0; j < theCard.at(0).size() - 1; ++j)
	//	{
	//		if (i == j) //only do the check below for elements on same row and column 
	//		{
	//			//if it is ever the case that there is a "mismatch", immediately return false
	//			if (theCard[i][j] != theCard[i + 1][j + 1]) //note the != 
	//			{
	//				std::cout << theCard[i][j] << " does not match " << theCard[i + 1][j + 1] << "\n";
	//				return false; 
	//			}
	//		}
	//	}
	//}

	////if we get all the way through the matrix and never find a "mismatch", return true 
	//return true; 

	/*A more efficent approach - no nested loop*/
	for (int i = 0; i < theCard.size() - 1; ++i)
	{
		if (theCard[i][i] != theCard[i + 1][i + 1]) //note the [i][i]
		{
			//std::cout << theCard[i][i] << " does not match " << theCard[i + 1][i + 1] << "\n";
			return false; 
		}
	}

	return true; 
}

bool Bingo::checkForHorizontalWin(const bingoCard& theCard)
{
	///*first, a (goofy) hardcoded way:*/
	//bool gameWonHorizontally = false; 

	//for (int row = 0; row < theCard.size(); ++row)
	//{ 
	//	if (! //note the NOT!
	//			(theCard[row][0] == theCard[row][1]
	//			&&
	//			theCard[row][1] == theCard[row][2]
	//			&&
	//			theCard[row][2] == theCard[row][3]
	//			&&
	//			theCard[row][3] == theCard[row][4]
	//			)
	//		)
	//	{
	//		std::cout << "Not all numbers match in following row (so no horizontal win):\n";
	//		printRow(theCard[row]);
	//	}

	//	else
	//	{
	//		gameWonHorizontally = true; 
	//		break; 
	//	}
	//}

	//return gameWonHorizontally;


	//less goofy way (expands to arbitrary dimensions): 

	bool wonAlongCurrentRow = true;

	for (int row = 0; row < theCard.size(); ++row)
	{
		wonAlongCurrentRow = true; //resets for each row 

		for (int col = 0; col < theCard.at(row).size() - 1; ++col) //note the -1
		{
			if (theCard[row][col] != theCard[row][col + 1])
			{
				wonAlongCurrentRow = false; 
				break; //waste no more time examining other elements in row 
			}
		}

		if (wonAlongCurrentRow) 
		{
			break; //this breaks from the OUTER loop
		}

		else //optional print for visualization - delete this else once satisfied
		{
			std::cout << "Mismatch in row: ";
			printRow(theCard[row]);
		}
	}

	return wonAlongCurrentRow; 
}



std::vector<std::vector<int>> getTranspose(const std::vector<std::vector<int>>& originalMatrix)
{
	std::vector<std::vector<int>> transposedMatrix;

	//first, make a copy: 
	transposedMatrix = originalMatrix; //the more efficient way to do this is directly below... (more complicated syntax)
	//std::vector<std::vector<int>> transposedMatrix; //constructed with ZERO rows and ZERO columns {{}} -> an EMPTY 2D array
	//transposedMatrix.resize(originalMatrix[0].size(), std::vector<int>(originalMatrix.size()));  

	for (int rowIndex = 0; rowIndex < originalMatrix.size(); ++rowIndex)
		for (int columnIndex = 0; columnIndex < originalMatrix.at(0).size(); ++columnIndex) //ASSUMING square matrix here -> with .at(0)
			transposedMatrix[rowIndex][columnIndex] = originalMatrix[columnIndex][rowIndex]; //switch row and column order

	return transposedMatrix;
}

void printMatrix(const std::vector<std::vector<int>>& theMatrix)
{ 
	constexpr int PADDING = 5;
	std::cout << std::left << std::setw(PADDING) << "B";
	std::cout << std::left << std::setw(PADDING) << "I";
	std::cout << std::left << std::setw(PADDING) << "N";
	std::cout << std::left << std::setw(PADDING) << "G";
	std::cout << std::left << std::setw(PADDING) << "O";
	std::cout << "\n";

	for (const auto& row : theMatrix)
	{
		for (const int currentNumber : row)
		{
			if (currentNumber == -99) //let's say -99 means the number at that spot was called
			{
				std::cout << "\033[31m" << std::left << std::setw(PADDING) << currentNumber; //this is an "ANSI" thing that makes text red
				std::cout <<  "\033[0m"; //resets to default color 
			}
			else
				std::cout << std::left << std::setw(PADDING) << currentNumber; //print non-called numbers in default terminal color 
		}
		std::cout << "\n"; //newline to separate rows
	}
}

void printRow(const std::vector<int>& row)
{
	for (const int number : row)
		std::cout << number << ", ";
	std::cout << "\n";
}
