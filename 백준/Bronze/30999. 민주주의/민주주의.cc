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

void solve()
{
	cin >> n >> m;

	int cnt = 0, res = 0;
	string str;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		cnt = 0;
		for (int j = 0; j < str.size(); ++j)
		{
			if (str[j] == 'O')
				cnt++;
		}

		if (cnt > str.size() / 2)
			res++;
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