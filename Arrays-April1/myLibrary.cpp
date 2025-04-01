
#include"myLibrary.h"
#include <iostream>

//function DEFINITIONS go here (in this "implementation" file) 

void printList(const std::vector<std::string>& list)
{
	for (int indexOfTheItemInTheList = 0; indexOfTheItemInTheList < list.size(); ++indexOfTheItemInTheList)
	{
		std::cout << list.at(indexOfTheItemInTheList) << "\n";
	}
}

void printList(const std::vector<float>& list)
{
	for (int indexOfTheItemInTheList = 0; indexOfTheItemInTheList < list.size(); ++indexOfTheItemInTheList)
	{
		std::cout << list.at(indexOfTheItemInTheList) << "\n";
	}
}

float calculateAverageValue(const std::vector<float>& list)
{
	float sumSoFar = 0.0f; 

	for (int i = 0; i < list.size(); ++i)
	{
		sumSoFar = sumSoFar + list[i]; //I just used [] instead of .at -> they are ROUGHLY the same thing
		std::cout << "Sum after loop iteration number " << i << " is: " << sumSoFar << "\n";
	}

	float average = sumSoFar / (list.size()); 

	return average; 
}
