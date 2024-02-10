#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <tuple>

using namespace std;

void setting();
void solve();
void spreadDustAll();
void spreadDust(int y, int x);
void OnAirPurification();
void UpAirPurification();
void UnderAirPurification();
void printBoard();

// 1. 미세먼지가 확산된다.
// 
// 
// 2. 공기청정기가 작동한다.
// 공청기 위아래를 알아야함.

struct SmallDust
{
	int y, x;
	int smallDust;
};

int R, C, T; // 행, 열, 시간
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<int>> board;
vector<pair<int, int>> dusts;
vector<SmallDust> smallDusts;
pair<int, int> upAirPurification, underAirPurification;
void setting()
{
	cin >> R >> C >> T;
	board = vector<vector<int>>(R + 1, vector<int>(C + 1));

	bool flag = false;
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != -1)
				dusts.push_back({ i, j });
			if (board[i][j] == -1)
			{
				if (flag == false)
				{
					upAirPurification = { i, j };
					flag = true;
				}
				else
				{
					underAirPurification = { i , j };
				}
			}
		}
	}
}

void spreadDustAll()
{
	// 확산은 모든 칸에서 동시에 일어남.
	// 네 방향으로 확산.
	// 네 방향 중 공청있거나 칸없으면 확산 X
	// 확산의 양은 x/5, 소수점은 버림
	// 남은 미세먼지양은 (x - x/5 * 확산된 방향 수)

	for (int i = 0; i < dusts.size(); ++i)
	{
		spreadDust(dusts[i].first, dusts[i].second);
	}

	// TODO
	// smallDust들을 더해주기

	dusts.clear();
	for (int i = 0; i < smallDusts.size(); ++i)
	{
		board[smallDusts[i].y][smallDusts[i].x] += smallDusts[i].smallDust;
	}

	smallDusts.clear();
}

void spreadDust(int y, int x)
{
	// 확산은 모든 칸에서 동시에 일어남.
	// 네 방향으로 확산.
	// 네 방향 중 공청있거나 칸없으면 확산 X
	// 확산의 양은 x/5, 소수점은 버림
	// 남은 미세먼지양은 (x - x/5 * 확산된 방향 수)

	if (y == 3 && x == 7)
	{
		int a = 1;
	}
	if (y == 5 && x == 7)
	{
		int a = 1;
	}

	int cnt = 0;
	int smallDust = board[y][x] / 5;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 1 || nx < 1 || ny > R || nx > C)
			continue;
		if (board[ny][nx] == -1)
			continue;

		cnt++;

		// TODO
		// 다 퍼진 뒤 더해줘야함.
		smallDusts.push_back({ ny, nx, smallDust });
		//board[ny][nx] += smallDust;
	}

	board[y][x] = board[y][x] - smallDust * cnt;
}

void OnAirPurification()
{
	UpAirPurification();
	UnderAirPurification();

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (board[i][j] != 0 && board[i][j] != -1)
				dusts.push_back({ i, j });
		}
	}
}

void UpAirPurification()
{
	// 반시계 방향으로 순환함.

	// upAirPurification위치까지
	for (int i = upAirPurification.first - 1; i > 1; --i)
	{
		board[i][1] = board[i - 1][1];
	}

	// 왼쪽 벽까지
	for (int i = 1; i < C; ++i)
	{
		board[1][i] = board[1][i + 1];
	}

	// 위쪽 벽까지
	for (int i = 1; i < upAirPurification.first; ++i)
	{
		board[i][C] = board[i + 1][C];
	}

	// 오른쪽 벽까지 가기
	for (int i = C; i > 2; --i)
	{
		board[upAirPurification.first][i] = board[upAirPurification.first][i - 1];
	}
	board[upAirPurification.first][2] = 0;

}

void UnderAirPurification()
{
	// 시계 방향으로 순환함.

	// underAirPurification위치까지
	for (int i = underAirPurification.first + 1; i < R ; ++i)
	{
		board[i][1] = board[i + 1][1];
	}

	// 왼쪽 벽까지
	for (int i = 1; i < C; ++i)
	{
		board[R][i] = board[R][i + 1];
	}

	// 아래쪽 벽까지
	for (int i = R; i > underAirPurification.first; --i)
	{
		board[i][C] = board[i - 1][C];
	}

	// 오른쪽 벽까지 가기
	for (int i = C; i > 2; --i)
	{
		board[underAirPurification.first][i] = board[underAirPurification.first][i - 1];
	}
	board[underAirPurification.first][2] = 0;

}

void printBoard()
{
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}

	cout << '\n';
}

void solve()
{
	setting();

	for (int i = 0; i < T; ++i)
	{
		spreadDustAll();

		OnAirPurification();
	}

	int res = 0;

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (board[i][j] != -1)
			{
				res += board[i][j];
			}
		}
	}

	cout << res;
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