/**
*

* Solution to homework task <2>
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author <Bella Sabeva>
* @idnumber <62188>
* @task <2>
* @compiler <VC>
*
*/
#include "pch.h"
#include <iostream>
#include<cmath>
using namespace std;
  long long int  SafelyInputInteger( long long  int  lowerBound,  long long  int  upperBound)
{
	  long long int  intNumber;
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
int main()
{ long long int  number;
    int digit;
	number = SafelyInputInteger(-4294967296, 4294967295);
	digit = SafelyInputInteger(0, 9);
	int br = 0;
	number = abs(number);
	while (number != 0)
	{
		long long int currentDigit = number % 10;
		if (currentDigit == digit)
		{
			br++;
		}
		number = number / 10;
	}
	cout << br;
	return 0;
}

 

 