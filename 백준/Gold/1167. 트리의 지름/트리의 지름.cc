#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

// 트리를 저장할 인접 리스트
vector<vector<pair<int, int>>> adj;

// 최대 노드 개수
const int MAX = 10001;
int n;

// DFS를 통해 가장 먼 노드와 그 거리를 찾는 함수
pair<int, ll> dfs(int cur, int parent, ll dist)
{
	pair<int, ll> maxDist = { cur, dist };

	for (int i = 0; i < adj[cur].size(); ++i)
	{
		if (adj[cur][i].first != parent)
		{
			pair<int, ll> temp = dfs(adj[cur][i].first, cur, dist + adj[cur][i].second);
			if (temp.second > maxDist.second)
				maxDist = temp;
		}
	}

	return maxDist;
}

pair<int, ll> bfs(int start, int n)
{
	vector<ll> distance(n + 1, 0);
	queue<int> q;
	q.push(start);

	while (q.empty() == false)
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); ++i)
		{
			int next = adj[here][i].first;
			int weight = adj[here][i].second;

			if (distance[next] == 0 && next != start)
			{
				distance[next] = distance[here] + weight;
				q.push(next);
			}
		}
	}

	// 가장 먼 노드 찾기
	int ret = start;
	ll maxDist = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (distance[i] > maxDist)
		{
			maxDist = distance[i];
			ret = i;
		}
	}

	return {ret, maxDist};
}

void solve()
{
	cin >> n;

	// 인접 리스트 초기화 (1부터 n까지)
	adj = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());

	// n - 1개의 간선 입력
	for (int i = 0; i < n; i++)
	{
		int parent, child = 0, weight = 0;
		cin >> parent;
		while (true)
		{
			cin >> child;
			if (child == -1)
				break;
			cin >> weight;
			adj[parent].push_back({ child, weight });
			adj[child].push_back({ parent, weight });
		}
	}

	if (n == 1)
	{
		cout << "0";
		return;
	}

	// 첫 번째 DFS: 루트 노드(1)에서 가장 먼 노드 찾기
	pair<int, ll> first = bfs(1, n);

	// 두 번째 DFS: 노드 A에서 가장 먼 노드 B 찾기
	pair<int, ll> second = bfs(first.first, n);

	// 트리의 지름은 두 번째 DFS에서 찾은 거리
	cout << second.second;
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