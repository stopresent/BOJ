#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, t;
long long dp[200];

void solve()
{
	cin >> t;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 100; ++i)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	int temp;
	for (int i = 0; i < t; ++i)
	{
		cin >> temp;
		cout << dp[temp] << '\n';
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