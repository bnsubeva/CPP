/**
*

* Solution to homework task <1>
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author <Bella Sabeva>
* @idnumber <62188>
* @task <1>
* @compiler <VC>
*
*/
#include "pch.h"
#include <iostream>
using namespace std;
int SafelyInputInteger(int lowerBound, int upperBound)
{
	int intNumber;
	do
	{
		cout << "Input a number..";
		cin >> intNumber;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	} while ((intNumber < lowerBound) || (intNumber > upperBound));
	return intNumber;
}
#include "pch.h"
#include <iostream>

int main()
{
	int number;
	number = SafelyInputInteger(0, 65535);
	int max = number;
	int min = number;
	while (number >= 0)
	{
		if (number > max)
		{
			max = number;
		}
		if (number < min)
		{
			min = number;
		}

		cin >> number;
	}
	int subtract;
	subtract = max - min;
	cout << subtract;
	return 0;
}

 
