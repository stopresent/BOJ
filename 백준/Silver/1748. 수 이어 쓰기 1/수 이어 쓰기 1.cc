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

int N, res = 0;

int digit_count(int num)
{
	int res = 0;

	while (num > 0)
	{
		num /= 10;
		res++;
	}

	return res;
}

void solve()
{
	cin >> N;
	int temp = digit_count(N);

	for (int i = 1; i < temp; ++i)
	{
		res += 9 * pow(10, i - 1) * i;
	}

	int num = N - (pow(10, temp - 1)) + 1;
	num *= temp;

	res += num;
	cout << res << '\n';
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