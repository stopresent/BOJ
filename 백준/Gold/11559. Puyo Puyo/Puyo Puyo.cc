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

// 뿌요뿌요
// 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 한꺼번에 없어진다. -> BFS
// 이 때 1연쇄가 시작
// 중력은 항상 적용
// 색은 R, G, B, P, Y
// 빈공간은 .
// 몇 연쇄가 일어나는지 알아내는것이 목표

using namespace std;

void setting();
void BFS(int y, int x);
void move(int y, int x);
void visitedClear();
void printBoard();
void gameStart();
void solve();

bool flag = false;
int boomCnt = 0, maxBoomCnt = 0;
char board[13][7];
int visited[13][7];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<char>> puyoes;
void setting()
{
	for (int i = 1; i <= 12; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] != '.')
			{
				puyoes.push_back({ board[i][j] });
			}
		}
	}
}

void BFS(int y, int x)
{
	vector<pair<int, int>> boomList;
	queue<pair<int, int>> q;
	if (visited[y][x] == false && board[y][x] != '.')
	{
		q.push({ y, x });
		visited[y][x] = 1;
	}

	pair<int, int> here;
	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		boomList.push_back(here);

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > 12 || nx > 6)
				continue;
			if (visited[ny][nx] == 1)
				continue;
			if (board[ny][nx] != board[here.first][here.second])
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	if (boomList.size() >= 4)
	{
		// 연쇄 시작
		for (int i = 0; i < boomList.size(); ++i)
		{
			board[boomList[i].first][boomList[i].second] = '.';
		}

		flag = true;
		//boomCnt++;
		//maxBoomCnt = max(maxBoomCnt, boomCnt);
	}
}

void move(int y, int x)
{
	char ch = board[y][x];

	while (true)
	{
		int ny = y + 1;
		if (board[ny][x] != '.')
			break;

		board[y][x] = '.';
		board[ny][x] = ch;

		y = ny;
	}
}

void visitedClear()
{
	for (int i = 1; i <= 12; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			visited[i][j] = 0;
		}
	}
}

void printBoard()
{
	for (int i = 1; i <= 12; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			cout << board[i][j] << " ";
		}
		
		cout << endl;
	}

	cout << endl;
}

void gameStart()
{
	while (true)
	{
		//printBoard();

		for (int i = 1; i <= 12; ++i)
		{
			for (int j = 1; j <= 6; ++j)
			{
				BFS(i, j);
			}
		}
		//printBoard();

		if (flag == true)
			boomCnt++;

		for (int i = 12; i >= 1; --i)
		{
			for (int j = 1; j <= 6; ++j)
			{
				move(i, j);
			}
		}
		//printBoard();

		visitedClear();

		if (flag == false)
			break;
		flag = false;

		//cout << boomCnt << " " << maxBoomCnt << endl;
	}
	
}

void solve()
{
	setting();
	gameStart();

	cout << boomCnt;
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