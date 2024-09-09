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

using namespace std;

int n, m, pre = 0, t = 0;
vector<vector<int>> board;
vector<vector<int>> visited;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
vector<pair<int, int>> melt;

void dfs(int y, int x)
{
	visited[y][x] = 1;
	
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny > n || nx < 0 || nx > m)
			continue;
		if (visited[ny][nx] == 1)
			continue;
		if (board[ny][nx] == 1)
		{
			melt.push_back({ ny, nx });
			visited[ny][nx] = 1;
			continue;
		}

		dfs(ny, nx);
	}
}

bool check()
{
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= m; ++x)
		{
			if (board[y][x] == 1)
				return true;
		}
	}

	return false;
}

void print()
{
	for (int y = 0; y < n + 1; ++y)
	{
		for (int x = 0; x < m + 1; ++x)
		{
			cout << board[y][x];
		}
		cout << endl;
	}
	
	cout << endl;
}

void solve()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 2, vector<int>(m + 2));
	visited = vector<vector<int>>(n + 2, vector<int>(m + 2));
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= m; ++x)
		{
			cin >> board[y][x];
		}
	}

	while (true)
	{
		if (check() == false)
		{
			cout << t << '\n';
			cout << pre << '\n';
			break;
		}
		
		dfs(0, 0);
		t++;
		pre = melt.size();
		for (int i = 0; i < melt.size(); ++i)
		{
			board[melt[i].first][melt[i].second] = 0;
		}
		//print();
		melt.clear();
		visited = vector<vector<int>>(n + 2, vector<int>(m + 2));

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