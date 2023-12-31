#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr(10);
int total = 0;
void solve()
{
	for (int i = 1; i <= 9; ++i)
	{
		cin >> arr[i];
		total += arr[i];
	}

	sort(arr.begin(), arr.end());

	int temp;
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = i + 1; j <= 9; ++j)
		{
			temp = total;
			if (temp - arr[i] - arr[j] == 100)
			{
				for (int k = 1; k <= 9; ++k)
				{
					if (k == i || k == j)
						continue;
					cout << arr[k] << '\n';
				}
				return;
			}
		}
	}
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