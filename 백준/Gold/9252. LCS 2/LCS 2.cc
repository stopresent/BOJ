#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// LCS (Longest Common Subsequence) 2

// ACAYKP
// CAPCAK
// 위의 경우 정답은
// ACAK

// dp의 의미
// dp[i] = 
int dp;
vector<int> cache1, seq;
vector<vector<int>> cache2(1001, vector<int>(1001));
int LIS(int pos)
{
	int& ret = cache1[pos];
	if (ret != 0)
		return ret;

	ret = 1;

	for (int next = pos + 1; next < seq.size(); ++next)
	{
		if (seq[pos] < seq[next])
			ret = max(ret, 1 + LIS(next));
	}
}

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
				cache2[i][j] = cache2[i - 1][j - 1] + 1;
			}
			else
			{
				cache2[i][j] = max(cache2[i - 1][j], cache2[i][j - 1]);
			}
		}
	}

	cout << cache2[str1.length()][str2.length()] << '\n';

	//// cache상태 확인
	//for (int i = 0; i < 10; ++i)
	//{
	//	for (int j = 0; j < 10; ++j)
	//	{
	//		cout << cache2[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	if (cache2[str1.length()][str2.length()] == 0)
		return;
	else
	{
		int f = str1.length();
		int s = str2.length();
		// 그 수열을 찾아야됨
		string str;

		int idx = str2.size();
		for (int i = str1.size(); i > 0; --i)
		{
			for (int j = idx; j > 0; --j)
			{
				if (cache2[i][j] == cache2[i - 1][j])
				{
					idx = j;
					break;
				}
				else if (cache2[i][j] == cache2[i][j - 1])
					continue;
				else
					str = str1[i - 1] + str;
			}
		}

		cout << str;

		//while (true)
		//{
		//	if (cache2[f][s] == 0)
		//		break;

		//	if (cache2[f][s - 1] == 0 && cache2[f - 1][s] == 0)
		//	{
		//		str.push_back(str2[s - 1]);
		//		break;
		//	}
		//	else if (cache2[f][s] != cache2[f - 1][s] && cache2[f - 1][s] != 0)
		//	{
		//		str.push_back(str2[s - 1]);

		//		f--;
		//		s--;
		//	}
		//	else if (cache2[f - 1][s] == 0 && cache2[f][s - 1] != 0)
		//	{
		//		s--;
		//	}
		//	else
		//		f--;
		//}

		//reverse(str.begin(), str.end());

		//cout << str;
	}

}

void solve()
{
	LCS();
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