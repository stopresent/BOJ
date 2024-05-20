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

void solve()
{
	while (true)
	{
		string str;
		cin >> str;
		if (str == "0")
			break;

		int sum = 1;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == '1')
			{
				sum += 2;
			}
			else if (str[i] == '0')
			{
				sum += 4;
			}
			else
			{
				sum += 3;
			}

			sum += 1;
		}

		cout << sum << '\n';
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