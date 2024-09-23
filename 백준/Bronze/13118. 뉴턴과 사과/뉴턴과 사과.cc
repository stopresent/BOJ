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

int a, b, c, d, x, y, r;

void solve()
{
	cin >> a >> b >> c >> d >> x >> y >> r;

	if (a == x)
		cout << 1;
	else if (b == x)
		cout << 2;
	else if (c == x)
		cout << 3;
	else if (d == x)
		cout << 4;
	else
		cout << 0;
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