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

void solve()
{
	vector<pair<int, int>> v;
	for (int i = 0; i < 8; ++i)
	{
		int input;
		cin >> input;
		v.push_back({input, i + 1});
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	cout << v[0].first + v[1].first + v[2].first + v[3].first + v[4].first << '\n';

	vector<int> ans;
	for (int i = 0; i < 5; ++i)
	{
		ans.push_back(v[i].second);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < 5; ++i)
	{
		cout << ans[i] << " ";
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