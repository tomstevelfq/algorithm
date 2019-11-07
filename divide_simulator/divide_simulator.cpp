//³ý·¨Ä£ÄâÆ÷
//divide simulator
#include<iostream>
#include<vector>

using namespace std;

vector<int> store;

int divide_simulator(int divisor, int dividend,int accuracy)
{
	int integer = dividend / divisor;
	int remain = dividend - divisor * integer;
	int  i;
	for(int iter=0;iter<accuracy;iter++)
	{
		remain *= 10;
		store.push_back(remain/divisor);
		remain =remain%divisor;
	}
	return integer;
}

int  main()
{
	int divisor, dividend,accuracy;
	cin >> divisor >> dividend>>accuracy;
	int integer = divide_simulator(divisor, dividend, accuracy);
	cout << integer;
	if (accuracy > 0)
	{
		cout << '.';
		for (int i = 0; i < accuracy; i++)
		{
			cout << store[i];
		}
		cout << endl;
	}
	return 0;
}