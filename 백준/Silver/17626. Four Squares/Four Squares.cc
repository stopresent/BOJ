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

const int MAX = 1234567890;
int n;

void solve()
{
	cin >> n;
	vector<int>dp(n + 1, 0);
	dp[1] = 1;

	for (int i = 2; i <= n; i++) 
	{
		int minn = MAX;
		for (int j = 1; j * j <= i; j++) 
		{
			int tmp = i - j * j;
			minn = min(minn, dp[tmp]);
		}
		dp[i] = minn + 1;
	}
	cout << dp[n];
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