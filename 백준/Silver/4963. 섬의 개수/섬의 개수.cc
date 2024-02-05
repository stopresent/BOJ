#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int w = -1, h = -1, res = 0;
int board[51][51];
int discovered[51][51];

int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };
int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
void BFS(pair<int, int> here)
{
	if (board[here.first][here.second] == 0)
		return;

	queue<pair<int, int>> q;
	q.push(here);

	if (board[here.first][here.second] == 1 && discovered[here.first][here.second] == 0)
		res++;
	discovered[here.first][here.second] = 1;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > h || nx > w)
				continue;
			if (discovered[ny][nx] == 1)
				continue;
			if (board[ny][nx] == 0)
				continue;

			q.push({ ny, nx });
			discovered[ny][nx] = 1;
		}
	}
	
}

void solve()
{
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 1; i <= h; ++i)
		{
			for (int j = 1; j <= w; ++j)
			{
				cin >> board[i][j];
			}
		}

		::memset(discovered, 0, sizeof(discovered));
		res = 0;
		for (int i = 1; i <= h; ++i)
		{
			for (int j = 1; j <= w; ++j)
			{
				BFS({ i, j });
			}
		}

		cout << res << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}