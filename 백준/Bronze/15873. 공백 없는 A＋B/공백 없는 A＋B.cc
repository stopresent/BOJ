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

	if (str.size() == 2)
	{
		int a = str[0] - '0';
		int b = str[1] - '0';
		cout << a + b;
	}
	else if (str.size() == 3)
	{
		if (str[1] == '0')
		{
			int b = str[2] - '0';
			cout << 10 + b;
		}
		else
		{
			int a = str[0] - '0';
			cout << a + 10;
		}
	}
	else if (str.size() == 4)
	{
		cout << 20;
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