#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<int, string> um;
unordered_map<string, int> um2;
string temp;

bool isNumber(string s)
{
	if (s.empty())
		return false;
	for (char c : s)
		if (!isdigit(c)) return false;
	return true;
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		um[i] = temp;
		um2[temp] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		// temp가 숫자인지 확인
		bool flag = isNumber(temp);
		// 숫자면 숫자로 전환
		if (flag)
		{
			int idx = stoi(temp);
			cout << um[idx] << '\n';
		}
		else
		{
			// 숫자가 아니면 um2 사용
			cout << um2[temp] << '\n';
		}
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