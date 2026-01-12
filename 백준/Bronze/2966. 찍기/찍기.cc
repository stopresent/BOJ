#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
string str;

void solve()
{
	cin >> n;
	cin >> str;
	string str1 = "ABC";
	string str2 = "BABC";
	string str3 = "CCAABB";
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == str1[i % 3])
			cnt1++;
		if (str[i] == str2[i % 4])
			cnt2++;
		if (str[i] == str3[i % 6])
			cnt3++;
	}

	int mx = max({ cnt1, cnt2, cnt3 });
	cout << mx << '\n';
	if (mx == cnt1)
		cout << "Adrian\n";
	if (mx == cnt2)
		cout << "Bruno\n";
	if (mx == cnt3)
		cout << "Goran\n";
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