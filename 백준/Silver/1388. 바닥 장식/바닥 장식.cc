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

int n, m;
vector<vector<char>> board;
vector<vector<bool>> visited;

void solve()
{
	cin >> n >> m;
	board = vector<vector<char>>(n, vector<char>(m, ' '));
	visited = vector<vector<bool>>(n, vector<bool>(m, false));

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			cin >> board[y][x];
		}
	}

	int ret = 0;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (visited[y][x])
				continue;

			if (board[y][x] == '-')
			{
				visited[y][x] = true;
				ret++;

				for (int i = x + 1; i < m; ++i)
				{
					if (board[y][i] == '-')
					{
						visited[y][i] = true;
					}
					else
					{
						break;
					}
				}
			}
			else if (board[y][x] == '|')
			{
				visited[y][x] = true;
				ret++;

				for (int i = y + 1; i < n; ++i)
				{
					if (board[i][x] == '|')
					{
						visited[i][x] = true;
					}
					else
					{
						break;
					}
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