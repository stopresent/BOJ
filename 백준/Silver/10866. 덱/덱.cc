#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n;
deque<int> d;

void solve()
{
	cin >> n;

	while (n > 0)
	{
		string input;
		cin >> input;
		if (input == "push_front")
		{
			int temp;
			cin >> temp;
			d.push_front(temp);
		}
		else if (input == "push_back")
		{
			int temp;
			cin >> temp;
			d.push_back(temp);
		}
		else if (input == "pop_front")
		{
			if (d.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				int front = d.front();
				cout << front << '\n';
				d.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (d.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				int back = d.back();
				cout << back << '\n';
				d.pop_back();
			}
		}
		else if (input == "size")
		{
			cout << d.size() << '\n';
		}
		else if (input == "empty")
		{
			if (d.size() == 0)
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (input == "front")
		{
			if (d.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << d.front() << '\n';
			}
		}
		else if (input == "back")
		{
			if (d.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << d.back() << '\n';
			}
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