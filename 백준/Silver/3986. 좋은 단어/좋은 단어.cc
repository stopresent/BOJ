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
#include <stack>

using namespace std;

void solve()
{
	int n, ret = 0;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		stack<char> stk;
		for (char a : s)
			if (stk.size() && stk.top() == a) stk.pop();
			else stk.push(a);

		if (stk.size() == 0)
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