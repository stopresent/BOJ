#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

char board[51][51];
int M, N;
int minCount = 80;

// 수가 작다
// 완전 탐색이 어울릴듯하다
// 이상적인 보드와 비교 -> 이상적인 보드가 되기위한 변경 개수 확인

void CheckMincount(int firstY, int firstX)
{
	int changeCountInFirstBlack = 0;

	// 이상적인 보드가 BlackFirst라고 가정.
	for (int y = 1 + firstY; y <= 8 + firstY; y++)
	{
		for (int x = 1 + firstX; x <= 8 + firstX; x++)
		{
			int xDiv2 = x % 2;
			int yDiv2 = y % 2;
			if ((xDiv2 == 0 && yDiv2 == 0) || (xDiv2 == 1 && yDiv2 == 1))
			{
				board[y][x] != 'B' ? changeCountInFirstBlack++ : changeCountInFirstBlack = changeCountInFirstBlack;
			}
			else if ((xDiv2 == 1 && yDiv2 == 0) || (xDiv2 == 0 && yDiv2 == 1))
			{
				board[y][x] != 'W' ? changeCountInFirstBlack++ : changeCountInFirstBlack = changeCountInFirstBlack;
			}
		}
	}

	if (changeCountInFirstBlack < minCount) minCount = changeCountInFirstBlack;

	int changeCountInFirstWhite = 0;

	// 이상적인 보드가 WhiteFirst라고 가정.
	for (int y = 1 + firstY; y <= 8 + firstY; y++)
	{
		for (int x = 1 + firstX; x <= 8 + firstX; x++)
		{
			int xDiv2 = x % 2;
			int yDiv2 = y % 2;
			if ((xDiv2 == 0 && yDiv2 == 0) || (xDiv2 == 1 && yDiv2 == 1))
			{
				board[y][x] != 'W' ? changeCountInFirstWhite++ : changeCountInFirstWhite = changeCountInFirstWhite;
			}
			else if ((xDiv2 == 1 && yDiv2 == 0) || (xDiv2 == 0 && yDiv2 == 1))
			{
				board[y][x] != 'B' ? changeCountInFirstWhite++ : changeCountInFirstWhite = changeCountInFirstWhite;
			}
		}
	}

	if (changeCountInFirstWhite < minCount) minCount = changeCountInFirstWhite;

}

int main()
{
	cin >> M >> N;

	char boardColor;

	for (int y = 1; y <= M; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> boardColor;
			board[y][x] = boardColor;
		}
	}

	for (int initY = 0; initY <= M - 7; initY++)
	{
		for (int initX = 0; initX <= N - 7; initX++)
		{
			CheckMincount(initY, initX);
		}
	}

	cout << minCount;
}
