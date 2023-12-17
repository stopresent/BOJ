#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n;
stack<int> s;
queue<int> q;
vector<char> ans;

void solve()
{
	cin >> n;

	int temp;
	for (int i = 1; i <= n; ++i)
	{
		cin >> temp;
		q.push(temp);
	}

	int pos = 1;
	while (!q.empty())
	{
		if (!s.empty() && s.top() == q.front())
		{
			s.pop();
			q.pop();
			ans.push_back('-');
		}
		else if (pos <= q.front())
		{
			while (pos <= q.front())
			{
				s.push(pos++);
				ans.push_back('+');
			}
		}
		else
		{
			cout << "NO";
			return;
		}
	}

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';
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