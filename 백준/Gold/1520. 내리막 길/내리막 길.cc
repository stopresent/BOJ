#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, res = 0;
vector<vector<int>> board;
vector<vector<int>> dp;
void setting()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 1, vector<int>(m + 1));
	dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= m; ++x)
		{
			cin >> board[y][x];
		}
	}
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int DFS(pair<int, int> pos)
{
	if (pos.first == n && pos.second == m)
		return 1;
	if (dp[pos.first][pos.second] != -1)
		return dp[pos.first][pos.second];

	dp[pos.first][pos.second] = 0;
	for (int i = 0; i < 4; ++i)
	{
		int ny = pos.first + dy[i];
		int nx = pos.second + dx[i];

		if (ny < 1 || nx < 1 || ny > n || nx > m)
			continue;
		if (board[ny][nx] >= board[pos.first][pos.second])
			continue;

		dp[pos.first][pos.second] += DFS({ ny, nx });
	}

	return dp[pos.first][pos.second];
}

void solve()
{
	res = DFS({ 1, 1 });

	cout << res;
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