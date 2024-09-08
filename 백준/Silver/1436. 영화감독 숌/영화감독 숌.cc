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

int n;

bool check(int x)
{
	string s = "";
	while (x > 0)
	{
		int temp = x % 10;
		s = s + (char)(temp + '0');
		x /= 10;
	}

	//cout << s << endl;

	for (int i = 0; i < s.size() - 2; ++i)
	{
		if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6')
			return true;
	}

	return false;
}

void solve()
{
	cin >> n;

	int num = 660;
	int cnt = 0;
	while (true)
	{
		if (check(num))
			cnt++;

		if (cnt == n)
		{
			cout << num;
			break;
		}

		num++;
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