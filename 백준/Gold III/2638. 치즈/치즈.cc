#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

void solve();
void BFS(int y, int x);
void BFS2(int y, int x);
void printBoard();
void visitedClear();
void Clear();

int n, m, res = 0, totalCheese = 0;
int dy[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
vector<vector<int>> board;
vector<vector<int>> isInAir; // 1이면 외부 공기 0이면 내부 공기
vector<vector<int>> visited;
vector<pair<int, int>> cheese;
//vector<pair<int, int>> toClear;

// 외부공기인지 내부공기인지
// 접촉면을 확인하는것.
// 치즈 그룹만들기

// 치즈 그룹 만들기?
void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	if (board[y][x] == 1 && visited[y][x] == 0)
	{
		q.push({ y, x });
		cheese.push_back({ y, x });
		visited[y][x] = 1;
	}
	pair<int, int> here;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > m)
				continue;
			if (visited[ny][nx] == 1)
				continue;
			if (board[ny][nx] == 0)
				continue;

			q.push({ ny, nx });
			cheese.push_back({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

}

// 내부 공기인지 판단하기
void BFS2(int y, int x)
{
	queue<pair<int, int>> q;

	q.push({ y, x });
	isInAir[y][x] = 1;
	pair<int, int> here;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > m)
				continue;
			if (isInAir[ny][nx] == 1)
				continue;
			if (board[ny][nx] == 1)
				continue;

			q.push({ ny, nx });
			isInAir[ny][nx] = 1;
		}
	}
}

void Clear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			isInAir[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void AddClearList()
{
	// 바로 지우지말고 클리어 리스트만 채워주자
	// 치즈 순회

	for (int i = 0; i < cheese.size(); ++i)
	{
		int cnt = 0;

		pair<int, int> ch = cheese[i];
		for (int j = 0; j < 4; ++j)
		{
			int ny = ch.first + dy[j];
			int nx = ch.second + dx[j];

			if (ny < 1 || nx < 1 || ny > n || nx > m)
				continue;
			if (isInAir[ny][nx] == 1 && board[ny][nx] == 0)
				cnt++;

			if (cnt >= 2)
			{
				board[ch.first][ch.second] = 0;
				totalCheese--;
				break;
				//toClear.push_back(ch);
			}
		}
	}
}

//void clearCheese()
//{
//	for (int i = 0; i < toClear.size(); ++i)
//	{
//		board[toClear[i].first][toClear[i].second] = 0;
//	}
//}

void visitedClear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			visited[i][j] = 0;
		}
	}
}

void airCheckClear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			isInAir[i][j] = 0;
		}
	}
}

void printBoard()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

bool haveCheese()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (board[i][j] == 1)
			{
				return true;
			}
		}
	}

	return false;
}

void solve()
{
	// 입력값 받기
	cin >> n >> m;
	board = vector<vector<int>>(n + 1, vector<int>(m + 1));
	visited = vector<vector<int>>(n + 1, vector<int>(m + 1));
	isInAir = vector<vector<int>>(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				totalCheese++;
		}
	}

	//printBoard();
	BFS2(1, 1); // 외부공기 판단

	while (true)
	{
		if (totalCheese == 0)
		{
			cout << res;
			break;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				BFS(i, j);
				if (cheese.size() != 0)
				{
					AddClearList();
					cheese.clear();
				}
			}
		}

		//clearCheese();
		//toClear.clear();
		Clear();
		//printBoard();
		BFS2(1, 1);
		res++;
	}
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