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

// 먼저 토네이도 모양으로 움직임을 구현해야한다.
int n;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { -1, 0, 1, 0 };
vector<vector<int>> board;

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
	pair<int, int> pos = { n / 2 + 1, n / 2 + 1};

	int idx = 1, dir = 0;
	int total = 0, ten = 0, seven = 0, five = 0, two = 0, one = 0, alpa = 0, ny = 0, nx = 0;
	while (true)
	{
		if (pos.first == 1 && pos.second == 1)
			break;

		for (int i = 0; i < idx; ++i)
		{
			if (pos.first == 1 && pos.second == 1)
				break;

			//print_board();

			int nextY = pos.first + dy[dir];
			pos.first = nextY;
			int nextX = pos.second + dx[dir];
			pos.second = nextX;

			// 모래 분배하기
			total = board[pos.first][pos.second];
			ten = total * 10 / 100;
			seven = total * 7 / 100;
			five = total * 5 / 100;
			two = total * 2 / 100;
			one = total * 1 / 100;
			alpa = total - (2 * ten + 2 * seven + 1 * five + 2 * two + 2 * one);
			board[pos.first][pos.second] = 0;

			// 알파 더해주기
			ny = pos.first + dy[dir];
			nx = pos.second + dx[dir];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += alpa;
			}

			// 10퍼
			ny = pos.first + dy[dir];
			ny = ny + dy[(dir - 1 + 4) % 4];
			nx = pos.second + dx[dir];
			nx = nx + dx[(dir - 1 + 4) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += ten;
			}
			ny = pos.first + dy[dir];
			ny = ny + dy[(dir + 1) % 4];
			nx = pos.second + dx[dir];
			nx = nx + dx[(dir + 1) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += ten;
			}

			// 7퍼
			ny = pos.first + dy[(dir - 1 + 4) % 4];
			nx = pos.second + dx[(dir - 1 + 4) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += seven;
			}
			ny = pos.first + dy[(dir + 1) % 4];
			nx = pos.second + dx[(dir + 1) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += seven;
			}

			// 5퍼
			ny = pos.first + dy[dir] * 2;
			nx = pos.second + dx[dir] * 2;
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += five;
			}

			// 2퍼
			ny = pos.first + dy[(dir - 1 + 4) % 4] * 2;
			nx = pos.second + dx[(dir - 1 + 4) % 4] * 2;
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += two;
			}
			ny = pos.first + dy[(dir + 1) % 4] * 2;
			nx = pos.second + dx[(dir + 1) % 4] * 2;
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += two;
			}

			// 1퍼
			ny = pos.first + dy[(dir + 2) % 4];
			nx = pos.second + dx[(dir + 2) % 4];
			ny = ny + dy[(dir - 1 + 4) % 4];
			nx = nx + dx[(dir - 1 + 4) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += one;
			}
			ny = pos.first + dy[(dir + 2) % 4];
			nx = pos.second + dx[(dir + 2) % 4];
			ny = ny + dy[(dir + 1) % 4];
			nx = nx + dx[(dir + 1) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += one;
			}
		}

		dir = (dir + 1) % 4;

		for (int i = 0; i < idx; ++i)
		{
			if (pos.first == 1 && pos.second == 1)
				break;

			//print_board();

			int nextY = pos.first + dy[dir];
			pos.first = nextY;
			int nextX = pos.second + dx[dir];
			pos.second = nextX;

			total = board[pos.first][pos.second];
			ten = total * 10 / 100;
			seven = total * 7 / 100;
			five = total * 5 / 100;
			two = total * 2 / 100;
			one = total * 1 / 100;
			alpa = total - (2 * ten + 2 * seven + 1 * five + 2 * two + 2 * one);
			board[pos.first][pos.second] = 0;

			// 알파 더해주기
			ny = pos.first + dy[dir];
			nx = pos.second + dx[dir];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += alpa;
			}

			// 10퍼
			ny = pos.first + dy[dir];
			ny = ny + dy[(dir - 1 + 4) % 4];
			nx = pos.second + dx[dir];
			nx = nx + dx[(dir - 1 + 4) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += ten;
			}
			ny = pos.first + dy[dir];
			ny = ny + dy[(dir + 1) % 4];
			nx = pos.second + dx[dir];
			nx = nx + dx[(dir + 1) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += ten;
			}

			// 7퍼
			ny = pos.first + dy[(dir - 1 + 4) % 4];
			nx = pos.second + dx[(dir - 1 + 4) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += seven;
			}
			ny = pos.first + dy[(dir + 1) % 4];
			nx = pos.second + dx[(dir + 1) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += seven;
			}

			// 5퍼
			ny = pos.first + dy[dir] * 2;
			nx = pos.second + dx[dir] * 2;
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += five;
			}

			// 2퍼
			ny = pos.first + dy[(dir - 1 + 4) % 4] * 2;
			nx = pos.second + dx[(dir - 1 + 4) % 4] * 2;
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += two;
			}
			ny = pos.first + dy[(dir + 1) % 4] * 2;
			nx = pos.second + dx[(dir + 1) % 4] * 2;
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += two;
			}

			// 1퍼
			ny = pos.first + dy[(dir + 2) % 4];
			nx = pos.second + dx[(dir + 2) % 4];
			ny = ny + dy[(dir - 1) % 4];
			nx = nx + dx[(dir - 1) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += one;
			}
			ny = pos.first + dy[(dir + 2) % 4];
			nx = pos.second + dx[(dir + 2) % 4];
			ny = ny + dy[(dir + 1) % 4];
			nx = nx + dx[(dir + 1) % 4];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n)
			{
				board[ny][nx] += one;
			}
		}
		
		idx++;
		dir = (dir + 1) % 4;

	}
}

void solve()
{
	cin >> n;
	board = vector<vector<int>>(n + 1, vector<int>(n + 1));
	int init_total = 0;
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			cin >> board[y][x];
			init_total += board[y][x];
		}
	}

	move();

	int cur_total = 0, ret = 0;
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			cur_total += board[y][x];
		}
	}

	ret = init_total - cur_total;
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