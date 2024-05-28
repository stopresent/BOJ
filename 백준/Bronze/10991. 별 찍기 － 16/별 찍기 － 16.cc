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
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n - 1; j++)
		{
			cout << " ";
		}
		for (int j = 1; j <= i * 2 - 1; j++)
		{
			if (j % 2 == 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
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