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

int h, w;
vector<vector<char>> board;
vector<vector<int>> ans;

void solve()
{
	cin >> h >> w;
	board = vector<vector<char>>(h, vector<char>(w));
	ans = vector<vector<int>>(h, vector<int>(w));

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			if (board[y][x] == 'c')
			{
				ans[y][x] = 0;
			}
			else
			{
				int time = 0;
				bool flag = false;
				for (int i = x; i >= 0; --i)
				{
					if (board[y][i] == '.')
					{
						time++;
					}
					else if (board[y][i] == 'c')
					{
						flag = true;
						break;
					}
				}

				if (flag == false)
				{
					ans[y][x] = -1;
				}
				else
				{
					ans[y][x] = time;
				}
			}
		}
	}

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			cout << ans[y][x] << " ";
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