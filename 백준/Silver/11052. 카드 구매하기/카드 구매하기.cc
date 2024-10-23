#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, ret;
vector<int> v;
vector<int> dp(1001);

void solve()
{
	cin >> n;
	v = vector<int>(n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];

		for (int j = i; j > 0; --j)
		{
			dp[i] = max(dp[i], dp[i - j] + v[j]);
		}
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