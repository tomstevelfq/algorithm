#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int num;
	int reverse_num=0;
	scanf("%d", &num);
	while (num > 0)
	{
		reverse_num *= 10;
		reverse_num += num%10;
		num /= 10;
	}
	printf("%d\n", reverse_num);
	return 0;
}