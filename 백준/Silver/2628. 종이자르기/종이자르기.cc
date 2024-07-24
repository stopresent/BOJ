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

int n, m;

void solve()
{
	cin >> n >> m;
	int c;
	cin >> c;
	vector<int> garo;
	vector<int> sero;
	garo.push_back(0);
	garo.push_back(m);
	sero.push_back(0);
	sero.push_back(n);

	for (int i = 0; i < c; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0)
			garo.push_back(b);
		else
			sero.push_back(b);
	}

	sort(garo.begin(), garo.end());
	sort(sero.begin(), sero.end());

	int max_width = 0, max_height = 0;
	for (int i = 0; i < garo.size() - 1; ++i)
	{
		int gap = garo[i + 1] - garo[i];
		max_height = max(max_height, gap);
	}

	for (int i = 0; i < sero.size() - 1; ++i)
	{
		int gap = sero[i + 1] - sero[i];
		max_width = max(max_width, gap);
	}

	cout << max_height * max_width;
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