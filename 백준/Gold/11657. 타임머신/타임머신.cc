#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Edge
{
	int s, e, val;
};

const long long MAX = 1234567890;
int n, m;
long long dist[1000];

void solve()
{
	cin >> n >> m;
	vector<Edge> edges;
	int a, b, c;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b >> c;
		edges.push_back({ a, b, c });
	}

	for (int i = 1; i <= n; ++i)
		dist[i] = MAX;
	dist[1] = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < edges.size(); ++j)
		{
			int s = edges[j].s;
			int e = edges[j].e;
			int w = edges[j].val;
			if (dist[s] != MAX && dist[s] + w < dist[e])
				dist[e] = dist[s] + w;
		}
	}

	for (int i = 0; i < edges.size(); ++i)
	{
		int u = edges[i].s;
		int v = edges[i].e;
		int w = edges[i].val;
		if (dist[u] != MAX && dist[u] + w < dist[v])
		{
			cout << -1 << '\n';
			return;
			//dist[v] = MAX;
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		if (dist[i] == MAX)
			cout << -1 << '\n';
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