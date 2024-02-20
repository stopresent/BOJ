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

void setting();
void turn();
void move();
void setRobbot();
bool isEnd();
void printBelt();

// 컨베이어 벨트는 벡터? 링크드 리스트?
// 1 : 올리는 위치
// n : 내리는 위치

int n, k;
vector<pair<int, int>> belt; // 내구도, 로봇 여부
void setting()
{
	cin >> n >> k;
	belt = vector<pair<int, int>>(2 * n + 1);
	int temp;
	for (int i = 1; i <= 2 * n; ++i)
	{
		cin >> temp;

		belt[i] = { temp, 0 };
	}
}

void turn()
{
	// 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.

	belt[0] = belt[2 * n];
	for (int i = 2 * n; i > 0; --i)
	{
		if (i == n)
		{
			belt[i - 1].second = 0;
		}
		belt[i] = belt[i - 1];
	}
}

void move()
{
	// 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
	// 만약 이동할 수 없다면 가만히 있는다.
	// 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.

	for (int i = n; i > 0; --i)
	{
		if (belt[i].second == 0 && belt[i - 1].second == 1 && belt[i].first >= 1)
		{
			if (i == n)
			{
				belt[i].second = 0;
				belt[i - 1].second = 0;
				belt[i].first--;
				continue;
			}

			belt[i].second = 1;
			belt[i - 1].second = 0;
			belt[i].first--;
		}
	}
}

void setRobbot()
{
	// 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.

	if (belt[1].first != 0)
	{
		belt[1].second = 1;
		belt[1].first--;
	}
}

void printBelt()
{
	for (int i = 1; i <= 2 * n; ++i)
	{
		cout << "(" << belt[i].first << "," << belt[i].second << ")" << " ";
	}
	cout << endl;
}

bool isEnd()
{
	// 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정을 종료한다.
	// 그렇지 않다면 1번으로 돌아간다.

	int cnt = 0;

	for (int i = 1; i <= 2 * n; ++i)
	{
		if (belt[i].first == 0)
		{
			cnt++;
		}
	}

	if (cnt >= k)
		return true;

	return false;
}

void solve()
{
	setting();

	//cout << "시작 세팅 " << endl;
	//printBelt();

	int res = 0;
	while (true)
	{
		if (isEnd())
			break;

		turn();
		//cout << "한칸 회전 " << endl;
		//printBelt();

		move();
		//cout << "로봇 움직이기 " << endl;
		//printBelt();

		setRobbot();
		//cout << "로봇 올리기 " << endl;
		//printBelt();

		//cout << endl;
		res++;
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