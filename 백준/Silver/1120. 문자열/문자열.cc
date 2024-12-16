#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int ret = INT_MAX;
void solve()
{
	cin >> s1 >> s2;
	if (s1.size() > s2.size())
		swap(s1, s2);

	int gap = s2.size() - s1.size();
	for (int i = 0; i <= gap; ++i)
	{
		int temp = 0;
		for (int j = i; j < i + s1.size(); ++j)
		{
			if (s2[j] - s1[j - i] != 0)
				temp++;
		}
		ret = min(ret, temp);
	}

	cout << ret;
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