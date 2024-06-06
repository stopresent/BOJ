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
	int a1, a0, c1, c2, n0;

	cin >> a1 >> a0 >> c1 >> c2 >> n0;
	if (c1 <= a1 && a1 <= c2 && c1 * n0 <= a1 * n0 + a0 && a1 * n0 + a0 <= c2 * n0) 
		cout << 1;
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