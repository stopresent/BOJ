#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, lines, visitedCount = 0;

vector<vector<int>> adjacent;
vector<bool> visited = { 0, };

void CreateGraph()
{
	cin >> n >> lines;
	adjacent = vector<vector<int>>(n + 1);
	visited.resize(n + 1, false);

	int u, v;
	for (int i = 0; i < lines; i++)
	{
		cin >> u >> v;
		adjacent[u].push_back(v);
		adjacent[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(adjacent[i].begin(), adjacent[i].end());
	}
}

void dfs(int here)
{
	visited[here] = true;

	for (int i = 0; i < adjacent[here].size(); ++i)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			dfs(there);
	}
}

void solve()
{
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i] == true)
		{
			visitedCount++;
		}
	}

	cout << visitedCount - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	CreateGraph();
	dfs(1);
	solve();
}
