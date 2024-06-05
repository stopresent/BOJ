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

map<string, int> board;

void solve()
{
	board["Poblano"] = 1500;
	board["Mirasol"] = 6000;
	board["Serrano"] = 15500;
	board["Cayenne"] = 40000;
	board["Thai"] = 75000;
	board["Habanero"] = 125000;

	int n;
	cin >> n;
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		ret += board[temp];
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