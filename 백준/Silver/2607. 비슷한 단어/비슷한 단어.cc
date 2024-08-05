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
vector<int> ch1(26);
string s1;
bool Check(string s2)
{
	vector<int> ch2(26);

	for (int i = 0; i < s2.size(); ++i)
	{
		int temp = s2[i] - 'A';
		ch2[temp]++;
	}

	int s1Size = s1.size();
	int s2Size = s2.size();
	if (abs(s1Size - s2Size) >= 2)
	{
		return false;
	}

	int difCount = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (ch1[i] != ch2[i])
		{
			difCount++;
			int difDist = abs(ch1[i] - ch2[i]);
			if (difDist >= 2)
			{
				return false;
			}
		}
	}

	if (difCount >= 3)
		return false;

	return true;
}

void solve()
{
	int n;
	cin >> n;
	cin >> s1;

	for (int i = 0; i < s1.size(); ++i)
	{
		int temp = s1[i] - 'A';
		ch1[temp]++;
	}

	int ret = 0;
	for (int i = 1; i < n; ++i)
	{
		string str;
		cin >> str;

		bool flag = Check(str);
		if (flag)
			ret++;
	}

	cout << ret;
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