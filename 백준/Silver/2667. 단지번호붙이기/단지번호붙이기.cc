#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, cnt = 0;
int board[27][27];
int discovered[27][27];
vector<int> res;
void setting()
{
	cin >> n;
	res = vector<int>(n * n);

	string str;
	for (int y = 1; y <= n; ++y)
	{
		cin >> str;
		for (int x = 1; x <= n; ++x)
		{
			board[y][x] = str[x - 1] - '0';
		}
	}
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void BFS(int y, int x)
{
	int ny, nx;
	queue<pair<int, int>> q;
	q.push({ y, x });
	discovered[y][x] = 1;

	while (q.empty() == false)
	{
		pair<int, int> here = q.front();
		q.pop();
		//cout << cnt << "단지 : " << here.first << " : " << here.second << endl;
		res[cnt]++;

		for (int i = 0; i < 4; ++i)
		{
			ny = here.first + dy[i];
			nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > n)
				continue;
			if (board[ny][nx] == 0)
				continue;
			if (discovered[ny][nx] == 1)
				continue;

			discovered[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

void solve()
{
	setting();

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			if (board[y][x] == 1 && discovered[y][x] == 0)
			{
				BFS(y, x);
				//cout << endl;
				cnt++;
			}
		}
	}

	sort(res.begin(), res.begin() + cnt);

	cout << cnt << '\n';

	for (int i = 0; i < cnt; ++i)
	{
		cout << res[i] << '\n';
	}
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