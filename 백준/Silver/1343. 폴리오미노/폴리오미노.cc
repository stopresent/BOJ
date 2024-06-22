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
	string str;
	cin >> str;
	string ret = "";
	int xCnt = 0, pointCnt = 0;;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'X')
		{
			if (pointCnt != 0)
			{
				for (int j = 0; j < pointCnt; ++j)
				{
					ret += '.';
				}
				pointCnt = 0;
			}
			xCnt++;

		}
		else
		{
			if (xCnt != 0)
			{
				int A = xCnt / 4;
				for (int j = 0; j < A; ++j)
				{
					ret += "AAAA";
				}
				xCnt = xCnt % 4;
				int B = xCnt / 2;
				for (int j = 0; j < B; ++j)
				{
					ret += "BB";
				}

				if (xCnt % 2 == 1)
				{
					cout << -1;
					return;
				}

				xCnt = 0;
			}

			pointCnt++;
		}
	}

	if (pointCnt != 0)
	{
		for (int j = 0; j < pointCnt; ++j)
		{
			ret += '.';
		}
		pointCnt = 0;
	}

	if (xCnt != 0)
	{
		int A = xCnt / 4;
		for (int j = 0; j < A; ++j)
		{
			ret += "AAAA";
		}
		xCnt = xCnt % 4;
		int B = xCnt / 2;
		for (int j = 0; j < B; ++j)
		{
			ret += "BB";
		}

		if (xCnt % 2 == 1)
		{
			cout << -1;
			return;
		}

		xCnt = 0;
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