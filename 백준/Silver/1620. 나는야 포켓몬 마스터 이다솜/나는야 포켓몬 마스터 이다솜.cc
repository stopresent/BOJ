#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
string input;
map<string, int> m1;
map<int, string> m2;

int main() {
	FILE* stream;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(&stream, "input.txt", "rt", stdin);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		m1[input] = i;
		m2[i] = input;
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> input;
		try
		{
			int num = stoi(input);
			cout << m2[num] << '\n';
		}
		catch (const std::exception&)
		{
			cout << m1[input] << '\n';
		}
	}

	return 0;
}