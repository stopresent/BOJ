#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	int n, m;
	cin >> n >> m;
	vector<long> S(n, 0);
	vector<long> C(m, 0);
	long answer = 0;
	cin >> S[0];

	for (int i = 1; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}
	for (int i = 0; i < n; i++)
	{
		int remainder = S[i] % m;
		if (remainder == 0)
			answer++;
		C[remainder]++;
	}

	for (int i = 0; i < m; i++)
	{
		if (C[i] > 1)
			answer += (C[i] * (C[i] - 1)) / 2;
	}
	cout << answer;
}