#include<stdio.h>
#include<iostream>

using namespace std;

void exchange_parameter(int& a, int& b)
{
	int temp=a;
	a = b;
	b = temp;
}

void exchange_parameter2(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void exchange_parameter3(int& a, int& b)
{
	cout << b << "    " << a << endl;
}

int main()
{
	int a, b;
	cin >> a >> b;
	exchange_parameter3(a, b);
	return 0;
}