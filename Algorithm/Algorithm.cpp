#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

void InsertionSort(vector<int>& v)
{
	const int n = v.size();

	// [1][3] [2][4][5]

	for (int i = 1; i < n; i++)
	{
		int data = v[i];

		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (v[j] > data)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = data;
	}

}

int main()
{
	
	vector<int> v = {3, 9, 5, 4, 2};
	InsertionSort(v);

}