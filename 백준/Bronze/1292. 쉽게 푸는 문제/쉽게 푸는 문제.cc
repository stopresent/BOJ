#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, res = 0;
void solve()
{
	cin >> a >> b;
	vector<int> seq;

	seq.push_back(0);

	for (int i = 1; i <= b; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			seq.push_back(i);
		}
	}

	for (int i = a; i <= b; ++i)
	{
		res += seq[i];
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