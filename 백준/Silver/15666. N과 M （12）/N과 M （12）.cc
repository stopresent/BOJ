#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> nums;
vector<int> seq;

void dfs(int idx, int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << seq[i] << (i + 1 == M ? '\n' : ' ');
        }
        return;
    }

    int prev = -1;
    for (int i = idx; i < N; ++i)
    {
        if (nums[i] == prev)
        {
            continue;
        }
        prev = nums[i];

        seq.push_back(nums[i]);
        dfs(i, depth + 1);
        seq.pop_back();
    }
}

void solve()
{
    cin >> N >> M;
    nums.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    dfs(0, 0);
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
