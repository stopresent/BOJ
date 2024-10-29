#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long a, b;
	cin >> a >> b;

	queue<long long> q;
	map<long long, long long> m;
	q.push(a);
	m[a] = 1;
	while (q.empty() == false)
	{
		long long here = q.front();
		q.pop();

		for (long long next : {here * 2, here * 10 + 1})
		{
			if (next == b)
			{
				cout << m[here] + 1;
				return;
			}
			else if (next < b)
			{
				q.push(next);
				if (m[next] == 0)
					m[next] = m[here] + 1;
				else
					m[next] = min(m[next], m[here] + 1);
			}
		}
	}

	cout << -1;
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