#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<algorithm>

using namespace std;

int num[3];

int main()
{
	for (int i = 0; i < 3; i++)
		cin >> num[i];
	sort(begin(num),end(num));
	for (auto it : num)
		cout << it << "   ";
	return 0;
}