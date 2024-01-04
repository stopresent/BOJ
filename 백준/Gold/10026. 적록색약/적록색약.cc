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
vector<vector<char>> board;
int discovered[101][101];
int n, r = 0, g = 0, b = 0;

void setting()
{
	cin >> n;
	board = vector<vector<char>>(n + 1, vector<char>(n + 1));
	string str;
	for (int y = 1; y <= n; ++y)
	{
		cin >> str;
		for (int x = 1; x <= n; ++x)
		{
			board[y][x] = str[x - 1];
		}
	}
}

queue<pair<int, int>> q;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void BFS(int y, int x)
{
	if (discovered[y][x])
		return;
	char ch = board[y][x];
	if (ch == 'R')
		r++;
	else if (ch == 'G')
		g++;
	else
		b++;
	q.push({ y, x });
	discovered[y][x] = 1;

	while (q.empty() == false)
	{
		pair<int, int> here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > n)
				continue;
			if (discovered[ny][nx] == 1)
				continue;
			if (board[ny][nx] != ch)
				continue;

			discovered[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

void BFS2(int y, int x)
{
	if (discovered[y][x])
		return;
	char ch = board[y][x];
	if (ch == 'R')
		r++;
	else if (ch == 'B')
		b++;
	else
		g++;
	q.push({ y, x });
	discovered[y][x] = 1;

	while (q.empty() == false)
	{
		pair<int, int> here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > n)
				continue;
			if (discovered[ny][nx] == 1)
				continue;
			if (ch == 'B' && board[ny][nx] != ch)
				continue;
			if (ch == 'R' && board[ny][nx] == 'B')
				continue;
			if (ch == 'G' && board[ny][nx] == 'B')
				continue;

			discovered[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

void solve()
{
	setting();

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			BFS(y, x);
		}
	}

	//cout << r << " " << g << " " << b << '\n';
	cout << r + g + b << " ";
	memset(discovered, 0, sizeof(discovered));
	r = g = b = 0;

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			BFS2(y, x);
		}
	}
	//cout << r << " " << g << " " << b;
	cout << r + g + b;
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