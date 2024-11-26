#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char c;

void solve()
{
	int cnt = 0;
	for (int i = 0; i < 6; ++i)
	{
		cin >> c;
		if (c == 'W')
			cnt++;
	}

	switch (cnt)
	{
	case 1:
	case 2:
		cout << 3;
		break;
	case 3:
	case 4:
		cout << 2;
		break;
	case 5:
	case 6:
		cout << 1;
		break;
	default:
		cout << -1;
		break;
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