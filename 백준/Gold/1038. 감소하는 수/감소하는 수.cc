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
#include <queue>

using namespace std;
const long long MAXNUM = 1000000;

void solve()
{
	int num;
	cin >> num;

	if (num > 1022)
	{
		cout << -1;
		return;
	}

	if (num <= 10)
	{
		cout << num;
		return;
	}

	int cnt = 9;
	queue<long long> q;
	for (int i = 1; i < 10; ++i)
		q.push(i);

	while (q.size())
	{
		long long current = q.front();
		q.pop();
		int lastDigit = current % 10;
		for (int i = 0; i < lastDigit; ++i)
		{
			long long next = current * 10 + i;
			// cout << "curr: " << current << " next: " << next;
			// cout << " lastDigit: " << lastDigit << " cnt: " << cnt << '\n';

			cnt++;

			if (cnt == num)
			{
				cout << next;
				return;
			}
			q.push(next);
		}
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