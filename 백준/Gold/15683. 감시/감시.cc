#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void CCTV1(int y, int x, int dir);
void CCTV2(int y, int x, int dir);
void CCTV3(int y, int x, int dir);
void CCTV4(int y, int x, int dir);
void CCTV5(int y, int x, int dir);
void visitedClear();
int checkResult();
void solve();

// 1번 : 한쪽 방향만 체크
// 2번 : 정반대 방향으로 체크 (한 라인 체크)
// 3번 : 직각 방향으로 체크
// 4번 : 한 방향으로 제외하고 체크
// 5번 : 모든 방향 체크

// cctv는 최대 8개이다.
// 하나의 cctv는 최대 4번 경우의 수가 존재한다. -> 브루트포스로 해도 될거같다.

// 번호마다 체크하는 방법이 필요하다.

enum Dir
{
	UP,		// 0
	RIGHT,	// 1
	DOWN,	// 2
	LEFT,	// 3
};

int n, m, cctvCount, ch[20], res = 123456789;
vector<vector<int>> board;
vector<vector<int>> visited;
vector<pair<int, int>> cctvs;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void CCTV1(int y, int x, int dir)
{
	int curY = y;
	int curX = x;
	while (true)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 1 || nx < 1 || ny > n || nx > m)
			break;
		if (board[ny][nx] == 6)
			break;

		y = ny;
		x = nx;

		visited[ny][nx] = 1;
	}
}

void CCTV2(int y, int x, int dir)
{
	int curY = y;
	int curX = x;
	while (true)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 1 || nx < 1 || ny > n || nx > m)
			break;
		if (board[ny][nx] == 6)
			break;

		y = ny;
		x = nx;

		visited[ny][nx] = 1;
	}

	dir = (dir + 2) % 4;
	y = curY;
	x = curX;
	while (true)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 1 || nx < 1 || ny > n || nx > m)
			break;
		if (board[ny][nx] == 6)
			break;

		y = ny;
		x = nx;

		visited[ny][nx] = 1;
	}
}

void CCTV3(int y, int x, int dir)
{
	int curY = y;
	int curX = x;
	while (true)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 1 || nx < 1 || ny > n || nx > m)
			break;
		if (board[ny][nx] == 6)
			break;

		y = ny;
		x = nx;

		visited[ny][nx] = 1;
	}

	y = curY;
	x = curX;
	dir = (dir + 1) % 4;
	while (true)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 1 || nx < 1 || ny > n || nx > m)
			break;
		if (board[ny][nx] == 6)
			break;

		y = ny;
		x = nx;

		visited[ny][nx] = 1;
	}
}

void CCTV4(int y, int x, int dir)
{
	int curY = y;
	int curX = x;
	while (true)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 1 || nx < 1 || ny > n || nx > m)
			break;
		if (board[ny][nx] == 6)
			break;

		y = ny;
		x = nx;

		visited[ny][nx] = 1;
	}

	y = curY;
	x = curX;
	dir = (dir + 1) % 4;
	while (true)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 1 || nx < 1 || ny > n || nx > m)
			break;
		if (board[ny][nx] == 6)
			break;

		y = ny;
		x = nx;

		visited[ny][nx] = 1;
	}

	y = curY;
	x = curX;
	dir = (dir + 2) % 4;
	while (true)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 1 || nx < 1 || ny > n || nx > m)
			break;
		if (board[ny][nx] == 6)
			break;

		y = ny;
		x = nx;

		visited[ny][nx] = 1;
	}
}

void CCTV5(int y, int x, int dir)
{
	int curY = y;
	int curX = x;
	for (int i = 1; i <= 4; ++i)
	{
		while (true)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 1 || nx < 1 || ny > n || nx > m)
				break;
			if (board[ny][nx] == 6)
				break;

			y = ny;
			x = nx;

			visited[ny][nx] = 1;
		}

		dir = (dir + i) % 4;
		y = curY;
		x = curX;
	}
}

void visitedClear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			visited[i][j] = 0;
		}
	}
}

int checkResult()
{
	int res = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (board[i][j] == 1 || board[i][j] == 2 || board[i][j] == 3 || board[i][j] == 4 || board[i][j] == 5 || board[i][j] == 6)
				continue;

			if (visited[i][j] == 0 )
				res++;
		}
	}

	return res;
}

void printVisited()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

void DFS(int s, int L)
{
	if (L == cctvCount)
	{
		for (int i = 0; i < L; ++i)
		{
			// ch[i] 가 dir
			// i는 cctv인덱스

			if (board[cctvs[i].first][cctvs[i].second] == 1)
			{
				CCTV1(cctvs[i].first, cctvs[i].second, ch[i]);
			}
			else if (board[cctvs[i].first][cctvs[i].second] == 2)
			{
				CCTV2(cctvs[i].first, cctvs[i].second, ch[i]);
			}
			else if (board[cctvs[i].first][cctvs[i].second] == 3)
			{
				CCTV3(cctvs[i].first, cctvs[i].second, ch[i]);
			}
			else if (board[cctvs[i].first][cctvs[i].second] == 4)
			{
				CCTV4(cctvs[i].first, cctvs[i].second, ch[i]);
			}
			else if (board[cctvs[i].first][cctvs[i].second] == 5)
			{
				CCTV5(cctvs[i].first, cctvs[i].second, ch[i]);
			}
		}

		res = min(res, checkResult());

		//printVisited();

		visitedClear();

		//cout << ch[i] << " ";
		//cout << endl;
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			ch[L] = i;
			DFS(i + 1, L + 1);
		}
	}
}

void solve()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 1, vector<int>(m + 1));
	visited = vector<vector<int>>(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5)
				cctvs.push_back({ i, j });
		}
	}

	cctvCount = cctvs.size();

	DFS(0, 0);

	cout << res;
	// cctv가 3개
	// 경우의 수
	// 0 0 0
	// 0 0 1
	// 0 0 2
	// 0 0 3
	// 0 1 0
	// 0 1 1
	// 0 1 2
	// 0 1 3
	// 0 2 0
	// ...

	// 4 * 4 * 4
	// 64
	
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