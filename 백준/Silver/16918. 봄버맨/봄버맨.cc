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

int R, C, N;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
vector<vector<char>> board;

void PrintBoard()
{
	for (int y = 0; y < R; ++y)
	{
		for (int x = 0; x < C; ++x)
		{
			cout << board[y][x];
		}

		cout << endl;
	}
}

void solve()
{
	cin >> R >> C >> N;
	board = vector<vector<char>>(R, vector<char>(C));

	for (int y = 0; y < R; ++y)
	{
		for (int x = 0; x < C; ++x)
		{
			cin >> board[y][x];
		}
	}

	int time = 1;

	//PrintBoard();

	while (true)
	{
		if (time == N)
		{
			PrintBoard();
			break;
		}

		// 폭탄의 위치를 기억한다
		vector<pair<int, int>> save;
		for (int y = 0; y < R; ++y)
		{
			for (int x = 0; x < C; ++x)
			{
				if (board[y][x] == 'O')
				{
					save.push_back({ y, x });
				}
			}
		}
		// 보드를 폭탄으로 매운다
		for (int y = 0; y < R; ++y)
		{
			for (int x = 0; x < C; ++x)
			{
				board[y][x] = 'O';
			}
		}
		time++;
		if (time == N)
		{
			PrintBoard();
			break;
		}

		// 기억한 폭탄이 터진다
		for (int i = 0; i < save.size(); ++i)
		{
			int cy = save[i].first;
			int cx = save[i].second;
			board[cy][cx] = '.';

			for (int j = 0; j < 4; ++j)
			{
				int ny = cy + dy[j];
				int nx = cx + dx[j];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C)
					continue;
				board[ny][nx] = '.';
			}
		}
		time++;
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