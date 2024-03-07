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

// 랜선 자르기
// 이분탐색

int K, N;
vector<int> seq;

void solve()
{
	cin >> K >> N;
	seq = vector<int>(K);

	for (int i = 0; i < K; ++i)
	{
		cin >> seq[i];
	}

	sort(seq.begin(), seq.end());

	long long left = 1, right = seq[K - 1], mid, post = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 0; i < K; ++i)
		{
			cnt += (seq[i] / mid);
		}

		if (cnt >= N)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << right;
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