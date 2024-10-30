#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<int> v;
vector<int> visited;

void solve()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 1);
	v = vector<int>(n + 1);
	visited = vector<int>(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		int p;
		cin >> p;
		if (p == -1)
			continue;
		board[p].push_back(i);
	}

	for (int i = 0; i < m; ++i)
	{
		int idx, w;
		cin >> idx >> w;
		v[idx] += w;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i])
			continue;

		queue<int> q;
		q.push(1);
		visited[1] = 1;
		while (q.empty() == false)
		{
			int here = q.front();
			q.pop();

			for (int i = 0; i < board[here].size(); ++i)
			{
				int next = board[here][i];

				if (visited[next])
					continue;

				v[next] += v[here];
				visited[next] = 1;
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << v[i] << " ";
	}
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