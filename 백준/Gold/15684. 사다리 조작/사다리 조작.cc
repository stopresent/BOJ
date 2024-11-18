#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
vector<vector<bool>> ladder;
int result = 4; // 최대 가로선 3개까지 가능, 4 이상이면 불가능

// 사다리 검사 함수
bool check() {
    for (int i = 1; i <= N; i++) {
        int pos = i;
        for (int j = 1; j <= H; j++) {
            if (ladder[j][pos]) {
                pos++; // 오른쪽으로 이동
            } else if (pos > 1 && ladder[j][pos - 1]) {
                pos--; // 왼쪽으로 이동
            }
        }
        if (pos != i) return false;
    }
    return true;
}

// 백트래킹으로 가로선 추가
void dfs(int count, int x, int y) {
    if (count >= result) return; // 현재 결과보다 많은 경우는 확인할 필요 없음
    if (check()) {
        result = count;
        return;
    }
    if (count == 3) return; // 최대 3개까지 추가 가능

    for (int i = x; i <= H; i++) {
        for (int j = (i == x ? y : 1); j < N; j++) {
            if (!ladder[i][j] && !ladder[i][j - 1] && !ladder[i][j + 1]) {
                // 가로선 추가
                ladder[i][j] = true;
                dfs(count + 1, i, j + 2); // 현재 위치에 가로선 추가 후 탐색
                ladder[i][j] = false; // 가로선 제거 (백트래킹)
            }
        }
    }
}

int main() {
    cin >> N >> M >> H;
    ladder = vector<vector<bool>>(H + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    dfs(0, 1, 1);

    cout << (result <= 3 ? result : -1) << '\n';
    return 0;
}
