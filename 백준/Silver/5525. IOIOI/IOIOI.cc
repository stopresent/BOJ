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

int n, m, ret = 0;
string s;

void solve()
{
	cin >> n >> m >> s;
	string s1 = "";
	for (int i = 0; i < n; ++i)
		s1 += "IO";
	s1 += "I";
	
	for (int i = 0; i < s.size() - (2 * n); ++i)
	{
		//cout << s.substr(i, 2 * n + 1) << endl;
		if (s.substr(i, 2 * n + 1) == s1)
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