#include <iostream>
using namespace std;
#include <iomanip>

/*

7. 달팽이 문제

사용자의 입력 : 1 ~ 100 사이의 정수

입력 예시
5

출력 예시
01 02 03 04 05
16 17 18 19 06
15 24 25 20 07
14 23 22 21 08
13 12 11 10 09

*/

const int MAX = 100;
int board[MAX][MAX] = {};
int N;


void PrintBoard()
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		cout << endl;
	}
}

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};

bool CanGo(int y, int x)
{
	if (y >= N || y < 0)
		return false;
	if (x >= N || x < 0)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;
}

void SetBoard()
{
	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { 1, 0, -1, 0 };

	int dir = RIGHT;
	int num = 1;
	int y = 0, x = 0;

	while (true)
	{
		board[y][x] = num;

		if (num == N * N) break;

		int nextY;
		int nextX;

		nextY = y + dy[dir];
		nextX = x + dx[dir];

		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			dir = (dir + 1) % 4;
		}

	}
}

int main()
{
	cin >> N;

	SetBoard();

	PrintBoard();

	return 0;
}