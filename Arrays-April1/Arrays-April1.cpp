// Arrays-April1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "myLibrary.h"

#include<algorithm> //a good one!
#include <iostream>
#include <vector>


void demoACoupleOfArrayThings()
{
	//int numberList[5] = { 1, 2, 3, 4, 5 }; //MUCH later!
//std::array //later!
//we will learn about how to make our own "templates" later (Prog. Fun. 2)
	std::vector<std::string> groceryList =
	{
		"eggs",
		"bacon",
		"tuna" //see TheNewBoston YT channel
	};//vector is a "dynamic" array

	//std::cout << "The SIZE of this list is: " << groceryList.size() << "\n";

	//printList(groceryList);
	std::vector<std::string> partialZodiacListOfNames =
	{
		"Aries",
		"Taurus",
		"Gemini", //like Pinocchio's cricket buddy? 
		"Cancer",
		"Leo",
		"Virgo"
	};

	std::vector<float> apparentMagnitudesOfSomeZodiacStars =
	{
		2.00f,
		0.87f,
		1.14f,
		3.59f, //this is Cancer (not the disease, but the Crab)
		1.36f, //Leo
		0.98f
	};

	printList(partialZodiacListOfNames);
	printList(apparentMagnitudesOfSomeZodiacStars);


}

void demoSomeStringArrayThings()
{
	std::vector<std::string> viralSongs =
	{
		"Never Gonna Give You Up",
		"Megalovania",
		"Baka Mitai",
		"Astronomia",
		"Running in the 90s"
		"My favorite song",
		"Some other song"
	};

	//std::string viralSongs[] = { //this is called a "C-style" array and it has its drawbacks
	//"Never Gonna Give You Up",
	//"Megalovania",
	//"Baka Mitai",
	//"Astronomia",
	//"Running in the 90s"
	//};

	//const int NUMBER_OF_ELEMENTS = 3; 
	//int someArray[NUMBER_OF_ELEMENTS] = { 1, 2, 3 };

	std::cout << "The FIRST viral song is: " << viralSongs.at(0) << "\n";
	std::cout << "The LAST viral song is: " << viralSongs.at(viralSongs.size() - 1) << "\n";

	//what is this "begin" and "end" stuff? 
	std::cout << "\n\n.begin()._Ptr prints this: " << viralSongs.begin()._Ptr << "\n\n\n";
	std::sort(viralSongs.begin(), viralSongs.end());

	printList(viralSongs);

}

int main()
{

	//demoSomeStringArrayThings(); 

	std::vector<float> speedrunRecords =
	{
		4.55, 
		6.36, 
		1.41, 
		6.48, 
		102.57
	};

	//again, this way below of making an array is somewhat discouraged after the year 2011
	//float speedrunRecords[] = {
	//4.55,   // Super Mario Bros.  
	//6.36,   // Minecraft Any% (random seed)  
	//1.41,   // Portal  
	//6.48,   // Celeste Any%  
	//102.57  // Elden Ring Any%  
	//};

	float averageSpeedRunTime = calculateAverageValue(speedrunRecords);

	std::cout << "The AVERAGE speed run time is: " << averageSpeedRunTime << " (minutes?)\n";
}

