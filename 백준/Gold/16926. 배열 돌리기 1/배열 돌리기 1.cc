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

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int N, M, R;
vector<vector<int>> board;

void TurnBoard(vector<vector<int>>& v)
{
	vector<vector<int>> save = v;
	int cnt = min(N, M) / 2;

	for (int i = 0; i < cnt; ++i)
	{
		int start = v[i][i];
		int r = i;
		int c = i;

		int k = 0;
		while (k < 4)
		{
			int nr = r + dy[k];
			int nc = c + dx[k];

			if (nr == i && nc == i)
				break;
			if (i <= nr && nr < N - i && i <= nc && nc < M - i)
			{
				v[r][c] = v[nr][nc];
				r = nr;
				c = nc;
			}
			else
			{
				k++;
			}
		}

		v[i + 1][i] = start;
	}
}

void solve()
{
	cin >> N >> M >> R;
	board = vector<vector<int>>(N, vector<int>(M, 0));
	
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> board[y][x];
		}
	}

	for (int i = 0; i < R; ++i)
	{
		TurnBoard(board);
	}

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cout << board[y][x] << " ";
		}

		cout << '\n';
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