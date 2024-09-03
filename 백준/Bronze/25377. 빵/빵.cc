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
int a, b;

void solve()
{
	cin >> n;
	bool flag = false;
	int ret = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		if (a <= b)
		{
			flag = true;
			ret = min(ret, b);
		}
	}

	if (flag == false)
		ret = -1;

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