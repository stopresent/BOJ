#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int sum = 0;

void solve()
{
	for (int i = 0; i < 3; ++i)
	{
		int n;
		cin >> n;
		sum += n * (i + 1);
	}

	if (sum >= 10)
		cout << "happy";
	else
		cout << "sad";
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