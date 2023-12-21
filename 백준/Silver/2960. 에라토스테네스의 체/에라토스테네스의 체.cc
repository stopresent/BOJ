#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, cnt = 0;

int primes[1001] = { 0, };

void solve()
{
	cin >> n >> k;

	for (int i = 2; i <= n; ++i)
	{
		primes[i] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = i; j <= n; j += i)
		{
			if (primes[j] != 0)
			{
				primes[j] = 0;
				cnt++;
				if (cnt == k)
				{
					cout << j << '\n';
					return;
				}
			}
		}
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