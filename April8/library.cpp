#include"library.h"

void printList(const std::vector<std::string>& list)
{
	//for (int index = 0; index < list.size(); ++index)
	//	std::cout << list[index] << "\n";


	//for (std::string currentNote : list) //this is a "range-based" for loop
	//	std::cout << currentNote << "\n";

	for (const auto& currentNote : list) //this is an "optimized" version of the code above
		std::cout << currentNote << "\n";
}