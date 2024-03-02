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

string str;
void solve()
{
	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		if (i % 10 == 0 && i != 0)
			cout << '\n';
		cout << str[i];

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