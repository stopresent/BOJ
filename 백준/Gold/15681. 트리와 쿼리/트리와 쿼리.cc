#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, R, Q;
vector<vector<int>> board;
vector<int> visited;
vector<int> parent;
vector<int> dist;
vector<int> sizes;

int dfs(int x)
{
	visited[x] = 1;
	sizes[x] = 1;

	for (int i = 0; i < board[x].size(); ++i)
	{
		int next = board[x][i];
		if (visited[next])
			continue;
		sizes[x] += dfs(next);
	}

	return sizes[x];
}

void solve()
{
	cin >> N >> R >> Q;
	board = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1);
	parent = vector<int>(N + 1);
	dist = vector<int>(N + 1);
	sizes = vector<int>(N + 1);
	for (int i = 0; i < N - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		board[u].push_back(v);
		board[v].push_back(u);
	}

	dfs(R);

	for (int i = 0; i < Q; ++i)
	{
		int u;
		cin >> u;
		cout << sizes[u] << '\n';
	}

	/*parent[R] = R;
	dist[R] = 0;
	queue<int> q;
	q.push(R);
	visited[R] = 1;
	while (q.empty() == false)
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < board[here].size(); ++i)
		{
			int next = board[here][i];
			if (visited[next])
				continue;
			parent[next] = here;
			dist[next] = dist[here] + 1;
			visited[next] = 1;
			q.push(next);
		}
	}

	for (int i = 0; i < Q; ++i)
	{
		int u;
		cin >> u;
		visited = vector<int>(N + 1);
		q.push(u);
		int cnt = 1;
		visited[u] = 1;
		while (q.empty() == false)
		{
			int here = q.front();
			q.pop();

			for (int i = 0; i < board[here].size(); ++i)
			{
				int next = board[here][i];
				if (next == parent[here])
					continue;
				if (visited[next])
					continue;
				visited[next] = 1;
				q.push(next);
				cnt++;
			}
		}

		cout << cnt << '\n';
	}*/
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