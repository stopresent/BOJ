#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct block1
{

};

int n, m, res = 0;
vector<vector<int>> board;
void solve()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 1, vector<int>(m + 1));

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= m; ++x)
		{
			cin >> board[y][x];
		}
	}

	// ㅡ 
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= m - 3; ++x)
		{
			int temp = 0;
			temp += board[y][x];
			temp += board[y][x + 1];
			temp += board[y][x + 2];
			temp += board[y][x + 3];

			res = max(res, temp);
		}
	}

	// ㅣ 
	for (int y = 1; y <= n - 3; ++y)
	{
		for (int x = 1; x <= m; ++x)
		{
			int temp = 0;
			temp += board[y + 0][x];
			temp += board[y + 1][x];
			temp += board[y + 2][x];
			temp += board[y + 3][x];

			res = max(res, temp);
		}
	}

	// ㅁ 
	for (int y = 1; y <= n - 1; ++y)
	{
		for (int x = 1; x <= m - 1; ++x)
		{
			int temp = 0;
			temp += board[y + 0][x + 0];
			temp += board[y + 0][x + 1];
			temp += board[y + 1][x + 0];
			temp += board[y + 1][x + 1];

			res = max(res, temp);
		}
	}

	// L 
	for (int y = 1; y <= n - 2; ++y)
	{
		for (int x = 1; x <= m - 1; ++x)
		{
			int temp = 0;
			temp += board[y][x];
			temp += board[y + 1][x];
			temp += board[y + 2][x];
			temp += board[y + 2][x + 1];

			res = max(res, temp);
		}
	}

	// L 대칭
	for (int y = 1; y <= n - 2; ++y)
	{
		for (int x = 1; x <= m - 1; ++x)
		{
			int temp = 0;
			temp += board[y + 0][x + 1];
			temp += board[y + 1][x + 1];
			temp += board[y + 2][x + 1];
			temp += board[y + 2][x + 0];

			res = max(res, temp);
		}
	}

	// ㄴ
	for (int y = 1; y <= n - 1; ++y)
	{
		for (int x = 1; x <= m - 2; ++x)
		{
			int temp = 0;
			temp += board[y][x];
			temp += board[y + 1][x];
			temp += board[y + 1][x + 1];
			temp += board[y + 1][x + 2];

			res = max(res, temp);
		}
	}

	// ㄴ 뒤집은거
	for (int y = 2; y <= n; ++y)
	{
		for (int x = 1; x <= m - 2; ++x)
		{
			int temp = 0;
			for (int k = 0; k < 3; ++k)
			{
				temp += board[y][x + k];
			}
			temp += board[y - 1][x + 2];

			res = max(res, temp);
		}
	}

	// ㄱ
	for (int y = 1; y <= n - 1; ++y)
	{
		for (int x = 1; x <= m - 2; ++x)
		{
			int temp = 0;
			temp += board[y][x];
			temp += board[y][x + 1];
			temp += board[y][x + 2];
			temp += board[y + 1][x + 2];

			res = max(res, temp);
		}
	}

	// ㄱ 뒤집은거
	for (int y = 1; y <= n - 1; ++y)
	{
		for (int x = 1; x <= m - 2; ++x)
		{
			int temp = 0;
			for (int k = 0; k < 3; ++k)
			{
				temp += board[y][x + k];
			}
			temp += board[y + 1][x];

			res = max(res, temp);
		}
	}

	// 긴 ㄱ
	for (int y = 1; y <= n - 2; ++y)
	{
		for (int x = 1; x <= m - 1; ++x)
		{
			int temp = 0;
			temp += board[y][x];
			temp += board[y][x + 1];
			temp += board[y + 1][x + 1];
			temp += board[y + 2][x + 1];

			res = max(res, temp);
		}
	}

	// 긴 ㄱ 대칭
	for (int y = 1; y <= n - 2; ++y)
	{
		for (int x = 1; x <= m - 1; ++x)
		{
			int temp = 0;
			temp += board[y][x];
			temp += board[y][x + 1];
			temp += board[y + 1][x];
			temp += board[y + 2][x];

			res = max(res, temp);
		}
	}

	// ㄹ 시리즈 1
	for (int y = 1; y <= n - 2; ++y)
	{
		for (int x = 1; x <= m - 1; ++x)
		{
			int temp = 0;
			temp += board[y][x];
			temp += board[y + 1][x];
			temp += board[y + 1][x + 1];
			temp += board[y + 2][x + 1];

			res = max(res, temp);
		}
	}

	// ㄹ 시리즈 1
	for (int y = 1; y <= n - 2; ++y)
	{
		for (int x = 1; x <= m - 1; ++x)
		{
			int temp = 0;
			temp += board[y][x + 1];
			temp += board[y + 1][x + 1];
			temp += board[y + 1][x];
			temp += board[y + 2][x];

			res = max(res, temp);
		}
	}

	// ㄹ 시리즈 2
	for (int y = 1; y <= n - 1; ++y)
	{
		for (int x = 1; x <= m - 2; ++x)
		{
			int temp = 0;
			temp += board[y + 1][x];
			temp += board[y + 1][x + 1];
			temp += board[y][x + 1];
			temp += board[y][x + 2];

			res = max(res, temp);
		}
	}

	// ㄹ 시리즈 2 대칭
	for (int y = 1; y <= n - 1; ++y)
	{
		for (int x = 1; x <= m - 2; ++x)
		{
			int temp = 0;
			temp += board[y][x];
			temp += board[y][x + 1];
			temp += board[y + 1][x + 1];
			temp += board[y + 1][x + 2];

			res = max(res, temp);
		}
	}

	// ㅏ
	for (int y = 1; y <= n - 2; ++y)
	{
		for (int x = 1; x <= m - 1; ++x)
		{
			int temp = 0;
			temp += board[y][x];
			temp += board[y + 1][x];
			temp += board[y + 1][x + 1];
			temp += board[y + 2][x];

			res = max(res, temp);
		}
	}

	// ㅜ
	for (int y = 1; y <= n - 1; ++y)
	{
		for (int x = 1; x <= m - 2; ++x)
		{
			int temp = 0;
			temp += board[y][x];
			temp += board[y][x + 1];
			temp += board[y][x + 2];
			temp += board[y + 1][x + 1];

			res = max(res, temp);
		}
	}

	// ㅓ
	for (int y = 1; y <= n - 2; ++y)
	{
		for (int x = 1; x <= m - 1; ++x)
		{
			int temp = 0;
			temp += board[y + 1][x];
			temp += board[y][x + 1];
			temp += board[y + 1][x + 1];
			temp += board[y + 2][x + 1];

			res = max(res, temp);
		}
	}

	// ㅗ
	for (int y = 1; y <= n - 1; ++y)
	{
		for (int x = 1; x <= m - 2; ++x)
		{
			int temp = 0;
			temp += board[y][x + 1];
			temp += board[y + 1][x];
			temp += board[y + 1][x + 1];
			temp += board[y + 1][x + 2];

			res = max(res, temp);
		}
	}

	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}