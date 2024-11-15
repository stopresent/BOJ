#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // 파스칼의 삼각형 DP 테이블
    vector<vector<int>> pascal(n, vector<int>(n, 1));

    // DP 테이블 초기화
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < i; j++) {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }

    // 출력 (n번째 줄의 k번째 숫자)
    cout << pascal[n-1][k-1] << '\n';

    return 0;
}
