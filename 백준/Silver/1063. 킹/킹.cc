#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;


/*

R : 한 칸 오른쪽으로
L : 한 칸 왼쪽으로
B : 한 칸 아래로
T : 한 칸 위로
RT : 오른쪽 위 대각선으로
LT : 왼쪽 위 대각선으로
RB : 오른쪽 아래 대각선으로
LB : 왼쪽 아래 대각선으로

*/

// 위의 순서대로 만듦.
int n;
int board[10][10];
int dy[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
map<string, int> m =
{
	{"R", 0},
	{"L", 1},
	{"B", 2},
	{"T", 3},
	{"RT", 4},
	{"LT", 5},
	{"RB", 6},
	{"LB", 7},
};
void solve()
{
	string kingPos, piecePos;
	pair<int, int> king, piece;
	cin >> kingPos >> piecePos >> n;

	int y = abs(8 - (kingPos[1] - '1' + 1)) + 1;
	int x = kingPos[0] - 'A' + 1;
	king = { y , x };

	y = abs(8 - (piecePos[1] - '1' + 1)) + 1;
	x = piecePos[0] - 'A' + 1;
	piece = { y , x };

	// n번 이동
	string moveStr;
	for (int i = 0; i < n; ++i)
	{
		cin >> moveStr;
		int ny = king.first + dy[m[moveStr]];
		int nx = king.second + dx[m[moveStr]];

		if (ny < 1 || nx < 1 || ny > 8 || nx > 8)
			continue;
		if (ny == piece. first && nx == piece.second)
		{
			int pny = piece.first + dy[m[moveStr]];
			int pnx = piece.second + dx[m[moveStr]];

			if (pny < 1 || pnx < 1 || pny > 8 || pnx > 8)
				continue;
			piece.first = pny;
			piece.second = pnx;
		}

		king.first = ny;
		king.second = nx;
	}

	// 마지막 위치 출력
	char kingY = abs('8' - king.first) + 1;
	char kingX = king.second + 'A' - 1;
	cout << kingX << kingY << '\n';

	char pieceY = abs('8' - piece.first) + 1;
	char pieceX = piece.second + 'A' - 1;
	cout << pieceX << pieceY << '\n';
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