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
	int a, b;
	cin >> a >> b;

	int a_1 = (a - 1) / 4, a_2 = (a - 1) % 4;
	int b_1 = (b - 1) / 4, b_2 = (b - 1) % 4;
	int ret = abs(a_1 - b_1) + abs(a_2 - b_2);
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