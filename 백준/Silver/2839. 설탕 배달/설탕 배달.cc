#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp(5001);

void solve()
{
	cin >> n;

	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= n; ++i)
	{
		if (dp[i - 3] != 0 && dp[i - 5] != 0)
			dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
		else if (dp[i - 3] != 0)
			dp[i] = dp[i - 3] + 1;
		else if (dp[i - 5] != 0)
			dp[i] = dp[i - 5] + 1;
	}

	if (dp[n] == 0)
		cout << -1;
	else
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