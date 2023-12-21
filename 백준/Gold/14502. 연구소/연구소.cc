#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct Pos
{
	int y;
	int x;
};

int visited[10][10];
int n, m;
vector<vector<int>> board;
vector<Pos> wall;
vector<Pos> virus;

// 0 : 빈 칸
// 1 : 벽
// 2 : 바이러스가 있는 위치
void setting()
{
	cin >> n >> m;
	board = vector<vector<int>>(n, vector<int>(m));

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			cin >> board[y][x];
			if (board[y][x] == 0)
				wall.push_back({ y, x });
			if (board[y][x] == 2)
				virus.push_back({ y, x });
		}
	}
}

// 퍼지는 함수

void print_board()
{
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x)
{
	for (int i = 0; i < 4; ++i)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= m)
			continue;
		if (visited[nextY][nextX])
			continue;
		if (board[nextY][nextX])
			continue;
		visited[nextY][nextX] = true;
		dfs(nextY, nextX);
	}
}

int spread()
{
	int res = 0;
	memset(visited, 0, sizeof(visited));
	for (Pos pos : virus)
	{
		visited[pos.y][pos.x] = 1;
		dfs(pos.y, pos.x);
	}
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			if (board[y][x] == 0 && visited[y][x] == 0)
				res++;

	return res;
}

// 1. 벽을 3개 세운다
// 2. 바이러스가 퍼진다.
// 3. 안전한 영역의 개수를 구한다.
void solve()
{
	int res = 0;

	// 벽을 만든다.
	// 조합
	int wallSize = wall.size();
	for (int i = 0; i < wallSize; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			for (int k = 0; k < j; ++k)
			{
				board[wall[i].y][wall[i].x] = 1;
				board[wall[j].y][wall[j].x] = 1;
				board[wall[k].y][wall[k].x] = 1;

				//print_board();
				res = max(res, spread());

				board[wall[i].y][wall[i].x] = 0;
				board[wall[j].y][wall[j].x] = 0;
				board[wall[k].y][wall[k].x] = 0;
			}
		}
	}

	cout << res << '\n';
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