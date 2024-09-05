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

int n, height;
vector<vector<int>> board;
vector<vector<int>> visited;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

void dfs(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
			continue;
		if (visited[ny][nx])
			continue;
		if (board[ny][nx] <= height)
			continue;

		dfs(ny, nx);
	}
}

void solve()
{
	cin >> n;

	board = vector<vector<int>>(n, vector<int>(n));
	visited = vector<vector<int>>(n, vector<int>(n));

	int minH = INT_MAX;
	int maxH = 0;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			cin >> board[y][x];
			minH = min(minH, board[y][x]);
			maxH = max(maxH, board[y][x]);
		}
	}

	int ret = 1;
	for (int h = minH; h < maxH; ++h)
	{
		int cnt = 0;
		height = h;
		visited = vector<vector<int>>(n, vector<int>(n));

		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				if (board[y][x] > height && visited[y][x] == 0)
				{
					cnt++;
					dfs(y, x);
				}
			}
		}

		ret = max(ret, cnt);
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