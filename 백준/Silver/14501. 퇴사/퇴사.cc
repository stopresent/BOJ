#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, ret;
vector<pair<int, int>> v;
vector<int> dp(20);

void dfs(int l, int sum)
{
	if (l == n + 1)
	{
		ret = max(ret, sum);
		return;
	}

	if (l + v[l].first <= n + 1)
		dfs(l + v[l].first, sum + v[l].second);
	dfs(l + 1, sum);
}

void solve()
{
	cin >> n;
	v = vector<pair<int, int>>(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	dfs(1, 0);
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