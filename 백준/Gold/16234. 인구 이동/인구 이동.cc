#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, L, R, res = 0;
vector<vector<int>> board;
vector<vector<int>> discovered;
vector<pair<int, int>> v;
queue<pair<int, int>> q;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool flag = true;
int sum = 0;

void BFS(pair<int, int> here)
{
	q.push(here);
	//v.push_back(here);
	discovered[here.first][here.second] = 1;

	// 국경선 열기
	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		if (flag != true)
			flag = false;
		for (int i = 0; i < 4; ++i)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny < 1 || nx < 1 || ny > N || nx > N)
				continue;
			if (discovered[ny][nx] == 1)
				continue;

			int diff = abs(board[here.first][here.second] - board[ny][nx]);
			if (diff < L || diff > R)
				continue;

			q.push({ ny, nx });
			v.push_back({ ny, nx });
			discovered[ny][nx] = 1;
			sum += board[ny][nx];
		}
	}

	// 인구 이동 횟수 증가
	//if (flag == true)
	//{
	//	isEnd = false;
	//}

	// 연합 만들기
	//int vSize = v.size();

	//sum /= vSize;

	//for (int i = 0; i < vSize; ++i)
	//{
	//	board[v[i].first][v[i].second] = sum;
	//}
}

void solve()
{
	cin >> N >> L >> R;
	board = vector<vector<int>>(N + 1, vector<int>(N + 1));
	discovered = vector<vector<int>>(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> board[i][j];
		}
	}

	// 로직
	// 1. 국경선을 연다.
	// 2. 모든 국경선을 열었으면 연합을 만든다.
	// 3. 연합을 해체하고 국경선을 닫는다.
	// BFS?


	while (true)
	{
		if (flag == false)
			break;

		flag = false;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (discovered[i][j] == 0)
				{
					v.clear();
					v.push_back({ i, j });
					sum = board[i][j];
					BFS({ i, j });
				}

				if (v.size() >= 2)
				{
					flag = true;
					int vSize = v.size();

					for (int i = 0; i < vSize; ++i)
					{
						board[v[i].first][v[i].second] = sum / vSize;
					}
				}
			}
		}

		if (flag)
			res++;

		// 연합 해체하고 국경선 닫기
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				discovered[i][j] = 0;
			}
		}
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