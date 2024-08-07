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
	vector<int> v(4);
	for (int i = 0; i < 4; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int sub = abs((v[0] + v[3]) - (v[1] + v[2]));
	cout << sub;
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