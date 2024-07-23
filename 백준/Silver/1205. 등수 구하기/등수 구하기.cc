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

int N, num, P;

void solve()
{
	cin >> N >> num >> P;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<>());

	int ret = 1;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > num)
			cnt1++;
		else if (v[i] == num)
			cnt2++;
	}

	if (cnt1 + cnt2 <= P - 1)
		cout << cnt1 + 1;
	else
		cout << -1;
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