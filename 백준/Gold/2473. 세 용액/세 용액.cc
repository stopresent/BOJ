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

int n;
long long ret = 3000000001;
long long seq[5010];
long long ans[4];

void solve()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> seq[i];
	}
	sort(seq, seq + n);

	for (int i = 0; i < n - 2; ++i)
	{
		long long start = i + 1;
		long long end = n - 1;

		while (start < end)
		{
			long long value = seq[i] + seq[start] + seq[end];
			if (abs(value) < ret)
			{
				ret = abs(value);
				ans[1] = seq[i];
				ans[2] = seq[start];
				ans[3] = seq[end];
			}

			if (value < 0)
				start++;
			else
				end--;
		}
	}

	cout << ans[1] << " " << ans[2] << " " << ans[3];
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