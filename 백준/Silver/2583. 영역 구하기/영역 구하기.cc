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

int n, m, k;
vector<vector<int>> board;
vector<vector<int>> visited;
vector<int> ans;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int area = 0;
void dfs(int y, int x)
{
	area++;
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;
		if (visited[ny][nx])
			continue;
		if (board[ny][nx] != 0)
			continue;

		dfs(ny, nx);
	}
}

void solve()
{
	cin >> n >> m >> k;
	board = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<int>>(n, vector<int>(m));

	int a, b, c, d;
	for (int i = 0; i < k; ++i)
	{
		cin >> a >> b >> c >> d;
		for (int j = b; j < d; ++j)
		{
			for (int k = a; k < c; ++k)
			{
				board[j][k] = 1;
			}
		}
	}

	int cnt = 0;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (board[y][x] == 0 && visited[y][x] == 0)
			{
				cnt++;
				area = 0;
				dfs(y, x);
				ans.push_back(area);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << cnt << '\n';
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
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