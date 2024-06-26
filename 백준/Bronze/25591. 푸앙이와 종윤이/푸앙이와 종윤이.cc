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
	int n, m;
	cin >> n >> m;

	int a, b, c, d, q, r;
	a = 100 - n;
	b = 100 - m;
	c = 100 - (a + b);
	d = a * b;
	q = d / 100;
	r = d % 100;

	cout << a << " " << b << " " << c << " " << d << " " << q << " " << r << '\n';
	cout << c + q << " " << r;
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