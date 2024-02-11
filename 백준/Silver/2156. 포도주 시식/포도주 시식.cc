#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
vector<int> seq, dp;
void solve()
{
	cin >> n;

	seq = vector<int>(n + 1);
	dp = vector<int>(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> seq[i];
	}

	dp[0] = 0;
	dp[1] = seq[1];
	dp[2] = seq[1] + seq[2];

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = max(dp[i - 3] + seq[i - 1] + seq[i],max(dp[i - 2] + seq[i], dp[i - 1]));
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