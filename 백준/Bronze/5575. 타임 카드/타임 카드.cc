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
	int h1, m1, s1, h2, m2, s2;
	for (int i = 0; i < 3; ++i)
	{
		cin >> h1 >> m1 >> s1;
		cin >> h2 >> m2 >> s2;

		int h = h2 - h1;
		int m = m2 - m1;
		int s = s2 - s1;
		if (s < 0)
		{
			s += 60;
			m -= 1;
		}

		if (m < 0)
		{
			m += 60;
			h -= 1;
		}

		cout << h << " " << m << " " << s << '\n';
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