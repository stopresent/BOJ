#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;
int n, s, ret = 0;
vector<int> v;

void dfs(int idx, int temp)
{
	if (idx == n)
		return;
	if (temp + v[idx] == s) ret++;

	dfs(idx + 1, temp);
	dfs(idx + 1, temp + v[idx]);
}

void solve()
{
	cin >> n >> s;
	v.resize(n);

	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		v[i] = temp;
	}
	
	dfs(0, 0);

	cout << ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
