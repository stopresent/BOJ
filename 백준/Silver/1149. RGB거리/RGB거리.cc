#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int house[1001][3];
int N;
int cost[3];
void solve()
{
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
        house[i][2] = min(house[i - 1][1], house[i - 1][0]) + cost[2];
    }
    cout << min(house[N][2], min(house[N][0], house[N][1]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);

    solve();
}