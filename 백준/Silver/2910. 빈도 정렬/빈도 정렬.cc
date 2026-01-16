#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, c, temp;
map<int, int> m, m_first;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) // 빈도가 같을 경우
		return m_first[a.second] < m_first[b.second];
	return a.first > b.first;
}

void solve()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		m[temp]++;
		if (m_first[temp] == 0)
			m_first[temp] = i + 1;
	}
	for (auto i : m)
		v.push_back({ i.second, i.first });
	sort(v.begin(), v.end(), cmp);
	for (auto i : v)
	{
		for (int j = 0; j < i.first; j++)
			cout << i.second << ' ';
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