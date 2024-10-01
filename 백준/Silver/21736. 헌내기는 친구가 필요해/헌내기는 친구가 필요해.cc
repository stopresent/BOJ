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
#include <queue>

using namespace std;

int n, m, ret = 0;
vector<vector<char>> board;
vector<vector<int>> visited;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
pair<int, int> p;

void solve()
{
	cin >> n >> m;
	board = vector<vector<char>> (n, vector<char>(m));
	visited = vector<vector<int>> (n, vector<int>(m));

	for (int y = 0; y < n; ++y)
	{
		string s;
		cin >> s;
		for (int x = 0; x < m; ++x)
		{
			board[y][x] = s[x];
			if (board[y][x] == 'I')
			{
				p = { y, x };
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(p);
	visited[p.first][p.second] = 1;
	while (q.empty() == false)
	{
		pair<int, int> here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] == 1)
				continue;
			if (board[ny][nx] == 'X')
				continue;
			if (board[ny][nx] == 'P')
				ret++;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	ret == 0 ? cout << "TT" : cout << ret;
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