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

long long ret = 0;
int t, n;
long long dp[100] = { 0 };

long long pibo(int n)
{
	if (dp[n] != 0)
		return dp[n];

	return dp[n] = pibo(n - 1) + pibo(n - 2) + pibo(n - 3) + pibo(n - 4);
}

void solve()
{
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	cin >> t;
	while (t--)
	{
		cin >> n;
		long long ret = pibo(n);
		cout << ret << '\n';
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