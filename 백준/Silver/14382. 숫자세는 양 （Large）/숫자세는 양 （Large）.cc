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

int t;
int cache[10];

void get_digit(int num)
{
	while (num > 0)
	{
		cache[num % 10] = 1;
		num /= 10;
	}
}

bool is_end()
{
	for (int i = 0; i < 10; ++i)
	{
		if (cache[i] < 1)
			return false;
	}

	return true;
}

void solve()
{
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int n, cnt = 1, idx = 2;
		cin >> n;

		while (true)
		{
			int temp = n * cnt;
			if (n == n * 2)
			{
				cout << "Case #" << i << ": INSOMNIA" << '\n';
				break;
			}

			get_digit(temp);
			if (is_end() == true)
			{
				cout << "Case #" << i << ": " << temp << '\n';
				break;
			}
			cnt++;
		}

		memset(cache, 0, sizeof(cache));
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