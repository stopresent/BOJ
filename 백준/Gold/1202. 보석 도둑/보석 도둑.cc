#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int n, k;
const int MAX = 300010;
pair<int, int> jewerly[MAX];
int bag[MAX];
priority_queue<int, vector<int>, less<int>> q;

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> jewerly[i].first >> jewerly[i].second;
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> bag[i];
    }

    sort(jewerly, jewerly + n);
    sort(bag, bag + k);

    int idx = 0;
    long long ret = 0;

    for (int i = 0; i < k; ++i)
    {
        while (idx < n && bag[i] >= jewerly[idx].first)
        {
            q.push(jewerly[idx].second);
            idx++;
        }
        if (q.empty() == false)
        {
            ret += q.top();
            q.pop();
        }
    }

    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);

    solve();

    return 0;
}