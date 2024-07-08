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
	int s, k, h;
	cin >> s >> k >> h;

	if (s + k + h >= 100)
	{
		cout << "OK";
		return;
	}
	int smallest = INT_MAX;
	smallest = min(s, smallest);
	smallest = min(h, smallest);
	smallest = min(k, smallest);

	if (smallest == s)
	{
		cout << "Soongsil";
		return;
	}
	else if (smallest == h)
	{
		cout << "Hanyang";
		return;
	}
	else
	{
		cout << "Korea";
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