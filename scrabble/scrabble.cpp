// scrabble.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string> 


int calculateWordPointValue(std::string inputWord)
{
	int totalScore = 0; 

	for (int x = 0; x < inputWord.length(); ++x)
	{
		//std::cout << inputWord[x] << "\n";
		switch (inputWord[x])
		{
		case 'a': 
		case 'e':
		case 'i':
			//etc.
			totalScore += 1; 
			break; 

		case 'd': 
		case 'g': 
			totalScore += 2; 
			//std::cout << "Fall through\n";
			break;

		case 'b': 
			totalScore += 3; 
			break; 

			//etc. 
		}
		
	}

	return totalScore; 
}

int main()
{
	std::cout << "Enter a word (MUST use lowercase) - we will determine how many points it is:\n";
	//this is a "prompt" 
	std::string userInputWord; 

	std::getline(std::cin, userInputWord);

	std::cout << "You entered: " << userInputWord << "\n";


	int totalScore = calculateWordPointValue(userInputWord);

	std::cout << "That word is worth this many points: " << totalScore << "\n";
}

