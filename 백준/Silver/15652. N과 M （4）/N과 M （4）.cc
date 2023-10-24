#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v = { 0, };

void dfs(int pre, int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i < pre)
            continue;

        v[depth] = i;
        dfs(i, depth + 1);
    }
}

int main() {
    cin >> n >> m;

    v.resize(n + 1);

    dfs(1, 0);
}