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

int N, Q, L, board_size, mass = 0;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<vector<int>> board;
vector<vector<bool>> visited;

void print_board()
{
	for (int y = 0; y < board_size; ++y)
	{
		for (int x = 0; x < board_size; ++x)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

int clone[200][200];

void rotate_square(int y1, int x1, int size) 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			clone[y1 + j][x1 + size - i - 1] = board[y1 + i][x1 + j];
	}
}

void DFS(int y, int x, int size)
{
	if (size == pow(2, L))
	{
		// L단계만큼 쪼개졌다.
		
		// 복사
		//int clone[200][200];
		//for (int i = y; i < y + size; ++i)
		//{
		//	for (int j = x; j < x + size; ++j)
		//	{
		//		clone[j][y + size - i - 1] = board[i][j];
		//	}
		//}
		rotate_square(y, x, size);

		//for (int i = y; i < y + size; ++i)
		//{
		//	for (int j = x; j < x + size; ++j)
		//	{
		//		board[i][j] = clone[j][board_size - i - 1];
		//	}
		//}

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				board[y + i][x + j] = clone[y + i][x + j];
			}
		}

		return;
	}
	else
	{
		// L단계만큼 쪼개지지 않았다.
		DFS(y, x, size / 2);
		DFS(y + size / 2, x, size / 2);
		DFS(y, x + size / 2, size / 2);
		DFS(y + size / 2, x + size / 2, size / 2);
	}
}

void melt()
{
	vector<pair<int, int>> temp;

	for (int y = 0; y < board_size; ++y)
	{
		for (int x = 0; x < board_size; ++x)
		{
			// 인접한 얼음의 개수
			int cnt = 0;
			for (int k = 0; k < 4; ++k)
			{
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny < 0 || nx < 0 || ny > board_size - 1 || nx > board_size - 1)
					continue;
				if (board[ny][nx] == 0)
					continue;

				cnt++;
			}

			if (cnt < 3)
			{
				temp.push_back({ y, x });
			}
		}
	}

	for (int i = 0; i < temp.size(); ++i)
	{
		board[temp[i].first][temp[i].second]--;
		if (board[temp[i].first][temp[i].second] < 0)
			board[temp[i].first][temp[i].second] = 0;
	}
}

void BFS(int y, int x)
{
	int cnt = 0;
	queue<pair<int, int>> q;
	if (visited[y][x] == true || board[y][x] == 0)
		return;
	visited[y][x] = true;
	q.push({ y, x });
	pair<int, int> here;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();
		visited[here.first][here.second] = true;
		cnt++;
		mass = max(mass, cnt);

		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 0 || nx < 0 || ny > board_size - 1 || nx > board_size - 1)
				continue;
			if (visited[ny][nx] == true)
				continue;
			if (board[ny][nx] == 0)
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}
}

void solve()
{
	cin >> N >> Q;
	board_size = pow(2, N);
	board = vector<vector<int>>(board_size, vector<int>(board_size));
	visited = vector<vector<bool>>(board_size, vector<bool>(board_size, false));

	for (int y = 0; y < board_size; ++y)
	{
		for (int x = 0; x < board_size; ++x)
		{
			cin >> board[y][x];
		}
	}

	//print_board();

	for (int i = 0; i < Q; ++i)
	{
		cin >> L;

		// 쪼개고 회전하기
		DFS(0, 0, board_size);

		//얼음 녹이기
		melt();

		//print_board();
	}

	// 남아있는 얼음의 합
	int sum = 0;
	for (int y = 0; y < board_size; ++y)
	{
		for (int x = 0; x < board_size; ++x)
		{
			sum += board[y][x];
		}
	}
	cout << sum << '\n';

	// 최대 덩어리
	for (int y = 0; y < board_size; ++y)
	{
		for (int x = 0; x < board_size; ++x)
		{
			BFS(y, x);
		}
	}
	cout << mass << '\n';
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