#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

void solve()
{
	int res = 0;
	//vector<vector<char>> board(8, vector<char>(8));
	char board[10][10];

	for (int i = 0; i < 8; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = i % 2; j < 8; j += 2)
		{
			if (board[i][j] == 'F')
				res++;
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