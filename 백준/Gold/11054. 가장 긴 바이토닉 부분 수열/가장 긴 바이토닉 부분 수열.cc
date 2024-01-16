#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> cache, rCache, seq;
void setting()
{
	cin >> n;
	seq = vector<int>(n + 1);
	cache = vector<int>(n + 1);
	rCache = vector<int>(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> seq[i];
	}
}

void solve()
{
	for (int i = 1; i <= n; ++i)
	{
		cache[i] = 1;
		for (int j = 1; j <= i; ++j)
		{
			if (seq[j] < seq[i] && cache[i] < cache[j] + 1)
				cache[i] = cache[j] + 1;
		}
	}

	for (int i = n; i >= 1; --i)
	{
		rCache[i] = 1;
		for (int j = n; j >= i; --j)
		{
			if (seq[i] > seq[j] && rCache[j] + 1 > rCache[i])
				rCache[i] = rCache[j] + 1;
		}
	}

	int ret = 0;
	for (int i = 0; i <= n; ++i)
	{
		if (ret < cache[i] + rCache[i] - 1)
			ret = cache[i] + rCache[i] - 1;
	}

	cout << ret;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	setting();
	solve();

	return 0;
}