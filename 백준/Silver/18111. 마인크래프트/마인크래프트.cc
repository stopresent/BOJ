#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, b, minN = 256, maxN = 0, totalTime = 123456789, height;
vector<vector<int>> board;

void setting()
{
	cin >> n >> m >> b;
	board = vector<vector<int>>(n, vector<int>(m));

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			cin >> board[y][x];
			if (board[y][x] > maxN)
				maxN = board[y][x];
			if (board[y][x] < minN)
				minN = board[y][x];
		}
	}
}

int check(int i)
{
	int res = 0, block = b;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (board[y][x] <= i)
			{
				res = res + i - board[y][x];
				block = block - (i - board[y][x]);
			}
			else
			{
				res = res + (board[y][x] - i) * 2;
				block = block + board[y][x] - i;
			}
		}
	}

	if (block < 0)
	{
		res = 123456789;
		return res;
	}
	return res;
}

void solve()
{
	int i = maxN;
	
	while (i != minN - 1)
	{
		int temp = check(i);
		if (temp < totalTime)
		{
			totalTime = temp;
			height = i;
		}

		i--;
	}

	cout << totalTime << " " << height << '\n';
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	setting();
	solve();

	return 0;
}