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

// 행성 터널
// kruskal 문제

struct Edge
{
	int cost;
	int u, v;
	bool operator<(Edge& other)
	{
		return cost < other.cost;
	}
};

const int MAX = 111111;
int unf[MAX];
int n;
vector<pair<int, int>> v[3];
vector<Edge> planet;

int Find(int u)
{
	if (u == unf[u])
		return u;
	return unf[u] = Find(unf[u]);
}

void Merge(int u, int v)
{
	u = Find(u);
	v = Find(v);

	if (u == v)
		return;

	unf[u] = v;
}

void solve()
{
	cin >> n;
	int x, y, z;

	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y >> z;
		v[0].push_back({ x, i });
		v[1].push_back({ y, i });
		v[2].push_back({ z, i });
		unf[i] = i;
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());

	for (int i = 0; i < n - 1; ++i)
	{
		planet.push_back({ abs(v[0][i].first - v[0][i + 1].first), v[0][i].second, v[0][i + 1].second});
		planet.push_back({ abs(v[1][i].first - v[1][i + 1].first), v[1][i].second, v[1][i + 1].second});
		planet.push_back({ abs(v[2][i].first - v[2][i + 1].first), v[2][i].second, v[2][i + 1].second});
	}

	sort(planet.begin(), planet.end());

	int ret = 0;
	for (int i = 0; i < planet.size(); ++i)
	{
		if (Find(planet[i].u) == Find(planet[i].v))
			continue;

		ret += planet[i].cost;
		Merge(planet[i].u, planet[i].v);
	}

	cout << ret;
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