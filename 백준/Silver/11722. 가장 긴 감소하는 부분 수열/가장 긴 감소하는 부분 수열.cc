#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v, dp(1010, 1);

void solve()
{
	cin >> n;
	v = vector<int>(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (v[j] > v[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ret = *max_element(dp.begin(), dp.end());

	cout << ret;
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