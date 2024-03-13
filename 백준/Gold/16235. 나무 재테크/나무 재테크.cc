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

struct Tree
{
	int r, c, age;
	bool operator<(const Tree& other)
	{
		return age < other.age;
	}
};

const int MAX = 1234567890;
int n, m, k;
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<vector<int>> board; // 영양분을 계산하고 있다.
vector<vector<vector<int>>> trees;
vector<Tree> deadTrees;
vector<Tree> divTrees;
vector<vector<int>> S2D2; // 겨울에 들어올 에너지 값을 저장한다.

void setting()
{
	// 입력값
	cin >> n >> m >> k;
	// 공간 확보.
	board = vector<vector<int>>(n + 1, vector<int>(n + 1, 5)); // 초기에는 5의 영양분이 있다.
	S2D2 = vector<vector<int>>(n + 1, vector<int>(n + 1));
	trees = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1));
	// 겨울에 들어올 에너지 값 저장.
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			cin >> S2D2[y][x];
		}
	}

	// 초기에 심겨진 나무 저장
	int r, c, age;
	for (int i = 1; i <= m; ++i)
	{
		cin >> r >> c >> age;
		trees[r][c].push_back(age);
	}
}

void spring()
{
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			if (trees[y][x].size() == 0)
				continue;

			sort(trees[y][x].begin(), trees[y][x].end());

			int size = trees[y][x].size();
			int deadCnt = 0;
			for (int k = 0; k < size; ++k)
			{
				if (board[y][x] >= trees[y][x][k])
				{
					// 나이만큼 양분을 먹고 나이가 한살 증가한다.
					board[y][x] -= trees[y][x][k];
					trees[y][x][k]++;

					if (trees[y][x][k] % 5 == 0)
					{
						divTrees.push_back({y, x, trees[y][x][k] });
					}
				}
				else
				{
					deadTrees.push_back({ y, x, trees[y][x][k] });
					deadCnt++;
				}
			}

			for (int k = 0; k < deadCnt; ++k)
					trees[y][x].pop_back();
		}
	}
}

void summer()
{
	// 봄에 죽은 나무가 양분으로 변한다.
	for (int i = 0; i < deadTrees.size(); ++i)
	{
		int energy = deadTrees[i].age / 2;
		board[deadTrees[i].r][deadTrees[i].c] += energy;
	}

	deadTrees.clear();
}

void autumn()
{
	for (int i = 0; i < divTrees.size(); ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			int ny = divTrees[i].r + dy[j];
			int nx = divTrees[i].c + dx[j];

			if (ny < 1 || nx < 1 || ny > n || nx > n)
				continue;
			// 나이가 1인 나무 추가.
			trees[ny][nx].push_back(1);
			
		}
	}

	divTrees.clear();
}

void winter()
{
	// 영양분 공급하기.
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			board[y][x] += S2D2[y][x];
		}
	}
}

void solve()
{
	setting();

	for (int i = 1; i <= k; ++i)
	{
		spring();
		summer();
		autumn();
		winter();
	}

	int cnt = 0;

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			cnt += trees[y][x].size();
		}
	}
	cout << cnt;
}

int main()
{
	FILE* stream;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}