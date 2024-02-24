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
void turnLeft(int num);
void turnRight(int num);

struct Gear
{
	int cogs[8];
};

vector<Gear> gears;
//Gear gears[4];
// 이미 돌려졌는지 아닌지 확인용이 필요할듯
int ch[1001];
int n;

void turnRight(int num)
{
	if (ch[num] == 1)
		return;
	ch[num] = 1;

	int curLeft = gears[num].cogs[6];
	int curRight = gears[num].cogs[2];

	// 오른쪽으로 돌리기
	int temp = gears[num].cogs[7];
	for (int i = 7; i > 0; --i)
	{
		gears[num].cogs[i] = gears[num].cogs[i - 1];
	}
	gears[num].cogs[0] = temp;

	// 왼쪽 바퀴 상호작용
	if (num - 1 >= 0 && gears[num - 1].cogs[2] != curLeft)
	{
		// 왼쪽 바퀴 반시계 방향으로 돌리기
		turnLeft(num - 1);
	}

	// 오른쪽 바퀴 상호작용
	if (num + 1 < n && gears[num + 1].cogs[6] != curRight)
	{
		// 오른쪽 바퀴 반시계 방향으로 돌리기
		turnLeft(num + 1);
	}
}

void turnLeft(int num)
{
	if (ch[num] == 1)
		return;
	ch[num] = 1;

	int curLeft = gears[num].cogs[6];
	int curRight = gears[num].cogs[2];

	// 왼쪽으로 돌리기
	int temp = gears[num].cogs[0];
	for (int i = 0; i < 7; ++i)
	{
		gears[num].cogs[i] = gears[num].cogs[i + 1];
	}
	gears[num].cogs[7] = temp;

	// 왼쪽 바퀴 상호작용
	if (num - 1 >= 0 && gears[num - 1].cogs[2] != curLeft)
	{
		// 왼쪽 바퀴 시계 방향으로 돌리기
		turnRight(num - 1);
	}

	// 오른쪽 바퀴 상호작용
	if (num + 1 < n && gears[num + 1].cogs[6] != curRight)
	{
		// 오른쪽 바퀴 시계 방향으로 돌리기
		turnRight(num + 1);
	}

}

int CheckScore()
{
	int res = 0;

	for (int i = 0; i < n; ++i)
	{
		if (gears[i].cogs[0] == 1)
			res++;
	}

	//if (gears[0].cogs[0] == 1)
	//	res += 1;
	//if (gears[1].cogs[0] == 1)
	//	res += 2;
	//if (gears[2].cogs[0] == 1)
	//	res += 4;
	//if (gears[3].cogs[0] == 1)
	//	res += 8;

	return res;
}

void VsitedClear()
{
	for (int i = 0; i < n; ++i)
	{
		ch[i] = 0;
	}
}

void PrintGears()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << gears[i].cogs[j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

void solve()
{
	cin >> n;
	gears = vector<Gear>(n);
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); ++j)
		{
			gears[i].cogs[j] = str[j] - '0';
		}
	}

	//PrintGears();

	int k; // 회전시킬 횟수
	cin >> k;

	int num, dir; // 회전할 바퀴 넘버와 회전 방향
	// dir = 1 -> 시계 방향
	// dir = -1 -> 반시계 방향
	for (int i = 0; i < k; ++i)
	{
		cin >> num >> dir;

		VsitedClear();

		if (dir == 1)
		{
			turnRight(num - 1);
		}
		else if (dir == -1)
		{
			turnLeft(num - 1);
		}

		//cout << "[" <<  i + 1 << "]" << endl;
		//PrintGears();
	}

	cout << CheckScore();
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