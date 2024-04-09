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

vector<vector<int>> cache(1001, vector<int>(1001));
void LCS()
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

	//cout << cache[str1.length()][str2.length()] << '\n';

	if (cache[str1.length()][str2.length()] == 0)
		return;
	else
	{
		int f = str1.length();
		int s = str2.length();
		// 그 수열을 찾아야됨
		string str;

		// 수열을 역 추적하기
		int idx = str2.size();
		for (int i = str1.size(); i > 0; --i)
		{
			for (int j = idx; j > 0; --j)
			{
				if (cache[i][j] == cache[i - 1][j])
				{
					idx = j;
					break;
				}
				else if (cache[i][j] == cache[i][j - 1])
					continue;
				else
					str = str1[i - 1] + str;
			}
		}

		cout << str;
	}
}

void solve()
{
	LCS();
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