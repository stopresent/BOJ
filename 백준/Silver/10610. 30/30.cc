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
	string s;
	cin >> s;
	sort(s.begin(), s.end(), greater<>());
	if (s[s.length() - 1] != '0')
	{
		cout << -1;
	}
	else
	{
		long long sum = 0;
		for (auto o : s)
		{
			sum += o - '0';
		}
		if (sum % 3 == 0)
			cout << s;
		else
			cout << -1;
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