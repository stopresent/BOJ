#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int numbers[10] = { 0, };

void solve()
{
	cin >> n;

	while (n > 0)
	{
		numbers[n % 10]++;
		n = n / 10;
	}

	int maxNum = 0;
	for (int i = 0; i <= 9; ++i)
	{
		if (i == 6 || i == 9)
			continue;
		maxNum = max(maxNum, numbers[i]);
	}

	if (maxNum > numbers[6] && maxNum > numbers[9])
	{
		cout << maxNum;
		return;
	}

	if (numbers[6] > numbers[9])
	{
		int dis = numbers[6] - numbers[9];
		if (dis % 2 == 0)
		{
			int temp = (numbers[6] - numbers[9]) / 2 + numbers[9];
			maxNum = max(maxNum, temp);
		}
		else
		{
			int temp = (numbers[6] - numbers[9] + 1) / 2 + numbers[9];
			maxNum = max(maxNum, temp);
		}
	}
	else if (numbers[9] > numbers[6])
	{
		int dis = numbers[9] - numbers[6];
		if (dis % 2 == 0)
		{
			int temp = (numbers[9] - numbers[6]) / 2 + numbers[6];
			maxNum = max(maxNum, temp);
		}
		else
		{
			int temp = (numbers[9] - numbers[6] + 1) / 2 + numbers[6];
			maxNum = max(maxNum, temp);
		}
	}
	else if (numbers[9] == numbers[6])
	{
		int temp = numbers[6];
		maxNum = max(maxNum, temp);
	}

	cout << maxNum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}