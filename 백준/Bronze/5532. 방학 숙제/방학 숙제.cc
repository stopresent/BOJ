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
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int max_day = 0;
	if (a % c == 0)
		max_day = max(max_day, a / c);
	else
		max_day = max(max_day, a / c + 1);

	if (b % d == 0)
		max_day = max(max_day, b / d);
	else
		max_day = max(max_day, b / d + 1);

	cout << l - max_day;
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