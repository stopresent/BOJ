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

/// <summary>
/// A+: 4.3, A0: 4.0, A-: 3.7
//
//B + : 3.3, B0 : 3.0, B - : 2.7
//
//C + : 2.3, C0 : 2.0, C - : 1.7
//
//D + : 1.3, D0 : 1.0, D - : 0.7
//
//F : 0.0
/// </summary>



void solve()
{
	string str;
	cin >> str;

	float ret = 0;

	if (str[0] == 'A')
		ret += 4;
	else if (str[0] == 'B')
		ret += 3;
	else if (str[0] == 'C')
		ret += 2;
	else if (str[0] == 'D')
		ret += 1;

	if (str[1] == '+')
		ret += 0.3;
	else if (str[1] == 0)
		ret += 0;
	else if (str[1] == '-')
		ret -= 0.3;

	cout << fixed;
	cout.precision(1);
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