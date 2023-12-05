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
	string str;
	cin >> str;

	int n;
	cin >> n;

	char c;
	int first, second;
	for (int i = 0; i < n; ++i)
	{
		cin >> c >> first >> second;

		int res = 0;
		for (int i = first; i <= second; ++i)
		{
			if (str[i] == c)
				res++;
		}

		cout << res << '\n';
	}
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