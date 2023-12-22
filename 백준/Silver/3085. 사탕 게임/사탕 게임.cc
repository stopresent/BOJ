#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, res = 0;
vector<vector<char>> board;

void setting()
{
	cin >> n;
	board = vector<vector<char>>(n, vector<char>(n));

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
			cin >> board[y][x];
}

// 문제의 해결 로직
// 1. 색이 서로 다른 인접한 사탕을 고른다. -> 하나의 사탕 당 상하좌우
// 2. 위치를 변경한다.
// 3. 최대 길이 수열을 찾는다.
// 4. 보드의 모든 경우에서 위의 행위를 반복한다.
int check_lis()
{
	int res = 0, cnt = 0;
	char ch;

	for (int y = 0; y < n; ++y)
	{
		ch = board[y][0];
		cnt = 1;

		for (int x = 1; x < n; ++x)
		{
			if (ch == board[y][x])
			{
				cnt++;
				res = max(res, cnt);
			}
			else
			{
				cnt = 1;
				ch = board[y][x];
			}
		}
	}

	cnt = 0;

	for (int x = 0; x < n; ++x)
	{
		ch = board[0][x];
		cnt = 1;

		for (int y = 1; y < n; ++y)
		{
			if (ch == board[y][x])
			{
				cnt++;
				res = max(res, cnt);
			}
			else
			{
				cnt = 1;
				ch = board[y][x];
			}
		}
	}

	return res;
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void solve()
{
	int res = 0;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 1; x < n; ++x)
		{
			for (int i = 0; i < 4; ++i)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
					continue;
				if (board[y][x] == board[ny][nx])
					continue;
				swap(board[y][x], board[ny][nx]);
				res = max(res, check_lis());
				swap(board[y][x], board[ny][nx]);
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