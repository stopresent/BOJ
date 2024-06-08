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
	int n;

	while (true)
	{
		cin >> n;
		if (n == 0)
			break;

		vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());

		bool flag = true;
		for (int i = 0; i < n - 1; ++i)
		{
			if (abs(v[i + 1] - v[i]) > 200)
			{
				flag = false;
				break;
			}
		}

		if (abs(1422 - v[n - 1]) > 100)
			flag = false;

		if (flag == true)
			cout << "POSSIBLE" << '\n';
		else
			cout << "IMPOSSIBLE" << '\n';
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