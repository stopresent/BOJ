#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3, s4;
void solve()
{
	cin >> s1 >> s2 >> s3 >> s4;
	s1 = s1 + s2;
	s3 = s3 + s4;
	long long a = 0, b = 0;
	for (int i = 0; i < s1.size(); ++i)
	{
		a += s1[i] - '0';
		a *= 10;
	}
	a /= 10;

	for (int i = 0; i < s3.size(); ++i)
	{
		b += s3[i] - '0';
		b *= 10;
	}
	b /= 10;
	
	cout << a + b;
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