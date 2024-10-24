#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

void solve()
{
	cin >> n;
	v = vector<int>(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	vector<int> dp(v);
	
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (v[j] < v[i])
				dp[i] = max(dp[i], dp[j] + v[i]);
		}
	}
	
	cout << *max_element(dp.begin(), dp.end());
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