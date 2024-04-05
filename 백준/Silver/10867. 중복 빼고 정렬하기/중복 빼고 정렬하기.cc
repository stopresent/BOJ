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
#include <map>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	vector<int> v;
	map<int, int> m;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		if (m[temp] == 0)
		{
			v.push_back(temp);
			m[temp] = 1;
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
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