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

int n, m, res = 0;
int v[101], v2[101];
void solve()
{
	cin >> n >> m;
	int len, vel, sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> len >> vel;
		for (int j = sum; j < sum + len; ++j)
		{
			v[j] = vel;
		}
		sum += len;
	}

	sum = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> len >> vel;
		for (int j = sum; j < sum + len; ++j)
		{
			v2[j] = vel;
		}
		sum += len;
	}
	
	for (int i = 0; i < 100; ++i)
	{
		if (v[i] < v2[i])
		{
			res = max(res, v2[i] - v[i]);
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