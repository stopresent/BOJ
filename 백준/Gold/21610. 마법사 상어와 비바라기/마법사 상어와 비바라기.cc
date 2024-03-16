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

int n, m, d, s;
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int diaY[] = { -1, -1, 1, 1 };
int diaX[] = { -1, 1, 1, -1 };
vector<vector<int>> board;
vector<pair<int, int>> clouds;
vector<pair<int, int>> remove_clouds;

void move_cloud()
{
	for (int i = 0; i < clouds.size(); ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			int ny = (clouds[i].first + dy[d - 1] + n) % n;
			if (ny == 0)
				ny = n;
			clouds[i].first = ny;
			int nx = (clouds[i].second + dx[d - 1] + n) % n;
			if (nx == 0)
				nx = n;
			clouds[i].second = nx;
		}
	}
}

void add_water()
{
	for (int i = 0; i < clouds.size(); ++i)
	{
		board[clouds[i].first][clouds[i].second]++;
	}
}

void remove_cloud()
{
	remove_clouds.clear();

	for (int i = 0; i < clouds.size(); ++i)
	{
		remove_clouds.push_back({ clouds[i].first, clouds[i].second });
	}

	clouds.clear();
}

void clone_water()
{
	for (int i = 0; i < remove_clouds.size(); ++i)
	{
		int cnt = 0;
		for (int j = 0; j < 4; ++j)
		{
			int ny = remove_clouds[i].first + diaY[j];
			int nx = remove_clouds[i].second + diaX[j];

			if (ny < 1 || nx < 1 || ny > n || nx > n)
				continue;
			if (board[ny][nx] == 0)
				continue;

			cnt++;
		}

		board[remove_clouds[i].first][remove_clouds[i].second] += cnt;
	}
}

void create_cloud()
{
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			if (board[y][x] < 2)
				continue;
			// 사라졌던 구름자리에 구름이 생기면 안됨.
			bool flag = true;
			for (int i = 0; i < remove_clouds.size(); ++i)
			{
				if (y == remove_clouds[i].first && x == remove_clouds[i].second)
				{
					flag = false;
					break;
				}
			}

			if (flag == true)
			{
				board[y][x] -= 2;
				clouds.push_back({ y, x });
			}
		}
	}

	remove_clouds.clear();
}

void solve()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 1, vector<int>(n + 1));

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			cin >> board[y][x];
		}
	}

	// 비바라기 마법 시전
	clouds.push_back({ n, 1 });
	clouds.push_back({ n, 2 });
	clouds.push_back({ n - 1, 1 });
	clouds.push_back({ n - 1, 2 });

	for (int i = 1; i <= m; ++i)
	{
		cin >> d >> s;

		// 구름이 이동한다.
		move_cloud();

		// 물이 1 증가한다. 
		add_water();

		// 구름이 사라진다.
		remove_cloud();

		// 물 복사 마법이 시전된다.
		clone_water();

		// 구름이 생성되고 물이 양이 2 줄어든다.
		create_cloud();
	}

	int ret = 0;

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			ret += board[y][x];
		}
	}

	cout << ret;
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