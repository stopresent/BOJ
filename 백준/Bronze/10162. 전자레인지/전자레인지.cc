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
	int T;
	cin >> T;

	if (T % 10 != 0)
	{
		cout << -1;
		return;
	}

	int ret = 0;
	int temp = T / (60 * 5);
	cout << temp << " ";
	ret += temp;
	T -= temp * (60 * 5);
	temp = T / 60;
	cout << temp << " ";
	ret += temp;
	T -= temp * 60;
	temp = T / 10;
	cout << temp << " ";
	ret += temp;

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