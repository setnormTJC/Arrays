#include<iostream> 
#include <vector>



int main()
{
    //int salaries[] = //this way is "old-school" 
    //{
    //    100,
    //    1000,
    //    10000
    //};

    std::vector<int> salaries =
    {
        100, 1000, 10'000
    };

    
    //int employeeCount = sizeof(salaries) / sizeof(salaries[0]);
    //again, the code on the line above is "old-school" (not as convenient as vector)

    int employeeCount = salaries.size(); //this will evaluate to 3 (three)
    for (int i = 0; i < employeeCount; i++)
    {
        //give 10 percent raise to all!
        salaries[i] = salaries[i] * 1.10;
    }



    //print updated salaries 
    for (int i = 0; i < employeeCount; i++)
    {
        std::cout << salaries[i] << "\n";
    }

    return 0;
}

