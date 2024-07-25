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

bool IsPrime(int x)
{
	for (int i = 2; i * i < x; ++i)
	{
		if (x % i == 0)
			return false;
	}

	return true;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	m *= 1000000;
	m += n;

	if (IsPrime(n) && IsPrime(m))
		cout << "Yes";
	else
		cout << "No";
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