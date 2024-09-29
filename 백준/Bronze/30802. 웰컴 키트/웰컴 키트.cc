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

int n, s, m, l, xl, xxl, xxxl, t, p, ret = 0;

void solve()
{
	cin >> n >> s >> m >> l >> xl >> xxl >> xxxl >> t >> p;
	ret += (s % t == 0 ? s / t : s / t + 1);
	ret += (m % t == 0 ? m / t : m / t + 1);
	ret += (l % t == 0 ? l / t : l / t + 1);
	ret += (xl % t == 0 ? xl / t : xl / t + 1);
	ret += (xxl % t == 0 ? xxl / t : xxl / t + 1);
	ret += (xxxl % t == 0 ? xxxl / t : xxxl / t + 1);
	cout << ret << '\n';
	cout << n / p << " " << n % p;
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