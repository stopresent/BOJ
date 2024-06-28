#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입력
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // 좌표 정렬
    sort(x.begin(), x.end());

    // 총 거리 합 계산
    long long total_distance = 0;
    long long sum_left = 0;
    long long sum_right = 0;

    // 모든 점의 x 좌표 합을 계산
    for (int i = 0; i < n; ++i) {
        sum_right += x[i];
    }

    for (int i = 0; i < n; ++i) {
        sum_right -= x[i];
        total_distance += sum_right - (n - i - 1) * x[i];
        total_distance += i * x[i] - sum_left;
        sum_left += x[i];
    }

    // 결과 출력
    cout << total_distance << endl;
    return 0;
}
