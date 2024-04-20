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
	int min_bugerr = INT_MAX, min_bv = INT_MAX;

	for (int i = 0; i < 3; ++i)
	{
		int temp;
		cin >> temp;
		min_bugerr = min(min_bugerr, temp);
	}

	for (int i = 0; i < 2; ++i)
	{
		int temp;
		cin >> temp;
		min_bv = min(min_bv, temp);
	}

	cout << min_bugerr + min_bv - 50;
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