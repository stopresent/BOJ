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

int n, k;
int cache[101][100001];
int w[101];
int v[101];

void solve()
{
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j - w[i] >= 0)
				cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - w[i]] + v[i]);
			else
				cache[i][j] = cache[i - 1][j];
		}
	}

	cout << cache[n][k];
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