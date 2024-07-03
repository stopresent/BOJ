#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;

int N, M;
int dy[] = { 0, 1, 0, -1, -1, 1, 1, -1 };
int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
vector<vector<int>> board;
vector<vector<int>> visited;

void print_board()
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

void print_visited()
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cout << visited[y][x] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

void clear_visited()
{
	visited = vector<vector<int>>(N, vector<int>(M, 0));
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	if (visited[y][x] == false)
		visited[y][x] = true;
	q.push({ y, x });

	while (q.empty() == false)
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (visited[ny][nx])
				continue;
			if (board[ny][nx] == 0)
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}
}

int get_mass()
{
	int ret = 0;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (board[y][x] == 0)
				continue;
			if (visited[y][x])
				continue;
			
			bfs(y, x);
			//print_visited();
			ret++;
		}
	}

	clear_visited();
	return ret;
}

void melt()
{
	vector<pair<int, int>> save;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (board[y][x] == 0)
				continue;

			int cnt = 0;
			for (int i = 0; i < 4; ++i)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (board[ny][nx] == 0)
					save.push_back({ y, x });
			}
		}
	}

	for (int i = 0; i < save.size(); ++i)
	{
		int y = save[i].first;
		int x = save[i].second;
		board[y][x]--;
		board[y][x] = max(board[y][x], 0);
	}
}

void solve()
{
	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<int>>(N, vector<int>(M, 0));
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (y == 0 || y == N - 1 || x == 0 || x == M - 1)
				board[y][x] = 0;
			cin >> board[y][x];
		}
	}

	int total_time = 0;
	while (true)
	{
		int mass_count = get_mass();
		if (mass_count >= 2)
		{
			cout << total_time;
			break;
		}
		else if (mass_count == 0)
		{
			cout << 0;
			break;
		}

		total_time++;
		melt();
		//print_board();
	}
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