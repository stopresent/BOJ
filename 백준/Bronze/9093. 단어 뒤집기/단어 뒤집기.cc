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
#include <string>
#include <stack>

using namespace std;

void solve()
{
	string str;

	int n;
	cin >> n;
	cin.ignore();
	stack<char> s;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, str);
		str += ' ';

		for (int j = 0; j < str.size(); ++j)
		{
			if (str[j] == ' ')
			{
				while (s.empty() == false)
				{
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
			else
			{
				s.push(str[j]);
			}
		}

		cout << '\n';
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