#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int n;

void solve()
{
	cin >> n;

	vec = vector<int>(21);

	while (n > 0)
	{
		string str;
		cin >> str;

		if (str == "add")
		{
			int temp;
			cin >> temp;
			if (vec[temp] == 0)
				vec[temp]++;
		}
		else if (str == "remove")
		{
			int temp;
			cin >> temp;
			if (vec[temp] == 1)
				vec[temp]--;
		}
		else if (str == "check")
		{
			int temp;
			cin >> temp;
			if (vec[temp] == 1)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "toggle")
		{
			int temp;
			cin >> temp;
			if (vec[temp] == 1)
				vec[temp]--;
			else
				vec[temp]++;
		}
		else if (str == "all")
		{
			for (int i = 1; i <= 20; ++i)
				vec[i] = 1;
		}
		else if (str == "empty")
		{
			for (int i = 1; i <= 20; ++i)
				vec[i] = 0;
		}

		n--;
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