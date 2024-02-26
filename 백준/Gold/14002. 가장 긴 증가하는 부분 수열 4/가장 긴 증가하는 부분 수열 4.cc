#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, weight = 1000000001, res = 0;
vector<int> seq, increase, dp;

void solve()
{
	cin >> n;
	seq = vector<int>(n + 1);
	dp = vector<int>(n + 1);

	dp[0] = 1;
	int len = 0;

	for (int i = 1; i <= n; ++i)
	{
		cin >> seq[i];
		dp[i] = 1;
		for (int j = 1; j < i; ++j)
		{
			if (dp[i] <= dp[j] && seq[j] < seq[i])
				dp[i] = dp[j] + 1;
		}

		len = max(len, dp[i]);
	}

	cout << len << '\n';

	for (int i = n; i > 0; --i)
	{
		if (dp[i] == len)
		{
			increase.push_back(seq[i]);
			len--;
		}
	}

	for (int i = increase.size() - 1; i >= 0; --i)
	{
		cout << increase[i] << " ";
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