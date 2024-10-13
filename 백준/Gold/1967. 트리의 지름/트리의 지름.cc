#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
	for (auto& [neighbor, weight] : adj[cur])
	{
		if (neighbor != parent)
		{
			pair<int, ll> temp = dfs(neighbor, cur, dist + weight);
			if (temp.second > maxDist.second)
				maxDist = temp;
		}
	}
	return maxDist;
}

void solve()
{
	cin >> n;

	// 인접 리스트 초기화 (1부터 n까지)
	adj.assign(n + 1, vector<pair<int, int>>());

	// n - 1개의 간선 입력
	for (int i = 0; i < n - 1; i++)
	{
		int parent, child, weight;
		cin >> parent >> child >> weight;
		adj[parent].emplace_back(child, weight);
		adj[child].emplace_back(parent, weight);
	}

	if (n == 1)
	{
		cout << "0";
		return;
	}

	// 첫 번째 DFS: 루트 노드(1)에서 가장 먼 노드 찾기
	pair<int, ll> first = dfs(1, -1, 0);

	// 두 번째 DFS: 노드 A에서 가장 먼 노드 B 찾기
	pair<int, ll> second = dfs(first.first, -1, 0);

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