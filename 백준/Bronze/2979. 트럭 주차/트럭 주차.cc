#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int A, B, C, sum = 0;
int arr[104];
void solve() {
	cin >> A >> B >> C;
	int in, out;
	for (int i = 0; i < 3; i++)
	{
		cin >> in >> out;
		arr[in]++;
		arr[out]--;
	}

	int cur = 0;
	for (int i = 0; i < 100; i++)
	{
		cur += arr[i];
		if (cur == 1) sum += A;
		else if (cur == 2) sum += B * 2;
		else if (cur == 3) sum += C * 3;
	}

	cout << sum;
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}