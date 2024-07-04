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
	string str;
	cin >> str;

	stack<char> s;
	int ret = 0, temp = 1;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
			temp *= 2;
		}
		else if (str[i] == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				ret = 0;
				break;
			}
			if (str[i - 1] == '(')
			{
				ret += temp;
			}

			s.pop();
			temp /= 2;
		}
		else if (str[i] == '[')
		{
			s.push(str[i]);
			temp *= 3;
		}
		else if (str[i] == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				ret = 0;
				break;
			}
			if (str[i - 1] == '[')
			{
				ret += temp;
			}

			s.pop();
			temp /= 3;
		}
	}

	if (s.empty() == false)
		ret = 0;

	cout << ret << '\n';
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