#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>
using namespace std;

int n, m, min_sum = INT_MAX, ret = 1;
vector<vector<int>> board;
vector<int> visited;
vector<int> dist;

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	visited[x] = 1;

	while (q.empty() == false)
	{
		int here = q.front();
		q.pop();

		for (int there : board[here])
		{
			if (visited[there] == 1)
				continue;
			dist[there] = dist[here] + 1;
			visited[there] = 1;
			q.push(there);
		}
	}
}

void print_dist()
{
	for (int i = 1; i <= n; ++i)
	{
		cout << dist[i] << "";
	}
	cout << endl;
}

void print_board()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int there : board[i])
			cout << there << " ";
		cout << endl;
	}
}

void solve()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 1);
	visited = vector<int>(n + 1);
	dist = vector<int>(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		board[u].push_back(v);
		board[v].push_back(u);
	}

	//print_board();

	for (int i = 1; i <= n; ++i)
	{
		bfs(i);
		int sum = 0;
		for (int j = 1; j <= n; ++j)
		{
			sum += dist[j];
		}
		
		if (sum < min_sum)
		{
			min_sum = sum;
			ret = i;
		}
		//print_dist();
		//cout << i << ":" << sum << endl;
		visited = vector<int>(n + 1);
		dist = vector<int>(n + 1);
	}

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