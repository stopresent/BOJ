#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int x, y;
string str[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void solve()
{
	cin >> x >> y;

	int temp = 0;
	for (int i = 0; i < x - 1; ++i)
	{
		temp += days[i];
	}

	temp += y;

	temp %= 7;

	cout << str[(temp + 6) % 7];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}