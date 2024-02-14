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

void printBoard();

//
// 드래곤 커브
// 
// 0: x좌표가 증가하는 방향 (→)
// 1: y좌표가 감소하는 방향(↑)
// 2 : x좌표가 감소하는 방향(←)
// 3 : y좌표가 증가하는 방향(↓)
// 
// x, y, d, g
// x = x시작 좌표
// y = 시작 y좌표
// d = 방향
// g = 세대값
//

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };
int board[105][105];
int visited[101][101]; // 하나하나 그릴거니까 필요할듯

// 현재까지 그린것에서 90도 돌려서 그리는게 필요


void dragonCurve(int x, int y, int d, int g)
{
	// 주어진 정보값으로 드래곤 커브를 
	// g번 돌리기... 흠..그린다.
	// 어떻게 그릴까

	vector<pair<int, int>> v;

	visited[y][x] = 1;
	v.push_back({ y, x });

	int ny = y + dy[d];
	int nx = x + dx[d];
	visited[ny][nx] = 1;
	v.push_back({ ny, nx });

	// ny, nx를 기준으로 돌려야한다.
	// 끝점을 아는 방법은? 벡터의 끝? 기준점에서 회전한다 
	pair<int, int> endPoint = v.back(); // 이게 기준점
	int endPointY = endPoint.first;
	int endPointX = endPoint.second;


	// 시계 방향으로 회전은
	// 기준점에서 x차이랑 y차이 
	// 기준을 0,0 으로 만든 뒤 계산하게 쉽게 만들기

	int nEndPointY = 0, nEndPointX = 0;
	for (int k = 0; k < g; ++k)
	{
		int vSize = v.size();
		for (int i = 0; i < vSize; ++i)
		{
			int viy = v[i].first;
			int vix = v[i].second;

			if (viy == endPointY && vix == endPointX)
				continue;

			// 0, 0을 기준으로 초기화
			viy -= endPointY;
			vix -= endPointX;

			int toAddY = vix;
			int toAddX = -viy;

			// 그 뒤 변한 값들을 더해주기
			toAddY += endPointY;
			toAddX += endPointX;

			// 0번째가 다음 기준점이 된다.
			if (i == 0)
			{
				nEndPointY = toAddY;
				nEndPointX = toAddX;
			}

			visited[toAddY][toAddX] = 1;
			v.push_back({ toAddY, toAddX });
		}

		endPointY = nEndPointY;
		endPointX = nEndPointX;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		board[v[i].first][v[i].second] = 1;
	}

	//printBoard();
	//cout << endl;

	//for (int i = 1; i <= 10; ++i)
	//{
	//	for (int j = 1; j <= 10; ++j)
	//	{
	//		board[i][j] = 0;
	//	}
	//}

	// visited 정보값을 board에 적용하기
}

void visitedClear()
{
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			visited[i][j] = 0;
		}
	}
}

void printBoard()
{
	int num = 100;

	for (int i = 1; i <= num; ++i)
	{
		for (int j = 1; j <= num; ++j)
		{
			cout << board[i][j];
		}

		cout << '\n';
	}
}

int getResult()
{
	// 네 꼭지점이 드래곤 커브의 일부인 것의 개수

	int res = 0, num = 100;

	for (int i = 0; i <= num; ++i)
	{
		for (int j = 0; j <= num; ++j)
		{
			if (board[i][j] == 1)
			{
				if (board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] == 1)
				{
					res++;
				}
			}
		}
	}

	return res;
}

void solve()
{
	int n;
	cin >> n;

	int x, y, d, g;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y >> d >> g;

		dragonCurve(x, y, d, g);
	}

	cout << getResult();
	//printBoard();

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