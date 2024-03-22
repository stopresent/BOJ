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

int n, m, d, s, ans = 0;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<pair<int, int>> load;

void print_board()
{
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void move()
{
	// 맞는데 왜 틀린거야 맞잖아
	for (int i = 0; i < load.size(); ++i)
	{
		if (board[load[i].first][load[i].second] == 0)
		{
			for (int j = i + 1; j < load.size(); ++j)
			{
				if (board[load[j].first][load[j].second] != 0)
				{
					swap(board[load[i].first][load[i].second], board[load[j].first][load[j].second]);
					break;
				}
			}
		}
	}
}

bool boom()
{
	// 폭발하면 움직여야함
	bool flag = false;
	for (int i = 0; i < load.size(); ++i)
	{
		int value = board[load[i].first][load[i].second];
		int cnt = 1;
		for (int j = i + 1; j < load.size(); ++j)
		{
			if (board[load[j].first][load[j].second] != value)
			{
				if (cnt < 4)
					break;

				for (int k = i; k < j; ++k)
				{
					board[load[k].first][load[k].second] = 0;
				}
				ans += value * cnt;
				flag = true;
				i = j - 1;
				cnt = 1;
				break;
			}

			if (board[load[j].first][load[j].second] == value)
				cnt++;
		}
	}

	return flag;
}

void blizard()
{
	pair<int, int> pos = { (n + 1) / 2, (n + 1) / 2 };
	for (int i = 1; i <= s; ++i)
	{
		int ny = pos.first + dy[d - 1] * i;
		int nx = pos.second + dx[d - 1] * i;

		board[ny][nx] = 0;
	}
}

bool can_go(int y, int x)
{
	if (y < 1 || x < 1 || y > n || x > n)
		return false;
	if (visited[y][x] == true)
		return false;
	return true;
}

void change()
{
	vector<vector<int>> cboard(n + 1, vector<int>(n + 1));
	int idx = 0;
	for (int i = 0; i < load.size();)
	{	
		if (idx >= n * n - 1)
			break;
		int cnt = 1;
		int value = board[load[i].first][load[i].second];
		if (value == 0)
			break;

		for (int j = i + 1; j < load.size(); ++j)
		{
			if (board[load[j].first][load[j].second] != value)
			{
				int dist = j - i;
				cboard[load[idx].first][load[idx].second] = dist;
				idx++;
				cboard[load[idx].first][load[idx].second] = value;
				idx++;
				i = j;

				break;
			}

			//if (board[load[j].first][load[j].second] == value)
			//{
			//	cnt++;
			//}
		}
	}

	for (int i = 0; i < load.size(); ++i)
	{
		board[load[i].first][load[i].second] = cboard[load[i].first][load[i].second];
	}
}

void solve()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 1, vector<int>(n + 1));
	visited = vector<vector<bool>>(n + 1, vector<bool>(n + 1));

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			cin >> board[y][x];
		}
	}

	// load 채워주기
	pair<int, int> pos = { 1, 1 };
	int dy2[] = { 0, 1, 0, -1 };
	int dx2[] = { 1, 0, -1, 0 };
	int dir = 0;
	load.push_back(pos);
	visited[pos.first][pos.second] = true;
	while (true)
	{
		int ny = pos.first + dy2[dir];
		int nx = pos.second + dx2[dir];
		if (ny == (n + 1) / 2 && nx == (n + 1) / 2)
			break;

		if (can_go(ny, nx))
		{
			pos.first = ny;
			pos.second = nx;
			load.push_back({ pos.first, pos.second });
			visited[pos.first][pos.second] = true;
		}
		else
		{
			dir = (dir + 1) % 4;
		}
	}

	reverse(load.begin(), load.end());

	//for (int i = 0; i < load.size(); ++i)
	//{
	//	cout << load[i].first << " " << load[i].second << endl;
	//}

	for (int i = 1; i <= m; ++i)
	{
		cin >> d >> s;
		blizard();
		//print_board();
		move();
		//print_board();

		while (true)
		{
			if (boom())
			{
				//print_board();
				move();
				//print_board();
			}
			else
				break;
		}

		//print_board();
		change();
		//print_board();
	}

	cout << ans;
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