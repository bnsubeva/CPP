/**
*

* Solution to homework task <3>
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author <Bella Sabeva>
* @idnumber <62188>
* @task <3>
* @compiler <VC>
*
*/
#include"pch.h"
#include<iostream>
using namespace std;
int Sum(int a, int b)
{
	int sum;

	if ((a + b) <= 15)
	{
		sum = a + b;
	}
	else {
		sum = ((a + b) % 15) - 1;
	}
	return sum;
}
int Difference(int a, int b)
{
	int difference;

	if ((a - b) >= 0)
	{
		difference = a - b;
	}
	else
	{
		difference = 15 + (a - b) + 1;
	}
	 return  difference;

}
int Multiplication(int a, int b)
{
	int multiplication;
	if (a*b <= 15)
	{
		multiplication = a * b;
	}
	else
	{
		int index;
		index = (a*b) / 15;
		if ((a*b) % 15 == 0)
		{
			multiplication = 15 - index + 1;
		}
		else
		{
			multiplication = a * b - index * 15 - index;
		}
	}
	 return multiplication;
}
int Partition(int a, int b)
{
	int partition;
	if (b == 0)
	{
		cout << "Wrong input";
	}
	else
	{
		partition = a / b;
		 return partition;
	}
}
int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	char operation;
	cin >> operation;
	if (a > 15 || b > 15)
	{
		cout << "Wrong input";
	}
	else
	{
		if (operation == '0')
		{
			cout<<Sum(a, b);
		}
		else if (operation == '1')
		{
			cout<<Difference(a, b);
		}
		else if (operation == '2')
		{
			cout<<Multiplication(a, b);
		}
		else if (operation == '3')
		{
			cout<<Partition(a, b);
		}
		else
		{
			cout << "Wrong input";
		}
	}
	return 0;
}
