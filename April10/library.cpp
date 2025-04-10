#include "library.h"

#include<fstream> 
#include<iostream> 
#include <vector>

std::vector<float> getTemperatureList(const std::string& filename)
{
	std::ifstream fin(filename);

	if (!fin)
	{
		std::cout << "FNFE\n";
		return {}; //this is called the "empty list" 
	}

	std::vector<float> temperatureList;

	while (!fin.eof())
	{
		float currentTemperatureInTheFile;
		fin >> currentTemperatureInTheFile;

		temperatureList.push_back(currentTemperatureInTheFile);
	}

	return temperatureList;
}



float determineMinimumTemperatureInFile(const std::vector<float>& temperatureList)
{
	//int minimum = INT_MAX //this is ONE way to do it!
	int minimum = temperatureList[0]; 

	for (int index = 1; index < temperatureList.size(); ++index)
	{
		if (temperatureList[index] < minimum)
		{
			minimum = temperatureList[index];
			std::cout << "Minimum was just UPDATED to: " << minimum << "\n";
		}
	}

	return minimum; 
}
