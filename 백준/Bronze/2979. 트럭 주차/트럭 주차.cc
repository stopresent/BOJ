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
	int a, b, c;
	cin >> a >> b >> c;
	int ret = 0;

	vector<int> v(110);
	for (int i = 0; i < 3; ++i)
	{
		int inTime, outTime;
		cin >> inTime >> outTime;

		for (int j = inTime - 1; j < outTime - 1; ++j)
			v[j]++;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == 1)
			ret += a * 1;
		else if (v[i] == 2)
			ret += b * 2;
		else if (v[i] == 3)
			ret += c * 3;
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