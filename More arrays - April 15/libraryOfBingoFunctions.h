#pragma once

#include<iostream> 
#include<vector> //it MIGHT be better to use <array> 


namespace Bingo
{


	using bingoCard = std::vector<std::vector<int>>; //this is a type alias 
	/*
	* NOTE/CAUTION: As is, this function may result in DUPLICATES (TRIPLICATE) -> fix this later, if desired
	*/
	bingoCard generateRandomBingoCard(); //function declaration (not a definition) 




}

std::vector<std::vector<int>> getTranspose(const std::vector<std::vector<int>>& originalMatrix);
void printMatrix(const std::vector<std::vector<int>>& theMatrix);
