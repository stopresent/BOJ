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

int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const int side = 110;
vector<vector<int>> board(101, vector<int>(101, 0));

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				board[y + j][x + k]++;
			}
		}
	}

	int ret = 0;
	for (int y = 0; y < 100; ++y)
	{
		for (int x = 0; x < 100; ++x)
		{
			if (board[y][x] == 0)
				continue;

			int cnt = 0;
			for (int i = 0; i < 4; ++i)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (board[ny][nx] == 0)
				{
					ret++;
				}
			}

		}
	}

	cout << ret;
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