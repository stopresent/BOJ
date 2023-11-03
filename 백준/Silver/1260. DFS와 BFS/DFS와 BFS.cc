#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int n, m, v;
vector<bool> visited;
vector<bool> discovered;
vector<vector<int>> adjacent;

void CreateGraph()
{
	cin >> n >> m >> v;
	visited.resize(n + 1, false);
	adjacent.resize(n + 1);
	discovered.resize(n + 1, false);

	int u, v;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		adjacent[u].push_back(v);
		adjacent[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
	{
		sort(adjacent[i].begin(), adjacent[i].end());
	}
}

void dfs(int here)
{
	visited[here] = true;
	cout << here << " ";

	for (int i = 0; i < adjacent[here].size(); ++i)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			dfs(there);
	}
}

void bfs(int here)
{
	queue<int> q;
	q.push(here);
	discovered[here] = true;

	while (q.empty() == false)
	{
		int here = q.front();
		q.pop();
		cout << here << " ";

		for (int there : adjacent[here])
		{
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	CreateGraph();
	dfs(v);
	cout << '\n';
	bfs(v);

}
