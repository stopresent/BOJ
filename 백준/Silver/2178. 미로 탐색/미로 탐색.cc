#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<bool>> discovered;

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
	Pos { -1, 0}, // UP
	Pos { 0, -1}, // LEFT
	Pos { 1, 0},  // DOWN
	Pos { 0, 1},  // RIGHT
};

// 1은 지나갈 수 있다.
// 0은 벽
void setting()
{
	cin >> n >> m;
	board = vector<vector<int>>(n, vector<int>(m));
	discovered = vector<vector<bool>>(n, vector<bool>(m, false));
	string str;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			board[i][j] = str[j] - '0';
		}
	}
}

bool CanGo(Pos pos)
{
	if (pos.y < 0 || pos.x < 0)
		return false;
	if (pos.y > n - 1 || pos.x > m - 1)
		return false;
	return board[pos.y][pos.x] == 1;
}

void Bfs(Pos pos)
{
	map<Pos, Pos> parent;

	int res = 1;
	Pos dest = { n - 1, m - 1 };
	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		if (pos == dest)
			break;

		for (int dir = 0; dir < 4; ++dir)
		{
			Pos nextPos = pos + front[dir];
			if (CanGo(nextPos) == false)
				continue;
			if (discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos] = pos;
		}
	}

	while (true)
	{
		if (pos == parent[pos])
			break;

		pos = parent[pos];
		res++;
	}

	cout << res;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	Pos pos = { 0, 0 };
	setting();
	Bfs(pos);

	return 0;
}