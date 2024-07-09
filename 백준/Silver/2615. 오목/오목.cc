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
vector<vector<int>> board(20, vector<int>(20, 0));
int ansY = 0, ansX = 0;

bool om(int y, int x)
{
	int num = board[y][x];

	// 가로 ㅡ
	if (x + 4 < 19 && num == board[y][x + 1] && num == board[y][x + 2] && num == board[y][x + 3] && num == board[y][x + 4])
	{
		if (x + 5 < 19 && num == board[y][x + 5])
		{
			//return false;
		}
		else if (x - 1 >= 0 && num == board[y][x - 1])
		{

		}
		else
		{
			ansY = y + 1;
			ansX = x + 1;
			return true;
		}
	}

	// 세로 |
	if (y + 4 < 19 && num == board[y + 1][x] && num == board[y + 2][x] && num == board[y + 3][x] && num == board[y + 4][x])
	{
		if (y + 5 < 19 && num == board[y + 5][x])
		{
			//return false;
		}
		else if (y - 1 >= 0 && num == board[y - 1][x])
		{

		}
		else
		{
			ansY = y + 1;
			ansX = x + 1;
			return true;
		}
	}

	// 오른쪽 아래 
	if (x + 4 < 19 && y + 4 < 19 && num == board[y + 1][x + 1] && num == board[y + 2][x + 2] && num == board[y + 3][x + 3] && num == board[y + 4][x + 4])
	{
		if (x + 5 < 19 && y + 5 < 19 && num == board[y + 5][x + 5])
		{
			//return false;
		}
		else if (x - 1 >= 0 && y - 1 >= 0 && num == board[y - 1][x - 1])
		{

		}
		else
		{
			ansY = y + 1;
			ansX = x + 1;
			return true;
		}
	}

	// 왼쪽 아래 /
	if (x - 4 >= 0 && y + 4 < 19 && num == board[y + 1][x - 1] && num == board[y + 2][x - 2] && num == board[y + 3][x - 3] && num == board[y + 4][x - 4])
	{
		if (x - 5 >= 0 && y + 5 < 19 && num == board[y + 5][x - 5])
		{
			//return false;
		}
		else if (x + 1 < 19 && y - 1 >= 0 && num == board[y - 1][x + 1])
		{

		}
		else
		{
			ansY = y + 5;
			ansX = x - 3;
			return true;
		}
	}

	return false;
}

void solve()
{
	for (int y = 0; y < 19; ++y)
	{
		for (int x = 0; x < 19; ++x)
		{
			cin >> board[y][x];
		}
	}

	bool flag = false;
	for (int y = 0; y < 19; ++y)
	{
		for (int x = 0; x < 19; ++x)
		{
			if (board[y][x] != 0)
			{
				if (om(y, x))
				{
					cout << board[y][x] << '\n';
					cout << ansY << " " << ansX << '\n';
					flag = true;
					break;
				}
			}
		}
	}

	if (flag == false)
		cout << 0;
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