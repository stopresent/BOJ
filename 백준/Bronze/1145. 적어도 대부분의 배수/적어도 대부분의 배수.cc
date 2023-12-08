#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

void solve()
{
	vector<int> seq(5);
	int min = -1;
	for (int i = 0; i < 5; ++i)
	{
		cin >> seq[i];
		if (min == -1 || min > seq[i])
			min = seq[i];
	}

	int cnt = 0;
	int t = min - 1;
	while (cnt < 3)
	{
		t++;
		cnt = 0;
		for (int i = 0; i < 5; ++i)
			if (t % seq[i] == 0)
				cnt++;
	}

	cout << t;
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