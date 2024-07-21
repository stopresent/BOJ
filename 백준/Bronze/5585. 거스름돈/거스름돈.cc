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
	int num;
	cin >> num;
	num = 1000 - num;

	int ret = 0;
	int values[] = {500, 100, 50, 10, 5, 1};

	for (int i = 0; i < 6; ++i)
	{
		int ci = num / values[i];
		ret += ci;
		num -= ci * values[i];
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