#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<pair<int, int>> points;
double answer;

void dfs(int idx, int cnt, int sx, int sy, vector<int>& selected) {
    if (cnt == n / 2) {
        int tx = 0, ty = 0;
        for (int i = 0; i < n; ++i) {
            if (selected[i]) {
                tx += points[i].first;
                ty += points[i].second;
            } else {
                tx -= points[i].first;
                ty -= points[i].second;
            }
        }
        double len = sqrt(1.0 * tx * tx + 1.0 * ty * ty);
        answer = min(answer, len);
        return;
    }
    if (idx == n) return;
    // 선택
    selected[idx] = 1;
    dfs(idx + 1, cnt + 1, sx + points[idx].first, sy + points[idx].second, selected);
    selected[idx] = 0;
    // 미선택
    dfs(idx + 1, cnt, sx, sy, selected);
}

void solve()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        points.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> points[i].first >> points[i].second;
        }
        answer = 1e18;
        vector<int> selected(n, 0);
        // 첫 번째 점은 항상 선택(중복 방지, 대칭 제거)
        selected[0] = 1;
        dfs(1, 1, points[0].first, points[0].second, selected);
        cout << fixed << setprecision(12) << answer << '\n';
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