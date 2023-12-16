#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> cache;

void solve()
{
	cin >> N;
	cache = vector<int>(N + 1);

	cache[1] = 0;
	for (int i = 2; i <= N; ++i)
	{
		cache[i] = cache[i - 1] + 1;
		if (!(i % 3))
			cache[i] = min(cache[i], cache[i / 3] + 1);
		if (!(i % 2))
			cache[i] = min(cache[i], cache[i / 2] + 1);
	}
	
	cout << cache[N];
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