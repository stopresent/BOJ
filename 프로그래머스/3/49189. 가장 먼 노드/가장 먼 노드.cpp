#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> dist;
vector<int> visited;
vector<vector<int>> v;
int answer = 1;
int solution(int n, vector<vector<int>> edge) {
    dist = vector<int>(n + 1);
    visited = vector<int>(n + 1);
    v = vector<vector<int>>(n + 1);
    
    for (int i = 0; i < edge.size(); i++)
    {
        int s = edge[i][0];
        int e = edge[i][1];
        
        v[s].push_back(e);
        v[e].push_back(s);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        
        for (int i : v[f])
        {
            if (visited[i]) continue;
            visited[i] = 1;
            q.push(i);
            dist[i] = dist[f] + 1;
        }
    }
    for (int i = 0; i < dist.size(); i++)
    {
        //cout << dist[i] << " ";
    }
    sort(dist.begin(), dist.end(), greater<int>());
    
    int a = dist[0];
    for (int i = 1; i < dist.size(); i++)
    {
        if (dist[i] == a) answer++;
        else break;
    }
    
    return answer;
}