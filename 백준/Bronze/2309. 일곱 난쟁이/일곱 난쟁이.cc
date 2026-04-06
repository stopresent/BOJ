#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void solve() {
	int num, sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> num;
		sum += num;
		v.push_back(num);
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - v[i] - v[j] == 100)
			{
				v.erase(v.begin() + j);
				v.erase(v.begin() + i);
				sort(v.begin(), v.end());
				for (int k = 0; k < 7; k++)
					cout << v[k] << '\n';
				return;
			}
		}
	}
}

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	solve();

	return 0;
}