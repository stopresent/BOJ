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

int h, w;
vector<int> rains;
void solve()
{
	cin >> h >> w;
	rains = vector<int>(w);
	for (int i = 0; i < w; ++i)
	{
		cin >> rains[i];
	}

	int res = 0;
	for (int i = 1; i < w - 1; ++i)
	{
		int left = 0, right = 0;
		
		for (int j = 0; j < i; ++j)
		{
			left = max(left, rains[j]);
		}

		for (int j = w - 1; j > i; --j)
		{
			right = max(right, rains[j]);
		}

		res += max(0, min(left, right) - rains[i]);
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