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
	while (cin >> n)
	{
		int ret = 0;
		for (int i = 1; i <= n; ++i)
		{
			ret = ret * 10 + 1;
			ret %= n;
			if (ret == 0)
			{
				cout << i << '\n';
				break;
			}
		}
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