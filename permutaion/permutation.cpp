//ееап
//permutaiton

#include<iostream>
#include<vector>
#include<iterator>
#include<iomanip>

using namespace std;
vector<int> permutations;
vector<int> flag(9);

void permutation(vector<int> num)
{
	for (int i = 0; i < 9; i++)
	{
		int a = num[i];
		for (int j = 0; j < 9; j++)
		{
			if (j == i)
				continue;
			int b = num[j];
			for (int k = 0; k < 9; k++)
			{
				int c = num[k];
				if (k == j || k == i)
					continue;
				permutations.push_back(a * 100 + b * 10 + c);
			}
		}
	}
}

int find(int m, int n)
{
	vector<int> a;
	for (int j = 0; j < 3; j++)
	{
		a.push_back(m % 10);
		m /= 10;
	}
	for (int i = 0; i < 3; i++)
	{
		int remain = n % 10;
		n /= 10;
		for (int i = 0; i < 3; i++)
			if (remain == a[i])
				return true;
	}
	return false;
}

int find2(int m)
{
	int a = m % 10;
	m /= 10;
	int b = m % 10;
	m /= 10;
	int c = m % 10;
	if (a == b || b == c || a == c)
		return true;
	return false;
}

int is_legal(int num)
{
	int m = num * 2;
	int n = num * 3;
	if ((find(num, m) ||find(num, n) ||find(m, n)) == 0&&(find2(m)||find2(n)||find2(num))==0)
		return true;
	return false;
}

int  main()
{
	vector<int> num{ 1,2,3,4,5,6,7,8,9 };
	permutation(num);
	for (auto it : permutations)
		if (is_legal(it))
			cout <<setw(10)<< it << setw(10) <<it*2 << setw(10) <<it*3 << endl;
	cout << "end";
	cout << "end";
	int multi=1;
	for (int i = 1; i <= 9; i++)
		multi *= i;
	cout << multi << endl;
	return 0;
}