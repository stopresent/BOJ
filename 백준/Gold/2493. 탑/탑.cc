#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>

using namespace std;

void solve()
{
	int n;
	stack<pair<int, int>> s;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int height;
		cin >> height;

		while (s.empty() == false)
		{
			if (height < s.top().second)
			{
				cout << s.top().first << " ";
				break;
			}

			s.pop();
		}

		if (s.empty())
			cout << 0 << " ";

		s.push({ i + 1, height });
	}
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