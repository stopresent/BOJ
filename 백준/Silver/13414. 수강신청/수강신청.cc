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

int k, l;
unordered_map<string, int> um;

void solve()
{
	cin >> k >> l;
	vector<string> v;

	for (int i = 0; i < l; ++i)
	{
		string num;
		cin >> num;
		v.push_back(num);
		um[num]++;
	}

	int cnt = 0;
	vector<string> ans;
	for (int i = 0; i < v.size(); ++i)
	{
		string num = v[i];
		if (um[num] == 1)
		{
			um[num]--;
			ans.push_back(num);
			cnt++;
			if (cnt == k)
				break;
		}
		else
		{
			um[num]--;
		}
	}

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << '\n';
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