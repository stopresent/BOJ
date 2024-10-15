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

const int MAX = 5;
int arr[10] = { 0 };

void solve()
{
	for (int i = 0; i < 5; ++i)
	{
		int n;
		cin >> n;
		if (n >= 0 && n <= 9)
			arr[n]++;
		else
			continue;
	}

	int prev = -1;
	for (int i = 0; i <= 9; ++i)
	{
		if (arr[i] & 1)
		{
			prev = i;
			break;
		}
	}

	cout << prev;
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