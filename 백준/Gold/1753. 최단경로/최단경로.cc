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

struct Edge
{
	int v;
	int dist;

	bool operator<(const Edge& other) const
	{
		return dist > other.dist;
	}
};

int n, m, k, a, b, c;
int ch[30];
priority_queue<Edge> pq;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
void solve()
{
	cin >> n >> m >> k;

	// 모든 정점까지의 거리는 매우 큰 숫자로 초기화
	dist = vector<int>(n + 1, 123456789);
	graph = vector<vector<pair<int, int>>>(n + 1);

	// 가중치 방향 그래프 생성
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	// 우선순위 큐 시작 정점 삽입
	pq.push({ k,0 });
	dist[k] = 0; // 처음 시작은 거리가 0
	while (pq.empty() == false)
	{
		int cur = pq.top().v;
		int cost = pq.top().dist;
		pq.pop();

		// 이미 방문한 곳인데 더 작은 값이 존재한다면 스킵
		if (cost > dist[cur])
			continue;

		// 정점과 연결된 정점들 순회
		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i].first;
			int nextCost = cost + graph[cur][i].second; // 이전까지의 비용과 간선의 가중치의 합
			if (nextCost < dist[next]) // 찐또배기 작은 값
			{
				dist[next] = nextCost; // 거리값 갱신
				pq.push({ next, nextCost }); // 우선순위 큐에 삽입
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (dist[i] == 123456789)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
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