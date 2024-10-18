#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int N, M, X;
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> rev_graph[1001];
int dist_to_X[1001];
int dist_from_X[1001];

void dijkstra(int start, vector<pair<int, int>> graph[], int dist[]) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    fill(dist, dist + N + 1, INF);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int distance = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < distance) continue;
        for (auto edge : graph[now]) {
            int next = edge.first;
            int cost = distance + edge.second;
            if (dist[next] > cost) {
                dist[next] = cost;
                pq.push({cost, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        rev_graph[v].push_back({u, w});
    }

    dijkstra(X, rev_graph, dist_to_X); // 각 마을에서 X까지의 최단 거리
    dijkstra(X, graph, dist_from_X);   // X에서 각 마을까지의 최단 거리

    int max_time = 0;
    for (int i = 1; i <= N; i++) {
        int total_time = dist_to_X[i] + dist_from_X[i];
        if (total_time > max_time) {
            max_time = total_time;
        }
    }

    cout << max_time << "\n";

    return 0;
}
