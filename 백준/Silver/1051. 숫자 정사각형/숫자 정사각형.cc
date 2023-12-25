#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, res = 1;
int board[52][52];

void printBoard()
{
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			cout << board[y][x];
		}
		cout << endl;
	}
}

void setting()
{
	cin >> n >> m;

	string str;
	for (int y = 0; y < n; ++y)
	{
		cin >> str;
		for (int x = 0; x < m; ++x)
		{
			board[y][x] = str[x] - '0';
		}
	}
}

void solve()
{
	// 로직의 순서
	// 보드의 처음부터 끝까지 순회를 할거임
	// 한 위치에서 해야하는 일
	// 1. 그 위치에서 오른쪽 방향으로 스캔시작 (범위 생각)
	// 2. 자신과 같은 숫자가 나오면 그 차이만큼 해당위치에서 아래로 이동해서 확인 (범위체크 필요)
	// 3. 자신의 위치에서도 같은 역할 수행
	// 4. 기존의 값보다 크면 값 갱신

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			int cur = board[y][x];
			for (int i = x; i < m; ++i)
			{
				if (board[y][i] == cur)
				{
					int dist = i - x;

					if (y + dist < n && board[y + dist][x] == cur && board[y + dist][i] == cur)
					{
						res = max(res, (dist + 1) * (dist + 1));
					}
				}
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

	setting();
	//printBoard();
	solve();

	return 0;
}