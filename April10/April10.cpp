// April10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm>
#include <iostream>
#include <vector>
#include <map>
#include "library.h"

void demoBigArray()
{
	std::cout << "The number of BYTES required to store an integer is: "
		<< sizeof(int) << "\n";


	//int bigBoy[1'000'000'000];// = { 1, 2, 3, 4, 5 }; //stack overflow!

	//std::cout << "The number of bytes required to store the list is: "
	//	<< sizeof(bigBoy) << "\n";

	/*A DYNAMIC array (vector) CAN be used to avoid stack overflow*/
	std::vector<int> someBigBoy(1'000'000'000); //this is quite BIG -> danger Will Robinson!

	std::cin.get();
}

int main()
{
	std::string filename = "temperatureData.txt";


	std::vector<float> temperatureList = getTemperatureList(filename); 

	auto threeDogNightTemperature = determineMinimumTemperatureInFile(temperatureList);

	std::cout << "The lowest temperature in that list is: " << threeDogNightTemperature << "\n";

	//we will come back to this later 
	//std::map<std::string, float> cityNamesToTemperatures = 
	//{
	//	"Austin", 34.0f, 
	//	"Tyler", 31.2f
	//}


	//ANOTHER way to find the minimum: 
	float minimumFoundAnotherWay = *std::min_element(temperatureList.begin(), temperatureList.end());
	//the asterisk is called the "dereferencing operator" (and is used on "pointer" data types -> memory addresses)

	std::cout << "\n\nIs it correct? " << minimumFoundAnotherWay << "\n";

}

