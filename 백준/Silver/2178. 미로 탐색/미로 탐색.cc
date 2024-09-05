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

int n, m;
vector<vector<int>> board;
vector<vector<int>> visited;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void solve()
{
	cin >> n >> m;
	board = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<int>>(n, vector<int>(m));
	string temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		for (int j = 0; j < temp.size(); ++j)
		{
			board[i][j] = temp[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	q.push({0, 0});
	visited[0][0] = 1;
	while (q.size())
	{
		pair<int, int> here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (visited[ny][nx])
				continue;
			if (board[ny][nx] == 0)
				continue;
			visited[ny][nx] = visited[here.first][here.second] + 1;
			q.push({ ny, nx });
		}
	}

	cout << visited[n - 1][m - 1];
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