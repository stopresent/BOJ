#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string str;
int res = 0;
stack<char> s;
void solve()
{
	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else
		{
			if (str[i - 1] == '(')
			{
				s.pop();
				res += s.size();
			}
			else
			{
				s.pop();
				res++;
			}
		}
	}

	cout << res;
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