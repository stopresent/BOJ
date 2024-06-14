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
	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		vector<int> v1;
		vector<int> v2;

		if (a > b)
		{
			swap(a, b);
		}

		while (a > 0)
		{
			v1.push_back(a);
			a /= 2;
		}

		while (b > 0)
		{
			v2.push_back(b);
			b /= 2;
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int ans = 1;
		for (int i = 0; i < v1.size(); ++i)
		{
			if (v1[i] == v2[i])
				ans = v1[i];
		}

		cout << ans * 10 << '\n';
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