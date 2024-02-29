#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int is[11], os[11];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> is[i];
	}

	for (int i = n; i >= 1; --i)
	{
		int val = is[i];
		for (int j = i; j < i + val; ++j)
		{
			os[j] = os[j + 1];
		}
		os[i + val] = i;
	}

	for (int i = 1; i < 11; ++i)
	{
		if (os[i] == 0)
			break;
		cout << os[i] << " ";
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