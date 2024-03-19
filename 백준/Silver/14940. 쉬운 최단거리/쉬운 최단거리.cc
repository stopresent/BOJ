#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int n, m;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<int>> board;
vector<vector<int>> dist;
queue<pair<int, int>> q;

void solve()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 1, vector<int>(m + 1));
	dist = vector<vector<int>>(n + 1, vector<int>(m + 1));

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			dist[y][x] = -1;
			cin >> board[y][x];
			if (board[y][x] == 2)
			{
				q.push({ y, x });
				dist[y][x] = 0;
			}
		}
	}

	pair<int, int> here;
	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (dist[ny][nx] != -1)
				continue;
			if (board[ny][nx] == 0)
				continue;
			dist[ny][nx] = dist[here.first][here.second] + 1;
			q.push({ ny, nx });
		}
	}

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (board[y][x] == 0)
				cout << 0 << " ";
			else
				cout << dist[y][x] << " ";
		}
		cout << '\n';
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