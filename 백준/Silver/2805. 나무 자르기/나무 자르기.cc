#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> seq;
void solve()
{
	cin >> n >> m;
	seq = vector<int>(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> seq[i];
	}

	sort(seq.begin(), seq.end());

	long long lt = 0, rt = seq[n - 1], res = 0;
	long long mid = (lt + rt) / 2;

	while (lt <= rt)
	{
		mid = (lt + rt) / 2;

		long long temp = 0;
		for (int i = 0; i < n; ++i)
		{
			if (seq[i] <= mid)
				continue;

			temp += seq[i] - mid;
		}

		if (temp > m)
		{
			if (res < mid)
				res = mid;
			lt = mid + 1;
		}
		else if (temp < m)
		{
			rt = mid - 1;
		}
		else
		{
			res = mid;
			break;
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