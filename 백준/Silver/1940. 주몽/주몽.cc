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
#include <unordered_map>

using namespace std;

int n, m, ret = 0;

void solve()
{
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		int idx;
		cin >> idx;
		v[i] = idx;
	}

	sort(v.begin(), v.end());
	int p1 = 0, p2 = v.size() - 1;

	while (p1 < p2)
	{
		int a = v[p1];
		int b = v[p2];
		if (a + b == m)
		{
			ret++;
			p1++;
			p2--;
		}
		else if (a + b > m)
		{
			p2--;
		}
		else if (a + b < m)
		{
			p1++;
		}
	}

	cout << ret;
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