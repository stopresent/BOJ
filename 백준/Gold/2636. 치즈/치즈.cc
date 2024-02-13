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
void removeCheese(vector<pair<int, int>> cheese);
void printBoard();
void visitedClear();
void visited2Clear();

int n, m;
int dy[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
vector<vector<int>> board;
vector<vector<int>> visited;
vector<vector<int>> visited2;
vector<pair<int, int>> cheese;

void solve()
{
	cin >> n >> m;
	board = vector<vector<int>>(n + 1, vector<int>(m + 1));
	visited = vector<vector<int>>(n + 1, vector<int>(m + 1));
	visited2 = vector<vector<int>>(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> board[i][j];
		}
	}

	// 그룹을 짓는다.
	// 그룹의 가장자리를 구한다.
	// 그룹의 가장자리를 없앤다.
	// 다시 그룹을 짓는다.
	// ...

	// 가장자리 개념을 어떻게 알지
	// 위가 0이면서 그룹 내에 맨위 y값을 알야한다.

	// 그룹의 개념은 bfs로 만든다?
	// 
	//

	//printBoard();
	//cout << '\n';

	int totalTime = 0;
	int lastCheese = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (board[i][j] == 1)
			{
				lastCheese++;
			}
		}
	}
	bool flag = true;

	while (flag == true)
	{
		flag = false;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				BFS(i, j);
				if (cheese.size() != 0)
				{
					flag = true;
					removeCheese(cheese);
					cheese.clear();
				}
			}
		}

		//printBoard();
		//cout << endl;

		int cheeseCnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (board[i][j] == 1)
				{
					cheeseCnt++;
				}
			}
		}

		totalTime++;
		if (cheeseCnt != 0)
			lastCheese = cheeseCnt;
		else if (cheeseCnt == 0)
			flag = false;

		visitedClear();
	}

	cout << totalTime << '\n';
	cout << lastCheese;
}

void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	if (board[y][x] == 1 && visited[y][x] == 0)
		q.push({ y, x });

	pair<int, int> here;

	while (q.empty() == false)
	{
		here = q.front();
		cheese.push_back(here);
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > m)
				continue;
			if (board[ny][nx] == 0)
				continue;
			if (visited[ny][nx] == 1)
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}
}

bool BFS2(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });

	pair<int, int> here;
	bool flag = false;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > m)
			{
				flag = true;
				return flag;
			}
			if (board[ny][nx] == 1)
				continue;
			if (visited2[ny][nx] == 1)
				continue;

			q.push({ ny, nx });
			visited2[ny][nx] = 1;
		}
	}

	return flag;
}

// 이 함수가 잘못됨
// 치즈 겉만 지워야하는데 로직이 잘못됐다
// 치즈 겉을 알수있는 방법은?
void removeCheese(vector<pair<int, int>> cheese)
{
	vector<pair<int, int>> clearList;

	int up = 100, down = 0, left = 100, right = 0;
	for (int i = 0; i < cheese.size(); ++i)
	{
		up = min(up, cheese[i].first);
		down = max(down, cheese[i].first);
		left = min(left, cheese[i].second);
		right = max(right, cheese[i].second);
	}

	for (int i = 0; i < cheese.size(); ++i)
	{
		visited2Clear();

		// 위쪽 가장자리인 경우
		if (board[cheese[i].first - 1][cheese[i].second] == 0)
		{
			// bfs2 돌리기
			bool flag = BFS2(cheese[i].first - 1, cheese[i].second);
			if (flag == true) // 가장자리다.
			{
				clearList.push_back({ cheese[i].first, cheese[i].second });
				continue;
			}

			visited2Clear();
		}

		// 왼쪽 가장자리인 경우
		if (board[cheese[i].first][cheese[i].second - 1] == 0)
		{
			// bfs2 돌리기
			bool flag = BFS2(cheese[i].first, cheese[i].second - 1);
			if (flag == true) // 가장자리다.
			{
				clearList.push_back({ cheese[i].first, cheese[i].second });
				continue;
			}

			visited2Clear();
		}

		// 오른쪽 가장자리인 경우
		if (board[cheese[i].first][cheese[i].second + 1] == 0)
		{
			// bfs2 돌리기
			bool flag = BFS2(cheese[i].first, cheese[i].second + 1);
			if (flag == true) // 가장자리다.
			{
				clearList.push_back({ cheese[i].first, cheese[i].second });
				continue;
			}

			visited2Clear();
		}

		// 아래쪽 가장자리인 경우
		if (board[cheese[i].first + 1][cheese[i].second] == 0)
		{
			// bfs2 돌리기
			bool flag = BFS2(cheese[i].first + 1, cheese[i].second);
			if (flag == true) // 가장자리다.
			{
				clearList.push_back({ cheese[i].first, cheese[i].second });
				continue;
			}

			visited2Clear();
		}

	}


	for (int i = 0; i < clearList.size(); ++i)
	{
		board[clearList[i].first][clearList[i].second] = 0;
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

		cout << '\n';
	}
}

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

void visited2Clear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			visited2[i][j] = 0;
		}
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