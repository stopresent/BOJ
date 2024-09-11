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
	int a = 0, b = 0;
	int score;
	for (int i = 3; i >= 1; --i)
	{
		cin >> score;
		a += score * i;
	}

	for (int i = 3; i >= 1; --i)
	{
		cin >> score;
		b += score * i;
	}

	if (a > b)
		cout << "A";
	else if (b > a)
		cout << "B";
	else
		cout << "T";
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