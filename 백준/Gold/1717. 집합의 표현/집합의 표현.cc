#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;

int n, m;
int parent[10000010];

int Find(int a)
{
	if (a == parent[a])
		return a;

	return parent[a] = Find(parent[a]);
}

void Merge(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b)
		return;

	parent[a] = parent[b];
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 1; i <= m; ++i)
	{
		int cal, a, b;
		cin >> cal >> a >> b;
		if (cal == 0)
		{
			Merge(a, b);
		}
		else
		{
			a = Find(a);
			b = Find(b);
			if (a == b)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
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