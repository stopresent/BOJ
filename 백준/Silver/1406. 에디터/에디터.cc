#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

string str;
int n;
list<char> li;
list<char>::iterator cursor, s;

void solve()
{
	cin >> str >> n;

	li.push_back('N');

	for (int i = 0; i < str.size(); ++i)
	{
		li.push_back(str[i]);
	}

	cursor = li.begin();
	s = li.begin();

	for (int i = 0; i < str.size(); ++i)
	{
		cursor++;
	}

	char temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;

		if (temp == 'L')
		{
			// 맨 앞이면 무시
			if (cursor != li.begin())
				--cursor;
		}
		else if (temp == 'D')
		{
			// 맨 뒤면 무시
			if (cursor != --li.end())
				cursor++;
		}
		else if (temp == 'B')
		{
			// 커서가 맨앞이면 무시됨.
			if (cursor != s)
			{
				list<char>::iterator t = cursor--;
				li.erase(t);
			}
		}
		else if (temp == 'P')
		{
			char newChar;
			cin >> newChar;

			li.insert(++cursor, newChar);
			cursor--;
		}
	}

	cursor = li.begin();
	for (int i = 0; i < li.size() - 1; ++i)
	{
		cout << *++cursor;
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