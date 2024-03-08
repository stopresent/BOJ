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

// ACM Craft
// 위상 정렬

int t, n, k;
vector<vector<int>> graph;
vector<int> cost, degree;

void solve()
{
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		graph.clear();
		cost.clear();
		degree.clear();

		cin >> n >> k;
		graph.resize(1010);
		cost = vector<int>(n + 1);
		degree = vector<int>(n + 1);

		for (int j = 0; j < n; ++j)
			cin >> cost[j + 1];

		int u, v;
		for (int j = 0; j < k; ++j)
		{
			cin >> u >> v;
			degree[v]++;
			graph[u].push_back(v);
		}

		int target;
		cin >> target;

		int result[1010];
		queue<int> q;
		for (int j = 1; j <= n; ++j)
		{
			if (degree[j] == 0)
				q.push(j);
			result[j] = cost[j];
		}

		while (q.empty() == false)
		{
			int here = q.front();
			q.pop();

			for (int j = 0; j < graph[here].size(); ++j)
			{
				int next = graph[here][j];
				degree[next]--;

				result[next] = max(result[next], result[here] + cost[next]);

				if (degree[next] == 0)
					q.push(next);
			}
		}

		cout << result[target] << '\n';
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