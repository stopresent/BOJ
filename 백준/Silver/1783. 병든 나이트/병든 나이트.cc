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
	int n, m;
	cin >> n >> m;

	if (n == 1)
		cout << 1;
	else if (n == 2)
		cout << min(4, (m + 1) / 2);
	else if (m < 7)
		cout << min(4, m);
	else
		cout << m - 2;
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