//³ý·¨Ä£ÄâÆ÷
//divide simulator
#include<iostream>
#include<vector>

using namespace std;

vector<int> store;

void divide_simulator(int divisor, int dividend,int accuracy)
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
}

int  main()
{
	int divisor, dividend,accuracy;
	while (cin >> divisor >> dividend >> accuracy && (divisor || dividend || accuracy) != 0)
	{
		divide_simulator(divisor, dividend, accuracy);
	}
	return 0;
}