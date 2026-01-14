#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s, ret;
int cnt[200], flag;
char mid;

void solve()
{
	cin >> s;
	for (char c : s) cnt[c]++;
	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (cnt[i])
		{
			if (cnt[i] & 1)
			{
				flag++;
				mid = char(i);
				cnt[i]--;
			}
			if (flag == 2) break;
			for (int j = 0; j < cnt[i]; j += 2)
			{
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}
	if (mid)
		ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2)
		cout << "I'm Sorry Hansoo" << '\n';
	else
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