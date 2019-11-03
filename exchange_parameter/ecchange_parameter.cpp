#include<stdio.h>
#include<iostream>

using namespace std;

void exchange_parameter(int& a, int& b)
{
	int temp=a;
	a = b;
	b = temp;
}

int main()
{
	int a, b;
	cin >> a >> b;
	exchange_parameter(a, b);
	cout << a << endl << b << endl;
	return 0;
}