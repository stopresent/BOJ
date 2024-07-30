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
	if (m == 1 || m == 2)
	{
		cout << "NEWBIE!";
		return;
	}

	if (m > n)
	{
		cout << "TLE!";
		return;
	}
	else
	{
		cout << "OLDBIE!";
		return;
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