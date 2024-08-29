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
	int y, m, d, cy, cm, cd;
	cin >> y >> m >> d >> cy >> cm >> cd;

	if (m == cm)
	{
		if (cd >= d)
			cout << cy - y << '\n';
		else
			cout << cy - y - 1 << '\n';
	}
	else if (cm > m)
	{
		cout << cy - y << '\n';
	}
	else
	{
		cout << cy - y - 1 << '\n';
	}

	cout << cy - y + 1 << '\n';
	cout << cy - y << '\n';
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