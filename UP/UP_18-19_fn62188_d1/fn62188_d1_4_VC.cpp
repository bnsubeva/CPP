/**
*

* Solution to homework task <4>
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author <Bella Sabeva>
* @idnumber <62188>
* @task <4>
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
int main()
{
	int space, rows;
	char symbol;
	rows = SafelyInputInteger(1, 13);
	cin >> symbol;
	int max;
	max = rows * 2 - 1;
	//diagonalite na kvadrata <=25//
	for (int i = 1; i < ((25 - max) / 2); i++)
	{
		cout << " " << endl;
	}

	for (int i = 1, k = 0; i <= rows - 1; i++, k = 0)
	{
		for (space = 1; space <= (rows - i + (40 - max)/2); space++)
			                                
		{
			cout << "  ";
		}

		while (k != 2 * i - 1)
		{
			cout << symbol << " ";
			k++;
		}
		cout << endl;
	}
	for (int i = rows; i >= 1; i--)
	{
		for (space = 0; space < (rows - i + (40 - max)/2); space++)
			cout << "  ";

		for (int j = i; j <= 2 * i - 1; j++)
			cout << symbol << " ";

		for (int j = 0; j < i - 1; j++)
			cout << symbol << " ";

		cout << endl;
	}

	return 0;
}