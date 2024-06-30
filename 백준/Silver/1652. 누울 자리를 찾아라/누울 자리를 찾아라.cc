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

void solve()
{
	int N;
	cin >> N;
	vector<vector<char>> board(N + 1, vector<char>(N + 1, '.'));
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> board[y][x];
		}
	}

	int ans1 = 0, ans2 = 0; // 가로 세로 가능한 공간 수

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N - 1; ++x)
		{
			if (board[y][x] == '.' && board[y][x + 1] == '.')
			{
				ans1++;
			}

			while (true)
			{
				if (x == N)
					break;
				if (board[y][x] == 'X')
					break;
				x++;
			}
		}
	}

	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < N - 1; ++y)
		{
			if (board[y][x] == '.' && board[y + 1][x] == '.')
			{
				ans2++;
			}

			while (true)
			{
				if (y == N)
					break;
				if (board[y][x] == 'X')
					break;
				y++;
			}
		}
	}

	cout << ans1 << " " << ans2;
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