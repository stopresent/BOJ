#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cur = 64, res = 1, sum = 0;

void solve()
{
	cin >> n;

	int temp = cur;
	sum = cur;

	while (true)
	{
		if (sum > n)
		{
			cur /= 2;
			sum -= cur;
		}
		else if (sum == n)
		{
			break;
		}
		else if (sum < n)
		{
			cur /= 2;
			sum += cur;

			res++;
		}
	}

	cout << res;
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