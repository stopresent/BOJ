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
	string str;
	cin >> str;

	string ret = "";
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'a')
		{
			ret += str[i] - ('a' - 'A');
		}
		else
		{
			ret += str[i] + ('a' - 'A');
		}
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