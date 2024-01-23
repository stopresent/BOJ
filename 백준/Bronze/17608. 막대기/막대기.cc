#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, res = 0;
vector<int> seq;

void solve()
{
	cin >> n;
	seq = vector<int>(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> seq[i];
	}

	int num = -123456789;
	for (int i = seq.size() - 1; i >= 0; --i)
	{
		if (seq[i] > num)
		{
			res++;
			num = seq[i];
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