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

int N, want;
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<int>> board;

bool CanGo(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	if (board[y][x] != 0)
		return false;

	return true;
}

void solve()
{
	cin >> N >> want;
	board = vector<vector<int>>(N, vector<int>(N));

	pair<int, int> pos = { 0, 0 }, want_pos = { 1, 1 };
	int value = N * N;
	board[pos.first][pos.second] = value;
	int dir = 0;
	while (true)
	{
		if (pos.first == N / 2 && pos.second == N / 2)
			break;

		int ny = pos.first + dy[dir];
		int nx = pos.second + dx[dir];
		if (CanGo(ny, nx))
		{
			value--;
			board[ny][nx] = value;
			pos.first = ny;
			pos.second = nx;
			if (value == want)
			{
				want_pos.first = ny + 1;
				want_pos.second = nx + 1;
			}
		}
		else
		{
			dir = (dir + 1) % 4;
		}
	}

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cout << board[y][x] << " ";
		}
		cout << '\n';
	}

	cout << want_pos.first << " " << want_pos.second;
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