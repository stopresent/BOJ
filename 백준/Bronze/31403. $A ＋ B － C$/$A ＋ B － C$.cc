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
	int A, B, C;
	cin >> A >> B >> C;

	cout << A + B - C << '\n';
	vector<int> v;
	while (B > 0)
	{
		v.push_back(B % 10);
		B /= 10;
	}
	while (A > 0)
	{
		v.push_back(A % 10);
		A /= 10;
	}

	reverse(v.begin(), v.end());

	int AplusB = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		AplusB += v[i];
		AplusB *= 10;
	}

	AplusB /= 10;
	
	cout << AplusB - C;
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