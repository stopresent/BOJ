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
#include <string>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "*";
		}
		cout << '\n';
	}

	for (int i = n - 1; i >= 1; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "*";
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