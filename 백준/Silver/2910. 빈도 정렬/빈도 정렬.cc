#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, c, temp;
vector<pair<int, int>> v;
map<int, int> m, m_first; // m : 숫자, 개수 m_first : 숫자, 처음 나온 인덱스

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) // 빈도가 같다면
		return m_first[a.second] < m_first[b.second]; // 먼저 만난순
	return a.first > b.first; // 빈도가 높은순으로 정렬
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

	for (auto it : m)
		v.push_back({ it.second, it.first }); // 빈도, 숫자

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