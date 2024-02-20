#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
vector<int> tri(3);

void solve()
{
	while (true)
	{
		for (int i = 0; i < 3; ++i)
		{
			cin >> tri[i];
		}
		sort(tri.begin(), tri.end());

		if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0)
			break;

		int a = tri[0] * tri[0];
		int b = tri[1] * tri[1];
		int c = tri[2] * tri[2];

		if (c == a + b)
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	solve();

	return 0;
}