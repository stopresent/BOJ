#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ret;
vector<char> v;
vector<bool> visited(10);

void dfs(int L, string cur)
{
    if (L == n + 1)
    {
        ret.push_back(cur);
        return;
    }

    for (int i = 0; i <= 9; ++i)
    {
        if (visited[i])
            continue;
        if (L == 0 || (v[L - 1] == '<' && cur.back() - '0' < i) || (v[L - 1] == '>' && cur.back() - '0' > i))
        {
            visited[i] = true;
            dfs(L + 1, cur + to_string(i));
            visited[i] = false;
        }
    }
}

void solve()
{
	cin >> n;
    v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

    dfs(0, "");
    sort(ret.begin(), ret.end());
    cout << ret.back() << '\n';
    cout << ret.front() << '\n';	
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