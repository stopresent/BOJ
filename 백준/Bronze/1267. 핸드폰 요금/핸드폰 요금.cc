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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i)
	{
		sum1 += (v[i] / 30 + 1) * 10;
		sum2 += (v[i] / 60 + 1) * 15;
	}

	if (sum1 < sum2)
	{
		cout << "Y" << " " << sum1 << '\n';
	}
	else if (sum2 < sum1)
	{
		cout << "M" << " " << sum2 << '\n';
	}
	else
	{
		cout << "Y"<< " M " << sum2 << '\n';
	}
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