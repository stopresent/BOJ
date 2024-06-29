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

bool compair(pair<int, int> &l, pair<int, int>& r)
{
	return l.second < r.second;
}

void solve()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first;
		cin >> v[i].second;
	}

	long long ans = 0;
	sort(v.begin(), v.end()); 
	int l = v[(n - 1) / 2].first;
	sort(v.begin(), v.end(), compair);
	int r = v[(n - 1) / 2].second;

	for (int i = 0; i < n; ++i)
	{
		ans += abs(v[i].first - l) + abs(v[i].second - r);
	}

	cout << ans;
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