#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int MAX = 1234567890;
int n, s, res = MAX, mid = MAX;
vector<int> seq;
void setting()
{
	cin >> n >> s;
	seq = vector<int>(n + 1);
	for (int i = 0; i < n; ++i)
	{
		cin >> seq[i];
	}
}

void solve()
{
	int lt = 0, rt = 0, L = 1;
	int temp = seq[0];

	while (rt < n && lt < n)
	{
		if (temp < s) 
		{
			rt++;
			temp += seq[rt];
		}
		else {
			if ((rt - lt) + 1 < mid)
				mid = (rt - lt) + 1;
			temp -= seq[lt];
			lt++;
		}
	}

	if (mid == MAX)
		cout << 0;
	else
		cout << mid;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	setting();
	solve();

	return 0;
}