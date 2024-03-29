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
#include <climits>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, cnt = 0;
vector<vector<int>> board;
int visited[110][110];

void BFS(int y, int x, int height)
{
	queue<pair<int, int>> q;
	if (visited[y][x] == true || board[y][x] <= height)
		return;
	q.push({ y, x });
	visited[y][x] = true;
	cnt++;

	pair<int, int> here;
	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > n)
				continue;
			if (visited[ny][nx] == true)
				continue;
			if (board[ny][nx] <= height)
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}
}

void solve()
{
	cin >> n;
	board = vector<vector<int>>(n + 1, vector<int>(n + 1));
	int min_num = INT_MAX, max_num = 0;
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			cin >> board[y][x];
			min_num = min(min_num, board[y][x]);
			max_num = max(max_num, board[y][x]);
		}
	}

	int ans = 0;
	for (int height = min_num - 1; height < max_num; ++height)
	{
		for (int y = 1; y <= n; ++y)
		{
			for (int x = 1; x <= n; ++x)
			{
				if (board[y][x] > height)
					BFS(y, x, height);
			}
		}

		ans = max(ans, cnt);
		cnt = 0;
		::memset(&visited, 0, sizeof(visited));
	}

	cout << ans;
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