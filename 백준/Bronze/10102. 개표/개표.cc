#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve()
{
	cin >> n;
	cin >> s;
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'A')
			a++;
		else
			b++;
	}

	if (a == b)
		cout << "Tie";
	else if (a > b)
		cout << "A";
	else
		cout << "B";
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