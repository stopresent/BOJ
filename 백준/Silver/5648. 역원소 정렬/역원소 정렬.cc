#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

long long reverse(long long num)
{
	long long ret = 0;

	while (num > 0)
	{
		ret = ret * 10 + num % 10;
		num /= 10;
	}

	return ret;
}

void solve()
{
	cin >> n;
	vector<long long> arr(n);
	long long temp = 0;
	for (long long i = 0; i < n; i++)
	{
		cin >> temp;
		arr[i] = reverse(temp);
	}

	sort(arr.begin(), arr.end());

	for (long long i = 0; i < n; i++)
		cout << arr[i] << '\n';
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