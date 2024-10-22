#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

struct Edge {
    int from, to, cost;
};

int TC, N, M, W;
vector<Edge> edges;
int dist[501];

bool bellman_ford() {
    fill(dist, dist + N + 1, 0);
    for (int i = 1; i <= N; i++) {
        for (auto edge : edges) {
            int from = edge.from;
            int to = edge.to;
            int cost = edge.cost;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                if (i == N) {
                    return true; // 음수 사이클 존재
                }
            }
        }
    }
    return false; // 음수 사이클 없음
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        edges.clear();

        // 도로 정보 입력
        for (int i = 0; i < M; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T}); // 무향 그래프이므로 반대 방향도 추가
        }

        // 웜홀 정보 입력
        for (int i = 0; i < W; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, -T}); // 시간이 줄어드므로 가중치는 -T
        }

        bool hasNegativeCycle = bellman_ford();
        if (hasNegativeCycle) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
