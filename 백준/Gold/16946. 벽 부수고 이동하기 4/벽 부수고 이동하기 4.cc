#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

// 시간초과가 뜨지 않게 변환

int n, m, zeroAreaIdx = 0;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int board[1111][1111];
int zeroArea[1111][1111];
int visited[1111][1111];
vector<int> zeroAreaZeroCount;
int BFS(int y, int x)
{
	int res = 0;
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = 1;
	zeroArea[y][x] = zeroAreaIdx;

	pair<int, int> here;
	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		res++;

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > m)
				continue;
			if (visited[ny][nx] == 1)
				continue;
			if (board[ny][nx] == 1)
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
			zeroArea[ny][nx] = zeroAreaIdx;
		}
	}

	zeroAreaZeroCount.push_back(res);
	return res % 10;
}

void solve()
{
	// 입력값 받기
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; ++j)
		{
			board[i][j] = str[j - 1] - '0';
		}
	}

	::memset(zeroArea, -1, sizeof(zeroArea));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (board[i][j] == 0 && visited[i][j] == 0)
			{
				BFS(i, j);
				zeroAreaIdx++;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (board[i][j] == 1)
			{
				vector<int> cache(4, -1);
				for (int k = 0; k < 4; ++k)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					cache[k] = zeroArea[ny][nx];
				}
				sort(cache.begin(), cache.end());
				cache.push_back(-1);
				int res = 0;
				for (int k = 0; k < 4; ++k)
				{
					if (cache[k] == -1)
						continue;
					if (cache[k] == cache[k + 1])
						continue;
					res += zeroAreaZeroCount[cache[k]];
				}
				::cout << (res + 1) % 10;
			}
			else
				::cout << 0;
		}
		::cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	::cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}