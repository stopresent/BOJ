#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, r;

vector<bool> visited;
vector<int> graph[100001];
vector<vector<int>> adjacent;
vector<int> ans;

void CreateGraph2()
{
	visited.resize(n + 1, false);
	ans.resize(n + 1, 0);
	adjacent = vector<vector<int>>(n + 1);

	int u, v; // 간선 정보
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

int num = 1;
void dfs2(int here)
{
	visited[here] = true;
	ans[here] = num++;

	for (int i = adjacent[here].size() - 1; i >= 0; --i)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			dfs2(there);
	}

}

void printVisitedNum()
{
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r;

	CreateGraph2();
	dfs2(r);
	printVisitedNum();
}