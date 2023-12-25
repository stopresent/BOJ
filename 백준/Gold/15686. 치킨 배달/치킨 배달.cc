// 치킨 배달
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// 빈 칸 : 0
// 집 : 1
// 치킨집 : 2

int n, m, res = 123456789, houseCnt, chickCnt;
vector<vector<int>> board;
vector<pair<int, int>> chick;
vector<pair<int, int>> house;

void setting()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 2, vector<int>(n + 2));

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			cin >> board[y][x];
			if (board[y][x] == 1)
				house.push_back({ y, x });
			if (board[y][x] == 2)
				chick.push_back({ y, x });
		}
	}

	houseCnt = house.size();
	chickCnt = chick.size();
}

int cal = 0;
void pick(int num, vector<int>& picked, int toPick)
{
	if (toPick == 0)
	{
		// 치킨 집 선택하기
		for (int i = 0; i < picked.size(); ++i)
		{
			board[chick[picked[i]].first][chick[picked[i]].second] = 3;
		}
		
		// 치킨 거리 구하기
		cal = 0;
		for (int i = 0; i < house.size(); ++i)
		{
			pair<int, int> h = { house[i].first, house[i].second };

			int temp = 12345678;
			for (int y = 1; y <= n; ++y)
			{
				for (int x = 1; x <= n; ++x)
				{
					if (board[y][x] == 3)
					{
						temp = min(temp,abs(h.first - y) + abs(h.second - x));
					}
				}
			}
			cal += temp;
		}

		res = min(res, cal);

		// 치킨 집 원상복구
		for (int i = 0; i < picked.size(); ++i)
		{
			board[chick[picked[i]].first][chick[picked[i]].second] = 2;
		}

		return;
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int next = smallest; next < num; ++next)
	{
		picked.push_back(next);
		pick(num, picked, toPick - 1);
		picked.pop_back();
	}
}

void solve()
{
	// 치킨 집 m개만 남기고 다 없앤다
	// 치킨 거리를 구한다
	// 모든 경우를 탐색한다

	vector<int> test;
	pick(chickCnt, test, m);
	
	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	setting();
	solve();

	return 0;
}