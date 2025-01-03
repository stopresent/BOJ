#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, q1, q2, q3, q4, axis;

void solve()
{
	cin >> n;
	int a, b;
	while (n--)
	{
		cin >> a >> b;
		if (a == 0 || b == 0)
			axis++;
		else if (a > 0 && b > 0)
			q1++;
		else if (a < 0 && b > 0)
			q2++;
		else if (a < 0 && b < 0)
			q3++;
		else if (a > 0 && b < 0)
			q4++;
	}

	cout << "Q1: " << q1 << '\n';
	cout << "Q2: " << q2 << '\n';
	cout << "Q3: " << q3 << '\n';
	cout << "Q4: " << q4 << '\n';
	cout << "AXIS: " << axis << '\n';
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