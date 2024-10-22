#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> wires(n);
    for (int i = 0; i < n; ++i) {
        cin >> wires[i].first >> wires[i].second;
    }

    // A 전봇대 기준으로 정렬
    sort(wires.begin(), wires.end());

    // B 전봇대의 위치에 대한 LIS 구하기
    vector<int> lis;
    for (int i = 0; i < n; ++i) {
        int pos = wires[i].second;
        // lis 벡터에서 pos가 들어갈 위치를 찾음
        auto it = lower_bound(lis.begin(), lis.end(), pos);
        if (it == lis.end()) {
            // 새로운 요소 추가
            lis.push_back(pos);
        } else {
            // 기존 위치를 pos로 갱신
            *it = pos;
        }
    }

    // 제거해야 하는 전깃줄의 개수는 전체 개수에서 LIS 길이를 뺀 값
    int result = n - lis.size();
    cout << result << endl;

    return 0;
}
