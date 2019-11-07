//分治法归并排序
#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

void merge_sequence(vector<int> &sequence,int start,int end,int middle)
{
	vector<int> front;
	vector<int> back;
	for (int i = start; i <= middle; i++)
		front.push_back(sequence[i]);
	for (int i = middle + 1; i <= end; i++)
		back.push_back(sequence[i]);
	front.push_back(INT32_MAX);
	back.push_back(INT32_MAX);
	int front_pos = 0, back_pos = 0;
	for (int i = start; i <= end; i++)
	{
		if (front[front_pos] <= back[back_pos])
			sequence[i] = front[front_pos++];
		else
			sequence[i] = back[back_pos++];
	}
}

void divide_sort(vector<int>& sort, int start, int end)
{
	if (start == end)
		return;
	else
	{
		int middle = (start + end) / 2;
		divide_sort(sort, start, middle);
		divide_sort(sort,middle + 1, end);
		merge_sequence(sort, start, end, middle);
	}
}

int main()
{
	vector<int> sort;
	sort.insert(sort.begin(), istream_iterator<int>(cin), istream_iterator<int>());
	divide_sort(sort, 0, sort.size() - 1);
	for (auto iter : sort)
		cout << iter << "   ";
	cout << "end" << endl;
	return 0;
}