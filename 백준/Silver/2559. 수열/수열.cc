#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<int> seq(n);

	for (int i = 0; i < n; i++)
		cin >> seq[i];

	int res = 0;
	for (int i = 0; i < k; ++i)
		res += seq[i];

	int maxTemp = res;
	for (int i = k; i < n; ++i)
	{
		res -= seq[i - k];
		res += seq[i];

		if (res > maxTemp)
			maxTemp = res;
	}

	cout << maxTemp;
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