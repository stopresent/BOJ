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

vector<vector<int>> board;
int N, M, res = 0;

struct Pos
{
	bool operator==(Pos& other)
	{
		return y == other.y && x == other.x;
	}

	bool operator!=(Pos& other)
	{
		return !(*this == other);
	}

	bool operator<(const Pos& other) const
	{
		if (y != other.y)
			return y < other.y;
		return x < other.x;
	}

	Pos operator+(Pos& other)
	{
		Pos ret;
		ret.y = y + other.y;
		ret.x = x + other.x;
		return ret;
	}

	Pos& operator+=(Pos& other)
	{
		y += other.y;
		x += other.x;
		return *this;
	}

	int y;
	int x;
};

Pos front[4] =
{
	Pos { -1, 0},	// UP
	Pos { 0, -1},	// LEFT
	Pos {1, 0},		// DOWN
	Pos {0, 1},		// RIGHT
};

queue<Pos> q;

bool IsInside(Pos pos)
{
	if (pos.y < 0 || pos.x < 0)
		return false;
	if (pos.y > N - 1 || pos.x > M - 1)
		return false;

	return true;
}

// 1: 익은 토마토
// 0 : 덜 익은 토마토
// -1 : 빈 공간
void setting()
{
	cin >> M >> N;
	board = vector<vector<int>>(N, vector<int>(M));
	string str;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> board[y][x];
			if (board[y][x] == 1)
			{
				q.push({ y, x });
			}
		}
	}
}

void bfs()
{
	while (!q.empty()) 
	{
		// 큐의 현재 원소(익은 토마토(1))를 꺼내기
		Pos pos = q.front();
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		// 해당 위치의 주변을 확인
		for (int dir = 0; dir < 4; dir++) 
		{
			Pos nextPos = pos + front[dir];

			// 지도를 벗어나지 않고, 익지않은 토마토(0)라면
			if (IsInside(nextPos) == true && board[nextPos.y][nextPos.x] == 0) 
			{
				board[nextPos.y][nextPos.x] = board[pos.y][pos.x] + 1;
				q.push(nextPos);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	setting();
	bfs();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 익지않은 토마토(0)가 존재할 경우
			if (board[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			// 토마토는 다 익었는데, 얼마만에 익었는지?
			if (res < board[i][j])
			{
				res = board[i][j];
			}
		}
	}

	cout << res - 1;

	return 0;
}