#include<stdio.h>
#include<iostream>

using namespace std;

double chicken_calculate(int num,double legs)
{
	return 2.0 * num - legs / 2;
}

int main()
{
	int num;
	double legs;
	cin >> num >> legs;
	double chicken = chicken_calculate(num, legs);
	cout << chicken << endl;
	if (chicken - floor(chicken) == 0 && (chicken>=0 && chicken<=num))
	{
		cout << "chicken:  " << chicken << "    rabbit:  " << legs/2-num << endl;
	}
	else
	{
		cout << "No answer" << endl;
	}
	return 0;
}