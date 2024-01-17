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

int n;
vector<int> seq;
vector<int> NGE;
stack<int> s;
void setting()
{
	cin >> n;
	seq = vector<int>(n + 1);
	NGE = vector<int>(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> seq[i];
	}
}

void solve()
{
	for (int i = n; i >= 1; --i)
	{
		while (s.empty() == false && s.top() <= seq[i])
			s.pop();

		if (s.empty())
			NGE[i] = -1;
		else
			NGE[i] = s.top();

		s.push(seq[i]);
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << NGE[i] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	setting();
	solve();

	return 0;
}