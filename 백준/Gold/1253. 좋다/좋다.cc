#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	int N;
	cin >> N;
	vector<int> A(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int result = 0;

	for (int k = 0; k < N; k++)
	{
		long find = A[k];
		int i = 0;
		int j = N - 1;

		while (i < j)
		{
			if (A[i] + A[j] == find)
			{
				if (i != k && j != k) {
					result++;
					break;
				}
				else if (i == k)
					i++;
				else if (j == k)
					j--;
			}
			else if (A[i] + A[j] < find)
				i++;
			else
				j--;
		}
	}

	cout << result << "\n";

	return 0;
}