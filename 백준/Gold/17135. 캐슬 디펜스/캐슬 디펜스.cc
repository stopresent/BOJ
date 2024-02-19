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

struct archer
{
	int pos;
};

struct enemy
{
	int y, x, idx;
	bool alive = true;
};

void setting();
void attack();
void move();
void killEnemy(int idx);
bool isEndGame();
void resetGame();
enemy canAttackEnemy(int pos);
void DFS(int s, int L);
void solve();


// 캐슬 디펜스

// 궁수는 3명
// 최대한 많은 적을 죽여야한다.
// 궁수를 배치하는 경우의 수를 모두 탐색하여 결과 계산하기?

// 로직
// 궁수를 배치한다.
// 궁수가 공격한다.
// 중복 공격이 가능하고, 가까운적이 여럿이면 가장 왼쪽 공격
// 적이 아래로 한 칸 이동
// 성으로 이동시 게임에서 제외

// 궁수의 위치는 중복 없는 순열


int n, m, d, archerCnt = 3, killCnt = 0, res = 0;
int archerPos[3] = { 0, 0, 0 };
vector<vector<int>> board;
vector<enemy> enemys, savePoint;
void setting()
{
	cin >> n >> m >> d;
	board = vector<vector<int>>(n + 1, vector<int>(m + 1));
	int idx = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				enemys.push_back({ i, j, idx, true });
				savePoint.push_back({ i, j, idx, true });
				idx++;
			}
		}
	}
}

void attack()
{
	vector<enemy> toDieEnemys;
	// 궁수의 공격은 동시에 이루어진다.
	for (int i = 0; i < archerCnt; ++i)
	{
		// 아처의 위치에서 공격가능한 적을 확인.
		enemy en = canAttackEnemy(archerPos[i]);
		if (en.alive == true)
		{
			toDieEnemys.push_back(en);
		}
	}

	// 여기서 진짜 죽이기
	if (toDieEnemys.size() != 0)
	{
		for (int i = 0; i < toDieEnemys.size(); ++i)
		{
			if (enemys[toDieEnemys[i].idx].alive == true)
			{
				killEnemy(toDieEnemys[i].idx);
				killCnt++;
			}
		}
	}
}

enemy canAttackEnemy(int pos)
{
	pair<int, int> archerPos = { n + 1, pos };
	vector<enemy> temp;
	int minDist = 123456789;
	for (int i = 0; i < enemys.size(); ++i)
	{
		int dist = ((n + 1 - enemys[i].y) + abs(enemys[i].x - pos));
		if (dist <= d)
		{
			temp.push_back(enemys[i]);
			minDist = min(minDist, dist);
		}
	}

	if (temp.size() != 0)
	{
		enemy ret = temp[0];
		for (int i = 0; i < temp.size(); ++i)
		{
			int dist = ((n + 1 - temp[i].y) + abs(temp[i].x - pos));

			// 가장 가까운거 해야됨. 그 중 젤 왼 쪽
			if (dist != minDist)
				continue;

			if (((n + 1 - ret.y) + abs(ret.x - pos)) != minDist)
				ret = temp[i];

			if (temp[i].x < ret.x)
			{
				ret = temp[i];
			}
		}

		return ret;
	}

	enemy falseEnemy = { -1, -1, -1, false };
	return falseEnemy;
}

void move()
{
	for (int i = 0; i < enemys.size(); ++i)
	{
		if (enemys[i].alive == false)
			continue;

		enemys[i].y++;

		if (enemys[i].y >= n + 1)
		{
			killEnemy(i);
		}
	}
}

void killEnemy(int idx)
{
	enemys[idx].y = 0;
	enemys[idx].x = 0;
	enemys[idx].alive = false;
}

bool isEndGame()
{
	for (int i = 0; i < enemys.size(); ++i)
	{
		if (enemys[i].alive == true)
			return false;
	}

	return true;
}

void resetGame()
{
	for (int i = 0; i < savePoint.size(); ++i)
	{
		enemys[i].y = savePoint[i].y;
		enemys[i].x = savePoint[i].x;
		enemys[i].idx = savePoint[i].idx;
		enemys[i].alive = savePoint[i].alive;
	}

	killCnt = 0;
}

void DFS(int s, int L)
{
	if (L == archerCnt)
	{
		//for (int i = 0; i < archerCnt; ++i)
		//{
		//	cout << archerPos[i] << " ";
		//}
		//cout << endl;
		// 여기서 궁수의 위치를 결정함.

		while (true)
		{
			if (isEndGame() == true)
				break;
			// 배치를 했으니 공격
			attack();
			// 적들 움직이기
			move();
			// 적들이 맵에 없을 때까지 해야됨.
		}

		res = max(res, killCnt);
		resetGame();
	}
	else
	{
		for (int i = s; i < m; ++i)
		{
			archerPos[L] = i + 1;
			DFS(i + 1, L + 1);
		}
	}
}

void solve()
{
	setting();

	DFS(0, 0);

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