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
#include <string>

using namespace std;


void solve()
{
	while (true)
	{
		string s;
		getline(cin, s);
		if (s == ".")
			break;

		bool flag = true;
		stack<char> st;

		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				st.push('(');
			}
			else if (s[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
				{
					flag = false;
					break;
				}
			}
			else if (s[i] == '[')
			{
				st.push('[');
			}
			else if (s[i] == ']')
			{
				if (!st.empty() && st.top() == '[')
					st.pop();
				else
				{
					flag = false;
					break;
				}
			}
		}

		if (st.empty() && flag)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
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