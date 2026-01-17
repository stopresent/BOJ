#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, ret;
string s;

void solve()
{
	cin >> n;
	while (n--)
	{
		cin >> s;
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			st.push(s[i]);
			while (st.size() > 1)
			{
				char t = st.top();
				st.pop();
				if (st.top() == t)
					st.pop();
				else
				{
					st.push(t);
					break;
				}
			}
		}

		if (st.size() == 0) ret++;
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