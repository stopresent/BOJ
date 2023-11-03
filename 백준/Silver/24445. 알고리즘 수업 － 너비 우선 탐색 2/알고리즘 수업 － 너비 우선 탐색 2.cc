#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, r;

vector<bool> discovered;
vector<int> graph[100001];
vector<vector<int>> adjacent;
vector<int> ans;

void CreateGraph()
{
	discovered.resize(n + 1, false);
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
		reverse(adjacent[i].begin(), adjacent[i].end());
	}
}

int num = 1;
void bfs(int here)
{
	queue<int> q;
	q.push(here);
	discovered[here] = true;
	

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		ans[here] = num++;

		for (int there : adjacent[here])
		{
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;
		}
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

	CreateGraph();
	bfs(r);
	printVisitedNum();
}