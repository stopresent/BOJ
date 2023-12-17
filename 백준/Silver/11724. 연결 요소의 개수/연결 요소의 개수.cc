#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, res = 0;
// 행렬을 만들어야 됨
vector<vector<int>> matrix;
vector<bool> discovered;
vector<bool> visited;

void setting()
{
	cin >> n >> m;
	matrix = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
	discovered = vector<bool>(n + 1, false);
	visited = vector<bool>(n + 1, false);

	int u, v;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}
}

void bfs(int here)
{
	queue<int> q;
	q.push(here);
	discovered[here] = true;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		visited[here] = true;

		for (int there = 1; there <= n; ++there)
		{
			if (matrix[here][there] == -1)
				continue;
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;
		}
	}

	res++;
}

void solve()
{
	for (int i = 1; i <= n; ++i)
	{
		if (discovered[i] == false)
		{
			bfs(i);
		}
	}

	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	setting();
	solve();

	return 0;
}