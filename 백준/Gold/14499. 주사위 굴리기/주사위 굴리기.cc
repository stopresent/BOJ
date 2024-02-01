#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dice
{
	int front = 0, back = 0;
	int east = 0, west = 0, north = 0, south = 0;
};

int n, m, x, y, k;
// x, y : 주사위가 놓인곳
// k : 명령의 수
vector<vector<int>> board;
int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };
// 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
int dir = 0;

// 현재 위치
Dice dice;
pair<int, int> pos;

// 주사위
//   2
// 4 1 3
//   5
//   6
// 주사위 구조체가 필요하나?

void solve()
{
	cin >> n >> m >> x >> y >> k;
	board = vector<vector<int>>(n + 1, vector<int>(m + 1));
	pos = { x + 1, y + 1 };

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> board[i][j];
		}
	}

	// k번 명령하기
	for (int i = 1; i <= k; ++i)
	{
		cin >> dir;

		// dir 방향으로 굴린다.
		int ny = pos.first + dy[dir - 1];
		int nx = pos.second + dx[dir - 1];
		if (ny < 1 || nx < 1 || ny > n || nx > m)
			continue;
		pos = { ny, nx };

		int curFront = dice.front;
		switch (dir)
		{
		case 1: // 동쪽으로 굴리기
			curFront = dice.front;
			dice.front = dice.west;
			dice.west = dice.back;
			dice.back = dice.east;
			dice.east = curFront;
			break;
		case 2: // 서쪽으로 굴리기
			curFront = dice.front;
			dice.front = dice.east;
			dice.east = dice.back;
			dice.back = dice.west;
			dice.west = curFront;
			break;
		case 3: // 북쪽으로 굴리기
			curFront = dice.front;
			dice.front = dice.south;
			dice.south = dice.back;
			dice.back = dice.north;
			dice.north = curFront;
			break;
		case 4: // 남쪽으로 굴리기
			curFront = dice.front;
			dice.front = dice.north;
			dice.north = dice.back;
			dice.back = dice.south;
			dice.south = curFront;
			break;
		}

		// 주사위 바닥과 칸 숫자 비교
		// 숫자 복사 과정
		if (board[pos.first][pos.second] == 0)
		{
			board[pos.first][pos.second] = dice.back;
		}
		else
		{
			dice.back = board[pos.first][pos.second];
			board[pos.first][pos.second] = 0;
		}

		// 주사위 윗면 수 출력
		cout << dice.front << '\n';
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