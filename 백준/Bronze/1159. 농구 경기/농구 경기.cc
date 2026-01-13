#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cnt(26);
bool flag = false;

void solve()
{
	cin >> n;
	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		cnt[name[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5)
		{
			flag = true;
			cout << char('a' + i);
		}
	}

	if (flag == false)
		cout << "PREDAJA";
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