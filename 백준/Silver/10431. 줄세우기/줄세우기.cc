#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;

void solve()
{
	int t;
	cin >> t;
	vector<int> testcases(t + 1);
	vector<int> ans(t);
	for (int i = 0; i < t; ++i)
	{
		cin >> testcases[i];

		vector<int> heightes(20);
		for (int j = 0; j < 20; ++j)
		{
			cin >> heightes[j];
			int height = heightes[j];
			for (int k = j - 1; k >= 0; --k)
			{
				if (heightes[k] > height)
				{
					swap(heightes[k], heightes[k + 1]);
					ans[i]++;
				}
			}
		}
	}

	for (int i = 0; i < t; ++i)
	{
		cout << testcases[i] << " ";

		cout << ans[i] << '\n';
	}
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}