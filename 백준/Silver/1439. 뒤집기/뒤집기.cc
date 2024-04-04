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
	string str;
	cin >> str;

	int zero_mass = 0, one_mass = 0, before_num = 0;
	before_num = str[0] - '0';
	if (before_num == 1)
		one_mass++;
	else
		zero_mass++;

	for (int i = 1; i < str.size(); ++i)
	{
		if (str[i] == str[i - 1])
			continue;

		if ((str[i] - '0') == 1)
			one_mass++;
		else
			zero_mass++;
	}

	int ret = min(zero_mass, one_mass);
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