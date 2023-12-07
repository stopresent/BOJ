#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> cache(1001, vector<int>(1001));

void solve()
{
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); ++i)
	{
		for (int j = 1; j <= str2.length(); ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				cache[i][j] = cache[i - 1][j - 1] + 1;
			}
			else
			{
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
			}
		}
	}

	cout << cache[str1.length()][str2.length()];
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