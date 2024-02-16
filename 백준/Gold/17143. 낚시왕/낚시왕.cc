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

struct Shark
{
	int r, c, s, d, z;

	bool operator<(const Shark other)
	{
		if (r < other.r)
			return true;
		return false;
	}
};

void setting();
void solve();
void moveShark();
void removeShark(int idx);
void setSharks();
void printBoard();

// 1. 낚시왕이 오른쪽으로 한 칸 이동
// 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
// 3. 상어가 이동한다.

int R, C, M, r, c, s, d, z, res = 0;
int dy[] = { 0, -1, 1, 0, 0 };
int dx[] = { 0, 0, 0, 1, -1 };
vector<vector<int>> board;
vector<Shark> sharks;

void setting()
{
	cin >> R >> C >> M;
	board = vector<vector<int>>(R + 1, vector<int>(C + 1));
	sharks = vector<Shark>(M + 1);

	sharks[0].r = 0;
	sharks[0].c = 0;
	sharks[0].s = 0;
	sharks[0].d = 0;
	sharks[0].z = 0;

	for (int i = 1; i <= M; ++i)
	{
		cin >> r >> c >> s >> d >> z;
		sharks[i].r = r;
		sharks[i].c = c;
		sharks[i].s = s;
		sharks[i].d = d;
		sharks[i].z = z;

		if (d <= 2)
		{
			sharks[i].s = s % ((R - 1) * 2);
		}
		else if (d >= 3)
		{
			sharks[i].s = s % ((C - 1) * 2);
		}
	}
}

void moveShark()
{
	for (int i = 0; i < sharks.size(); ++i)
	{
		if (sharks[i].r == 0)
			continue;

		int y = sharks[i].r;
		int x = sharks[i].c;
		//board[y][x] = 0; // 자리를 떠났다.

		for (int j = 0; j < sharks[i].s; ++j)
		{
			int ny = y + dy[sharks[i].d];
			int nx = x + dx[sharks[i].d];

			if (ny < 1 || nx < 1 || ny > R || nx > C)
			{
				if (sharks[i].d == 1 || sharks[i].d == 3)
				{
					sharks[i].d++;
					ny = y + dy[sharks[i].d];
					nx = x + dx[sharks[i].d];
				}
				else if (sharks[i].d == 2 || sharks[i].d == 4)
				{
					sharks[i].d--;
					ny = y + dy[sharks[i].d];
					nx = x + dx[sharks[i].d];
				}
			}

			y = ny;
			x = nx;
		}

		// 이동을 완료한 상어인지 아닌지 판별해야함
		if (board[y][x] == 0)
		{
			board[y][x] = i;
			sharks[i].r = y;
			sharks[i].c = x;
		}
		else if (board[y][x] < i)
		{
			if (sharks[board[y][x]].z > sharks[i].z)
			{
				removeShark(i);
				//board[y][x] = sharks[board[y][x]].r;
			}
			else
			{
				removeShark(board[y][x]);
				board[y][x] = i;
				sharks[i].r = y;
				sharks[i].c = x;
			}
		}
	}

	//printBoard();

	for (int i = 0; i < sharks.size(); ++i)
	{
		board[sharks[i].r][sharks[i].c] = 0;
	}
}

void eatShark()
{
	if (sharks.size() == 0)
		return;

	for (int i = 0; i < sharks.size(); ++i)
	{
		if (sharks[i].r == 0)
			continue;

		for (int j = i + 1; j < sharks.size(); ++j)
		{
			if (sharks[j].r == 0)
				continue;

			// 같은 곳에 상어가 존재 할 경우
			if (sharks[i].r == sharks[j].r && sharks[i].c == sharks[j].c)
			{
				if (sharks[i].z < sharks[j].z)
				{
					removeShark(i);
				}
				else
				{
					removeShark(j);
				}
			}
		}
	}
}

void removeShark(int idx)
{
	sharks[idx].r = 0;
	sharks[idx].c = 0;
	sharks[idx].d = 0;
	sharks[idx].s = 0;
	sharks[idx].z = 0;
}

void setSharks()
{
	//for (int i = 1; i <= R; ++i)
	//{
	//	for (int j = 1; j <= C; ++j)
	//	{
	//		board[i][j] = 0;
	//	}
	//}

	//for (int i = 0; i < sharks.size(); ++i)
	//{
	//	if (sharks[i].r == 0)
	//		continue;
	//	board[sharks[i].r][sharks[i].c] = 1;
	//}

	printBoard();
}

void printBoard()
{
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			cout << board[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
}

void solve()
{
	setting();
	// 주인공은 1부터 C까지 이동
	for (int pos = 1; pos <= C; ++pos)
	{
		// 상어 잡기
		pair<int, int> temp = { 1000, 1000 }; // 인덱스, r값
		for (int k = 0; k < sharks.size(); ++k)
		{
			if (sharks[k].c == pos)
			{
				if (sharks[k].r < temp.second)
				{
					temp.first = k;
					temp.second = sharks[k].r;
				}
			}
		}

		if (temp.first != 1000)
		{
			res += sharks[temp.first].z;
			removeShark(temp.first);
		}

		moveShark();
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