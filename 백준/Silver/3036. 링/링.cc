#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

void solve()
{
	cin >> n;
	int num, temp;
	cin >> num;
	for (int i = 1; i < n; ++i)
	{
		cin >> temp;
		int g = gcd(num, temp);
		cout << num / g << "/" << temp / g << '\n';
	}
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