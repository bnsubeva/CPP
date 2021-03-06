/**
*

* Solution to homework task <5>
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author <Bella Sabeva>
* @idnumber <62188>
* @task <5>
* @compiler <VC>
*
*/
#include "pch.h"
#include<iostream>
#include<cmath>
double formula(double x, double y, int Xo, int  Yo)
{
	double formula = pow(x, 2) - 2 * x*Xo + pow(Xo, 2) + pow(y, 2) - 2 * y*Yo + pow(Yo, 2);
	return formula;
}
using namespace std;
int main()
{
	double x, y;
	cin >> x;
	cin >> y;
	const int R1 = 6;
	const int R2 = 3;
	const int R3 = 1;

	if (formula(x, y, 0, 0) < pow(R1, 2))
	{
		if (formula(x, y, 0, 3) < pow(R2, 2))
		{
			if (formula(x, y, 0, 3) < pow(R3, 2))
			{
				cout << "Black";
			}
			else if (formula(x, y, 0, 3) == pow(R3, 2))
			{
				cout << "Undefined";
			}
			else
			{
				cout << "White";
			}
		}
		else if (formula(x, y, 0, 3) == pow(R2, 2))
		{
			cout << "Undefined";
		}

		else if (formula(x, y, 0, -3) < pow(R2, 2))
		{
			if (formula(x, y, 0, -3) < pow(R3, 2))
			{
				cout << "White";
			}
			else if (formula(x, y, 0, -3) == pow(R3, 2))
			{
				cout << "Undefined";
			}
			else
			{
				cout << "Black";
			}
		}
		else {
			if (x > 0)
			{
				cout << "Black";
			}
			else
			{
				cout << "White";
			}
		}
	}
	else if (formula(x, y, 0, 0) == pow(R1, 2))
	{
		cout << "Undefined";
	}
	else
	{
		cout << "Outside";
	}

	return 0;
}
