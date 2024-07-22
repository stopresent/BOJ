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

int N, L, ret = 0;
vector<vector<int>> board;

void solve()
{
	cin >> N >> L;
	board = vector<vector<int>>(N, vector<int>(N));
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < N; ++y)
	{
		// 가로 체크
		vector<bool> garo(N, false);
		bool flag1 = true;
		int last = -1;
		for (int x = 0; x < N; ++x)
		{
			if (last == -1)
				last = board[y][x];

			if (abs(board[y][x] - last) > 1)
			{
				flag1 = false;
				break;
			}


			if (board[y][x] - last == 1)
			{
				if (x - L < 0)
				{
					flag1 = false;
					break;
				}

				int temp = board[y][x - 1];
				for (int k = 0; k < L; ++k)
				{
					if (board[y][x - k - 1] != temp)
					{
						flag1 = false;
						break;
					}

					if (garo[x - k - 1] == false)
						garo[x - k - 1] = true;
					else
					{
						flag1 = false;
						break;
					}

				}
				if (flag1 == false)
					break;
			}
			else if (last - board[y][x] == 1)
			{
				if (x + L > N)
				{
					flag1 = false;
					break;
				}

				int temp = board[y][x];
				for (int k = 0; k < L; ++k)
				{
					if (board[y][x + k] != temp)
					{
						flag1 = false;
						break;
					}

					if (garo[x + k] == false)
						garo[x + k] = true;
					else
					{
						flag1 = false;
						break;
					}

				}
				if (flag1 == false)
					break;
			}

			last = board[y][x];
		}

		if (flag1)
		{
			ret++;
			//cout << "y : " << y << "and garo ok" << endl;
		}

		// 세로 체크
		vector<bool> sero(N, false);
		bool flag2 = true;
		last = -1;
		for (int x = 0; x < N; ++x)
		{
			if (last == -1)
				last = board[x][y];

			if (abs(board[x][y] - last) > 1)
			{
				flag2 = false;
				break;
			}

			if (board[x][y] - last == 1)
			{
				if (x - L < 0)
				{
					flag2 = false;
					break;
				}

				int temp = board[x - 1][y];
				for (int k = 0; k < L; ++k)
				{
					if (board[x - k - 1][y] != temp)
					{
						flag2 = false;
						break;
					}

					if (sero[x - k - 1] == false)
						sero[x - k - 1] = true;
					else
					{
						flag2 = false;
						break;
					}

				}
				if (flag2 == false)
					break;
			}
			else if (last - board[x][y] == 1)
			{
				if (x + L > N)
				{
					flag2 = false;
					break;
				}

				int temp = board[x][y];
				for (int k = 0; k < L; ++k)
				{
					if (board[x + k][y] != temp)
					{
						flag2 = false;
						break;
					}

					if (sero[x + k] == false)
						sero[x + k] = true;
					else
					{
						flag2 = false;
						break;
					}

				}
				if (flag2 == false)
					break;
			}

			last = board[x][y];
		}

		if (flag2)
		{
			ret++;
			//cout << "y : " << y << "and sero ok" << endl;
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