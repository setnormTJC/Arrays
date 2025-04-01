#pragma once

#include<string> 
#include<vector> 

//function DECLARATIONS go here (in this "specification" file) 

void printList(const std::vector<std::string>& list); 

/*This is an OVERLOADED version of the print function that prints an array of FLOATS*/
void printList(const std::vector<float>& list);

/*this is one of our first algorithms! --> HOORAY!*/
float calculateAverageValue(const std::vector<float>& list); //function declaration 