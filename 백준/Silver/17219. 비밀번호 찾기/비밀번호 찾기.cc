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
#include <map>

using namespace std;

map<string, string> cache;

void solve()
{
	int n, m;
	cin >> n >> m;
	string adrress, passWord;
	for (int i = 0; i < n; ++i)
	{
		cin >> adrress >> passWord;
		cache[adrress] = passWord;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> adrress;
		cout << cache[adrress] << '\n';
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