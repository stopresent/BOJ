#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;

	vector <int> v;
	for (int i = 0; i < n; i++) 
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	set <string> s;
	do 
	{
		string res;
		for (int i = 0; i < k; i++) 
		{
			res += to_string(v[i]);
		}
		s.insert(res);
	} while (next_permutation(v.begin(), v.end()));
	cout << s.size();
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