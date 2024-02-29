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

int unf[100001];
int v, e;

struct Edge
{
	int v1, v2, value;
	Edge(int a, int b, int c)
	{
		v1 = a;
		v2 = b;
		value = c;
	}

	bool operator<(const Edge& other) const
	{
		return value < other.value;
	}
};

int Find(int v)
{
	if (v == unf[v])
		return v;
	return unf[v] = Find(unf[v]);
}

void Merge(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b)
		unf[a] = b;
}

void solve()
{
	vector<Edge> edges;
	cin >> v >> e;
	// 각 정점의 부모는 자기이다.
	for (int i = 1; i <= v; ++i)
		unf[i] = i;

	// 그래프 연결정보 입력
	int v1, v2, val;
	for (int i = 1; i <= e; ++i)
	{
		cin >> v1 >> v2 >> val;
		edges.push_back({ v1, v2, val });
	}

	// 비용을 기준으로 정렬하기
	sort(edges.begin(), edges.end());

	// Union & Find 를 이용한 Kruscal 알고리즘
	int res = 0;
	for (int i = 0; i < e; ++i)
	{
		int fa = Find(edges[i].v1);
		int fb = Find(edges[i].v2);

		if (fa != fb)
		{
			res += edges[i].value;
			Merge(edges[i].v1, edges[i].v2);
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