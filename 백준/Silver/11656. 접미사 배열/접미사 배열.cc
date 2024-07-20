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
	string temp;
	vector<string> v;

	cin >> s;

	for (int i = 0; i < s.length(); ++i) 
	{
		temp = s.substr(i, s.length() - i);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i) 
	{
		cout << v[i] << endl;
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