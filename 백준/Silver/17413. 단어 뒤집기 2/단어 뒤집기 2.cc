#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

//string str;
string str;
string res;
stack<char> s;

void print(stack<char>& s)
{
	while (s.empty() == false)
	{
		cout << s.top();
		s.pop();
	}
}

void solve()
{
	getline(cin, str);
	
	bool isIn = false;

	for (char ch : str)
	{
		if (ch == '<')
		{
			print(s);
			isIn = true;
			cout << ch;
		}
		else if (ch == '>')
		{
			isIn = false;
			cout << ch;
		}
		else if (isIn)
		{
			cout << ch;
		}
		else
		{
			if (ch == ' ')
			{
				print(s);
				cout << ch;
			}
			else
			{
				s.push(ch);
			}
		}
	}

	print(s);
	
	cout << res << '\n';
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