#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

void solve()
{
	string str;
	cin >> str;
	vector<vector<int>> aCount(222222, vector<int>(26));
	for (int i = 0; i < str.size(); ++i)
	{
		if (i != 0)
		{
			for (int j = 0; j < 26; ++j)
				aCount[i][j] = aCount[i - 1][j];
		}
		int cur = str[i] - 'a';
		aCount[i][cur]++;
	}

	int n;
	cin >> n;

	char c;
	int first, second;
	for (int i = 0; i < n; ++i)
	{
		cin >> c >> first >> second;
		int cur = c - 'a';

		int sum1 = first > 0 ? aCount[first - 1][cur] : 0;
		int sum2 = aCount[second][cur];

		cout << sum2 - sum1 << '\n';
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