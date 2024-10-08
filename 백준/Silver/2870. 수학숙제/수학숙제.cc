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
vector<string> v;
string s, ret;

void go() 
{
	while (true) 
	{
		if (ret.size() && ret.front() == '0')ret.erase(ret.begin());
		else break;
	}
	if (ret.size() == 0) ret = "0";
	v.push_back(ret);
	ret = "";
}
bool cmp(string a, string b) 
{
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}
void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> s;
		ret = "";
		for (int j = 0; j < s.size(); j++) 
		{
			if (s[j] < 65)ret += s[j];
			else if (ret.size()) go();
		}
		if (ret.size()) go();
	}
	sort(v.begin(), v.end(), cmp);
	for (string i : v)cout << i << "\n";
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