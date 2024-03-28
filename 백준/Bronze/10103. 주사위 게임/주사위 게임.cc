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
int num1 = 100, num2 = 100;

void solve()
{
	cin >> n;

	int a, b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		if (a == b)
		{
			continue;
		}
		else if (a > b)
		{
			num2 -= a;
		}
		else
		{
			num1 -= b;
		}
	}

	cout << num1 << '\n' << num2;
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