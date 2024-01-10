#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int n, dp[500];
vector<int> seq(500);

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> seq[i];
	}

	dp[1] = seq[1];
	dp[2] = seq[1] + seq[2];
	dp[3] = max(seq[1] + seq[3], seq[2] + seq[3]);

	for (int i = 4; i <= n; ++i)
	{
		dp[i] = max(dp[i - 2] + seq[i], dp[i - 3] + seq[i - 1] + seq[i]);
	}

	cout << dp[n];
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