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

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };
int board[105][105];

void dragonCurve(int x, int y, int d, int g)
{
	vector<pair<int, int>> v;

	v.push_back({ y, x });

	int ny = y + dy[d];
	int nx = x + dx[d];
	v.push_back({ ny, nx });

	pair<int, int> endPoint = v.back(); // 이게 기준점
	int endPointY = endPoint.first;
	int endPointX = endPoint.second;

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

			v.push_back({ toAddY, toAddX });
		}

		endPointY = nEndPointY;
		endPointX = nEndPointX;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		board[v[i].first][v[i].second] = 1;
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