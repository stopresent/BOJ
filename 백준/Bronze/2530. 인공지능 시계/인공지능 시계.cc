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
	int h, m, s, totalTime;
	cin >> h >> m >> s >> totalTime;
	int sum = h * 3600 + m * 60 + s + totalTime;

	sum = sum % (3600 * 24);
	h = sum / 3600;
	if (h != 0)
		sum = sum % (h * 3600);
	m = sum / 60;
	if (m != 0)
		sum = sum % (m * 60);
	s = sum;

	cout << h << " " << m << " " << s;
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