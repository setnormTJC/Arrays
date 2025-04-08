// April8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"library.h"

#include<algorithm>
#include <iostream>
#include<random>
#include<string> 
#include <vector>

void demoArrayOfMusicNotes()
{
	std::vector<std::string> listOfSomeMusicNotes =
	{
		"C",
		"C#",
		"D",
		"D#",
		"E",
		"F",
		"F#",
		"G"
	};

	//whoops - let's add another note TO THE END of that array:
	//by using `push_back`
	std::cout << "This is a MEMORY address (pointer):" << listOfSomeMusicNotes.begin()._Ptr << "\n";
	listOfSomeMusicNotes.push_back("G#");
	listOfSomeMusicNotes.push_back("A");

	printList(listOfSomeMusicNotes); //let's modify the for loop to be "range-based"

	std::cout << "The C Major chord is: \n";
	std::cout << listOfSomeMusicNotes[0] << listOfSomeMusicNotes[4] << listOfSomeMusicNotes[7]
		<< "\n";

	//let's also "play" random notes (by using std::shuffle from <algorithm>)
	std::cout << "\n\nSome random notes:\n";

	std::cout << "How many random notes do ya want?\n";
	int numberOfNotesDesired; 
	std::cin >> numberOfNotesDesired; 

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, listOfSomeMusicNotes.size() - 1);
	

	for (int currentNoteNumber = 0; currentNoteNumber < numberOfNotesDesired; ++currentNoteNumber)
	{
		std::string randomNote = listOfSomeMusicNotes[distribution(rng)]; //to be determined...
		std::cout << "Playing this random note: \n" << randomNote << "\n";
		//std::cout << "Random INDEX is = " << distribution(rng) << "\n";
	}

	std::cout << "\n\n\nCan we SHUFFLE the list of notes? (YES!)\n";
	std::shuffle(listOfSomeMusicNotes.begin(), 
		listOfSomeMusicNotes.end(), rng); 
	printList(listOfSomeMusicNotes); 


}

int main()
{
	demoArrayOfMusicNotes(); 


}

