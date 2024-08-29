#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <string>

using namespace std;

void solve()
{
	string s;
	getline(cin, s);

	int gap = 13;
	string ret = "";

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] <= 'M')
				s[i] += gap;
			else
				s[i] = 'A' + 13 - ('Z' - s[i]) - 1;
			
			ret += s[i];
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i] <= 'm')
				s[i] += gap;
			else
				s[i] = 'a' + 13 - ('z' - s[i]) - 1;

			ret += s[i];
		}
		else
			ret += s[i];
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