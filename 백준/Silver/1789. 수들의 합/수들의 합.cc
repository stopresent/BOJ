#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long s, sum = 0;
int num = 1, cnt = 0;
void solve()
{
	cin >> s;

	while (true)
	{
		sum += num;
		cnt++;

		if (sum > s)
		{
			cnt--;
			break;
		}

		num++;
	}

	cout << cnt;
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