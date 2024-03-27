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
#include <map>

using namespace std;

int n, m;
bool visited[101];
map<int, int> snake, ladder;

void BFS()
{
	// 현재위치, 카운트
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	visited[1] = true;
	pair<int, int> here;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		// 사다리, 뱀 적용
		if (ladder.find(here.first) != ladder.end())
			here.first = ladder[here.first];
		if (snake.find(here.first) != snake.end())
			here.first = snake[here.first];

		if (here.first == 100)
		{
			cout << here.second << '\n';
			return;
		}

		for (int i = 1; i <= 6; ++i)
		{
			if (visited[here.first + i] == false)
			{
				visited[here.first + i] = true;
				q.push({ here.first + i, here.second + 1 });
			}
		}
	}
}

void solve()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		// 사다리 정보 입력
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}

	for (int i = 0; i < m; ++i)
	{
		// 뱀 정보 입력
		int u, v;
		cin >> u >> v;
		snake[u] = v;
	}

	BFS();
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