#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
int n, m, i, j, x, y, k, sum;

void solve()
{
	cin >> n >> m;
	v = vector<vector<int>>(n + 1, vector<int>(m + 1));

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= m; ++x)
		{
			cin >> v[y][x];
		}
	}

	cin >> k;
	for (int K = 0; K < k; ++K)
	{
		cin >> i >> j >> x >> y;

		sum = 0;
		for (int Y = i; Y <= x; ++Y)
		{
			for (int X = j; X <= y; ++X)
			{
				sum += v[Y][X];
			}
		}

		cout << sum << '\n';
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