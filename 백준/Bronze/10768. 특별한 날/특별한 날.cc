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
	if (a < 2)
	{
		cout << "Before";
	}
	else if (a > 2)
	{
		cout << "After";
	}
	else
	{
		if (b < 18)
			cout << "Before";
		else if (b > 18)
			cout << "After";
		else
			cout << "Special";
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