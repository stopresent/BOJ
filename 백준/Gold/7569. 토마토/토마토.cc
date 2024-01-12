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

struct Pos
{
	int z, y, x;
};

int m, n, h;
vector<vector<vector<int>>> board;
vector<vector<vector<int>>> discovered;
queue<Pos> q;
void setting()
{
	cin >> m >> n >> h;
	board = vector<vector<vector<int>>>(h + 1, vector<vector<int>>(n + 1, vector<int>(m + 1)));
	discovered = vector<vector<vector<int>>>(h + 1, vector<vector<int>>(n + 1, vector<int>(m + 1)));

	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
				{
					q.push({ i, j, k });
					discovered[i][j][k] = 1;
				}
			}
		}
	}

	//for (int i = 1; i <= h; ++i)
	//{
	//	for (int j = 1; j <= n; ++j)
	//	{
	//		for (int k = 1; k <= m; ++k)
	//		{
	//			cout << board[i][j][k];
	//		}
	//		cout << endl;
	//	}
	//}
}

int dy[] = { -1, 0, 1, 0, 0, 0 };
int dx[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
void BFS(int z, int y, int x)
{
	//queue<Pos> q;
	//q.push({ z, y, x });
	discovered[z][y][x] = 1;

	while (q.empty() == false)
	{
		Pos here = q.front();
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int nz = here.z + dz[i];
			int ny = here.y + dy[i];
			int nx = here.x + dx[i];

			if (discovered[nz][ny][nx])
				continue;
			if (board[nz][ny][nx] == -1)
				continue;
			if (nz < 1 || ny < 1 || nx < 1 || nz > h || ny > n || nx > x)
				continue;

			discovered[nz][ny][nx] = discovered[here.z][here.y][here.x] + 1;
			q.push({ nz, ny, nx });
		}
	}
}

void solve()
{
	//discovered[z][y][x] = 1;

	while (q.empty() == false)
	{
		Pos here = q.front();
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int nz = here.z + dz[i];
			int ny = here.y + dy[i];
			int nx = here.x + dx[i];

			if (nz < 1 || ny < 1 || nx < 1 || nz > h || ny > n || nx > m)
				continue;
			if (discovered[nz][ny][nx] >= 1)
				continue;
			if (board[nz][ny][nx] == -1)
				continue;
			if (board[nz][ny][nx] == 1)
				continue;
			
			discovered[nz][ny][nx] = discovered[here.z][here.y][here.x] + 1;
			q.push({ nz, ny, nx });
		}
	}

	//for (int i = 1; i <= h; ++i)
	//{
	//	for (int j = 1; j <= n; ++j)
	//	{
	//		for (int k = 1; k <= m; ++k)
	//		{
	//			cout << discovered[i][j][k];
	//		}
	//		cout << endl;
	//	}
	//}

	bool flag = false;
	int res = 0;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				if (discovered[i][j][k] == 0 && board[i][j][k] != -1)
				{
					flag = true;
					cout << -1 << '\n';
					return;
				}

				res = max(res, discovered[i][j][k]);
			}
		}
	}

	cout << res - 1;
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