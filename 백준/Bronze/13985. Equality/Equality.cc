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
#include <string>

using namespace std;

void solve()
{
	string s;
	getline(cin, s);

	int a = s[0] - '0';
	int b = s[4] - '0';
	int c = s[8] - '0';
	char simbol = s[2];

	if (simbol == '+')
	{
		if (c == a + b)
			cout << "YES";
		else
			cout << "NO";
	}
	else if (simbol == '-')
	{
		if (c == a - b)
			cout << "YES";
		else
			cout << "NO";
	}
	else if (simbol == '/')
	{
		if (c == a / b)
			cout << "YES";
		else
			cout << "NO";
	}
	else if (simbol == '*')
	{
		if (c == a * b)
			cout << "YES";
		else
			cout << "NO";
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