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

char board[400][400];

void draw(int len, int y, int x)
{
	for (int i = 0; i < len; ++i)
	{
		if (i == 0 || i == len - 1)
		{
			for (int j = 0; j < len; ++j)
			{
				board[y + i][x + j] = '*';
			}
		}
		else
		{
			board[y + i][x] = '*';
			board[y + i][x + len - 1] = '*';
		}
	}
}

void dfs(int n, int y, int x)
{
	int len = 4 * n - 3;
	draw(len, y, x);
	
	if (n == 1)
		return;

	dfs(n - 1, y + 2, x + 2);
}

void solve()
{
	int n;
	cin >> n;

	for (int y = 0; y < 4 * n - 3; ++y)
	{
		for (int x = 0; x < 4 * n - 3; ++x)
		{
			board[y][x] = ' ';
		}
	}

	dfs(n, 0, 0);

	for (int y = 0; y < 4 * n - 3; ++y)
	{
		for (int x = 0; x < 4 * n - 3; ++x)
		{
			cout << board[y][x];
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