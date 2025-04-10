#pragma once

#include <string>
#include<vector> 

std::vector<float> getTemperatureList(const std::string& filename);

float determineMinimumTemperatureInFile(const std::vector<float>& temperatureList);