#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string str, ret = "";

int cmp(char op)
{
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return -1;
}

void solve()
{
	cin >> str;

	stack<char> s;

	for (char ch : str)
	{
		if (isalpha(ch))
			ret += ch;
		else if (ch == '(')
			s.push(ch);
		else if (ch == ')')
		{
			while (!s.empty() && s.top() != '(')
			{
				ret += s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			while (!s.empty() && cmp(s.top()) >= cmp(ch))
			{
				ret += s.top();
				s.pop();
			}
			s.push(ch);
		}
	}

	while (!s.empty())
	{
		ret += s.top();
		s.pop();
	}

	cout << ret;
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