#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
vector<vector<long long>> dp;
int n, ret;

void solve()
{
	cin >> n;
	dp = vector<vector<long long>>(1011, vector<long long>(10));

	for (int i = 0; i < 10; ++i)
		dp[1][i] = 1;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] % MOD;
			else
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		ret = ret + dp[n][i] % MOD;
	}

	cout << ret % MOD;
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