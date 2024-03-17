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

struct FireBall
{
	int r, c, m, s, d;
};

int N, M, K, r, c, m, s, d;
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<FireBall> board[51][51];

void move_fireball()
{
	vector<FireBall> cBoard[51][51];
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			if (board[y][x].size() == 0)
				continue;

			// 이거 복사 안되면 수동으로 해줘야됨.
			vector<FireBall> temp = board[y][x];
			board[y][x].clear();

			for (int i = 0; i < temp.size(); ++i)
			{
				int ny = (temp[i].r + dy[temp[i].d] * temp[i].s) % N;
				if (ny <= 0)
					ny += N;
				temp[i].r = ny;
				int nx = (temp[i].c + dx[temp[i].d] * temp[i].s) % N;
				if (nx <= 0)
					nx += N;
				temp[i].c = nx;

			}

			for (int i = 0; i < temp.size(); ++i)
			{
				cBoard[temp[i].r][temp[i].c].push_back(temp[i]);
			}
		}
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			for (int i = 0; i < cBoard[y][x].size(); ++i)
			{
				//cout << "cBoard에서 board로 복사" << endl;
				//cout << cBoard[y][x][i].r << " " << cBoard[y][x][i].c << " " << cBoard[y][x][i].m << " " << cBoard[y][x][i].s << " " << cBoard[y][x][i].d << endl;
				board[y][x].push_back(cBoard[y][x][i]);
			}
		}
	}
}

void merge_div_fireball()
{
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			if (board[y][x].size() < 2)
				continue;

			vector<FireBall> temp = board[y][x];
			board[y][x].clear();
			int mSum = 0, sSum = 0, cnt = temp.size();
			int evenCnt = 0, oddCnt = 0;
			for (int i = 0; i < temp.size(); ++i)
			{
				if (temp[i].d % 2 == 0)
					evenCnt++;
				else
					oddCnt++;
				mSum += temp[i].m;
				sSum += temp[i].s;
			}

			// 그냥 소멸
			int mass = mSum / 5;
			if (mass == 0)
				continue;

			int speed = sSum / cnt;
			if (evenCnt == 0 || oddCnt == 0)
			{
				board[y][x].push_back({ y, x, mass, speed, 0 });
				board[y][x].push_back({ y, x, mass, speed, 2 });
				board[y][x].push_back({ y, x, mass, speed, 4 });
				board[y][x].push_back({ y, x, mass, speed, 6 });
			}
			else
			{
				board[y][x].push_back({ y, x, mass, speed, 1 });
				board[y][x].push_back({ y, x, mass, speed, 3 });
				board[y][x].push_back({ y, x, mass, speed, 5 });
				board[y][x].push_back({ y, x, mass, speed, 7 });
			}
		}
	}
}

void solve()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= M; ++i)
	{
		cin >> r >> c >> m >> s >> d;
		board[r][c].push_back({ r, c, m, s, d });
	}

	for (int i = 1; i <= K; ++i)
	{
		move_fireball();
		merge_div_fireball();
	}

	int ret = 0;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			for (int i = 0; i < board[y][x].size(); ++i)
			{
				ret += board[y][x][i].m;
			}
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