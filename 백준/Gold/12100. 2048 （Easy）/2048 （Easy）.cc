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

int n;
vector<vector<int>> board;
int visited[20][20];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

// 미쳐버린 생각
// 보드를 회전시켜서 반복문을 일정하게 만들기!!
// rotation 함수를 만들어야한다.

void rotation(int cnt)
{
	// 시계방향으로 90도 씩 cnt번 회전

	vector<vector<int>> temp(n, vector<int>(n));
	vector<vector<int>> temp2(n, vector<int>(n));

	for (int k = 0; k < cnt; ++k)
	{
		// 회전하는 로직
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				temp[i][j] = board[n - j - 1][i];
				temp2[i][j] = visited[n - j - 1][i];
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				board[i][j] = temp[i][j];
				visited[i][j] = temp2[i][j];
			}
		}
	}
}

void move(int y, int x, int dir)
{
	// 이동하는 방향에 따라서 달라질거같다
	// 이동하는 방향이 위라면...
	// 맨 윗 줄부터 계산 시작?
	// 보드 맨 윗줄까지 가는데, 내랑 같은 숫자를 만나면 합체
	// 0이면 그냥 넘어가
	// 다른 숫자면 멈추기
	// 벽앞까지


	int cur = board[y][x];
	while (true)
	{
		if (cur == 0)
			break;

		if (y + dy[dir] == -1)
			break;

		if (board[y + dy[dir]][x + dx[dir]] == cur)
		{
			if (visited[y + dy[dir]][x + dx[dir]] == 1)
				break;

			board[y + dy[dir]][x + dx[dir]] = cur * 2;
			visited[y + dy[dir]][x + dx[dir]] = 1;
			board[y][x] = 0;
			break;
		}

		if (board[y + dy[dir]][x + dx[dir]] != cur && board[y + dy[dir]][x + dx[dir]] != 0)
			break;

		if (board[y + dy[dir]][x + dx[dir]] == 0)
		{
			board[y + dy[dir]][x + dx[dir]] = cur;
			board[y][x] = 0;

			y += dy[dir];
			x += dx[dir];
		}

	}
}

void moveAll()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			move(i, j, 0);
		}
	}
}

void printBoard()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void printVisited()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}


int res = -1;
void DFS(int L)
{
	if (L > 5)
		return;

	if (L == 5)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				res = max(res, board[i][j]);
			}
		}

		return;
	}


	// 보드 원상 복귀?
	int tempBoard[20][20];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			tempBoard[i][j] = board[i][j];
		}
	}


	for (int i = 0; i < 4; ++i)
	{
		rotation(i);
		moveAll();
		// 방문 초기화
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				visited[i][j] = 0;
			}
		}
		rotation(4 - i);

		//if (i == 0)
		//	cout << "UP" << endl;
		//else if (i == 1)
		//	cout << "LEFT" << endl;
		//else if (i == 2)
		//	cout << "DOWN" << endl;
		//else if (i == 3)
		//	cout << "RIGHT" << endl;

		//printBoard();
		//cout << "printVisited" << endl;
		//printVisited();
		//cout << endl;

		DFS(L + 1);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				board[i][j] = tempBoard[i][j];
			}
		}
	}

}

void solve()
{
	cin >> n;
	board = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	// 로직
	// 최대 5회의 경우 최대 결과 값을 출력
	// 모든 경우의 수를 다 해본다.
	// 브루트포스 방법
	// 무식하게 풀기.

	// 그럼 한 번 이동할 때 변하는 로직을 만들어야한다.
	// 이동은 move?
	// 방향 값을 받아야한다.
	// dir 필요

	DFS(0);

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

