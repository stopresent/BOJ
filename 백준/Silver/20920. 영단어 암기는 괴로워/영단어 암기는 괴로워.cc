#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second == b.second && a.first.size() == b.first.size())
		return a.first < b.first; // 여기서 사전순으로
	else if (a.second == b.second && a.first.size() > b.first.size())
		return a.first.size() > b.first.size();
	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	string inputString;
	map<string, int> m;

	for (int i = 0; i < N; i++)
	{
		cin >> inputString;

		if (inputString.length() < M)
			continue;

		m[inputString]++;
	}

	vector<pair<string, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << "\n";
	}

}
