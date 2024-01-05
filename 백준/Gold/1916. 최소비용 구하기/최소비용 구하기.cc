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
	int cost;

	bool operator<(const Edge& other) const
	{
		return cost > other.cost;
	}
};

int n, m, go, finish;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
void setting()
{
	cin >> n >> m;
	graph = vector<vector<pair<int, int>>>(n + 1);
	dist = vector<int>(n + 1, 123456789);
	int a, b, c;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	cin >> go >> finish;
}

priority_queue<Edge> pq;
void dijkstra(int here, int distance)
{
	pq.push({ here, distance });
	dist[here] = 0;
	while (pq.empty() == false)
	{
		int here = pq.top().v;
		int cost = pq.top().cost;
		pq.pop();

		if (cost > dist[here])
			continue;

		for (int there = 0; there < graph[here].size(); ++there)
		{
			int next = graph[here][there].first;
			int nextCost = cost + graph[here][there].second;
			if (nextCost < dist[next])
			{
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	setting();
	dijkstra(go, 0);
	cout << dist[finish];

	return 0;
}