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

vector<int> v(30);

void solve()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		v[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; ++i)
	{
		cout << v[i] << " ";
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