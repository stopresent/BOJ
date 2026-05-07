#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> dots) {
    
    vector<vector<int>> v = { { 0, 1, 2, 3 }, { 0, 2, 1, 3 }, { 0, 3, 1, 2 } };
    for (int i = 0; i < v.size(); i++)
    {
        int dx1 = dots[v[i][0]][0] - dots[v[i][1]][0];
        int dy1 = dots[v[i][0]][1] - dots[v[i][1]][1];
        int dx2 = dots[v[i][2]][0] - dots[v[i][3]][0];
        int dy2 = dots[v[i][2]][1] - dots[v[i][3]][1];
        
        if (dy1 * dx2 == dy2 * dx1) return 1;
    }
    
    return 0;
}