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

char consonant[] = { 'a', 'e', 'i', 'o', 'u' };

bool IsConsonant(char c)
{
	for (int i = 0; i < 5; ++i)
	{
		if (consonant[i] == c)
			return true;
	}

	return false;
}

void solve()
{
	string str;
	while (true)
	{
		cin >> str;
		if (str == "end")
			break;

		bool flag1 = false, flag2 = false, flag3 = false;

		// 모음이 하나라도 포함되는지 확인.
		for (int i = 0; i < str.size(); ++i)
		{
			if (flag1)
				break;

			for (int j = 0; j < 5; ++j)
			{
				if (IsConsonant(str[i]))
				{
					flag1 = true;
					break;
				}
			}
		}

		if (flag1 == false)
		{
			cout << "<" << str << "> is not acceptable." << '\n';
			continue;
		}

		// 연속된 자음 및 모음 확인
		if (str.size() >= 3)
		{
			for (int i = 0; i < str.size() - 2; ++i)
			{
				if (IsConsonant(str[i]) && IsConsonant(str[i + 1]) && IsConsonant(str[i + 2]))
				{
					flag2 = true;
					break;
				}
				else if (!IsConsonant(str[i]) && !IsConsonant(str[i + 1]) && !IsConsonant(str[i + 2]))
				{
					flag2 = true;
					break;
				}
			}
		}

		if (flag2 == true)
		{
			cout << "<" << str << "> is not acceptable." << '\n';
			continue;
		}

		// 같은 글자가 연속적으로 나오는지 확인.
		if (str.size() >= 2)
		{
			for (int i = 0; i < str.size() - 1; ++i)
			{
				if (str[i] == 'e' || str[i] == 'o')
					continue;
				if (str[i] == str[i + 1])
				{
					flag3 = true;
					break;
				}
			}
		}

		if (flag3 == true)
		{
			cout << "<" << str << "> is not acceptable." << '\n';
			continue;
		}

		cout << "<" << str << "> is acceptable." << '\n';

	}
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