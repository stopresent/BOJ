#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
void solve()
{
	cin >> n;

	int year, nextYear, temp = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> year;
		temp = 0;

		nextYear = year + 1;

		temp += year % 100;

		if (nextYear % temp == 0)
			cout << "Good" << '\n';
		else
			cout << "Bye" << '\n';
	}
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