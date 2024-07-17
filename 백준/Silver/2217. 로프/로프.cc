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
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += v[i];
		int temp = sum / (i + 1);
		if (temp <= v[i])
		{
			ret = max(ret, temp * (i + 1));
		}
		else
		{
			ret = max(ret, v[i] * (i + 1));
		}
	}

	cout << ret;
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