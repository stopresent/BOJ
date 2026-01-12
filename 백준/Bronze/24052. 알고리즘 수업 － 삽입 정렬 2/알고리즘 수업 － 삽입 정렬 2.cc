#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, k;
int insertion_sort(vector<int>& v)
{
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		int pos = i - 1;
		int temp = v[i];

		while (0 <= pos && temp < v[pos])
		{
			v[pos + 1] = v[pos];
			pos--;
			cnt++;
			if (cnt == k)
				return cnt;
		}

		if ((pos + 1) != i)
		{
			v[pos + 1] = temp;
			cnt++;
			if (cnt == k)
				return cnt;
		}
	}

	return cnt;
}

void solve()
{
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int cnt = insertion_sort(v);
	if (cnt < k)
		cout << -1;
	else
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
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