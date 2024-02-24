#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void setting();
void printBoard();
void solve();

int n, res = 0, cnt = 0;
int board[11][11];
vector<pair<int, int>> arr;
vector<pair<int, int>> bishopPos;
void setting()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1 && (i + j) % 2 == 0) // 놓을 수 있는 비숍 자리들.
				arr.push_back({ i, j });
		}
	}
}

void printBoard()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void bishop(int cnt, int L)
{
	if (cnt > res)
		res = cnt;
	if (L == arr.size())
		return;

	bool flag = true;
	for (int i = 0; i < bishopPos.size(); ++i)
	{
		if (abs(arr[L].first - bishopPos[i].first) == abs(arr[L].second - bishopPos[i].second))
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		bishopPos.push_back({ arr[L].first, arr[L].second });
		bishop(cnt + 1, L + 1);
		bishopPos.pop_back();
	}
	bishop(cnt, L + 1);

	return;
}

void solve()
{
	setting();

	int ans = 0;
	bishop(0, 0);
	ans += res;
	res = 0;
	arr.clear();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (board[i][j] == 1 && (i + j) % 2 == 1)
				arr.push_back({ i, j });
		}
	}
	bishop(0, 0);
	ans += res;
	res = 0;
	arr.clear();

	cout << ans;
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