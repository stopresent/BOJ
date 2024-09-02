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
	if (a >= 3 && b <= 4)
	{
		cout << "TroyMartian" << '\n';
	}
	if (a <= 6 && b >= 2)
	{
		cout << "VladSaturnian" << '\n';
	}
	if (a <= 2 && b <= 3)
	{
		cout << "GraemeMercurian" << '\n';
	}
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