#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, dir, len, large, small, res;
pair<int, int> cache[12];

void solve()
{
	cin >> n;

	for (int i = 0; i < 6; ++i)
	{
		cin >> dir >> len;
		cache[i] = cache[i + 6] = { dir, len };
	}

	for (int i = 3; i < 12; ++i)
	{
		if (cache[i].first == cache[i - 2].first && cache[i - 1].first == cache[i - 3].first)
		{
			large = cache[i + 1].second * cache[i + 2].second;
			small = cache[i - 1].second * cache[i - 2].second;

			break;
		}
	}

	res = n * (large - small);
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