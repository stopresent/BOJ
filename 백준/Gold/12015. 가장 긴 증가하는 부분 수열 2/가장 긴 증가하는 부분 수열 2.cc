#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000001];
vector<int> seq;
int N;

void bs(int num)
{
	int low = 0, high = seq.size() - 1, mid;
	int ret = 100000007; // 왜 이런 숫자로 잡는거지?
	while (low <= high)
	{
		mid = (low + high) / 2;
		int here = seq[mid];
		if (here >= num)
		{
			if (ret > mid)
				ret = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	seq[ret] = num;
}

void findLis()
{
	seq.push_back(arr[0]);
	for (int i = 1; i < N; ++i)
	{
		if (seq.back() < arr[i])
			seq.push_back(arr[i]);
		else
			bs(arr[i]);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	findLis();

	cout << seq.size();

	return 0;
}