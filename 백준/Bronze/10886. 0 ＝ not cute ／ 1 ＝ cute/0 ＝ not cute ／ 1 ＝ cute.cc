#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
void solve()
{
	cin >> n;
	int a = 0, b = 0, temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (temp == 0) a++;
		else b++;
	}
	if (a > b)
		cout << "Junhee is not cute!";
	else
		cout << "Junhee is cute!";
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