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
	cin >> n;

	if (n == 1)
	{
		cout << "*";
		return;
	}

	for (int i = 1; i <= 2 * n; ++i)
	{
		if (i % 2 == 0)
			cout << " ";

		if (i % 2 == 1)
		{
			for (int j = 0; j < (n + 1) / 2; ++j)
			{
				cout << "* ";
			}
		}
		else
		{
			for (int j = 0; j < n / 2; ++j)
			{
				cout << "* ";
			}
		}

		cout << '\n';
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