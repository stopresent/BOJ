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

int n;

void solve()
{
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;

		int cnt = 0;
		bool flag = true;
		for (int j = 0; j < s.size(); ++j)
		{
			if (s[j] == '(')
				cnt++;
			else
				cnt--;

			if (cnt < 0)
			{
				flag = false;
				break;
			}
		}

		if (cnt != 0)
			flag = false;

		if (flag)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
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