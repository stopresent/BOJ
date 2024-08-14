#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    int total_time = 0;

    if (A < 0) {
        // 고기가 얼어 있는 경우
        total_time += (-A) * C;  // A에서 0까지 데우는 시간
        total_time += D;         // 해동하는 시간
        total_time += B * E;     // 0에서 B까지 데우는 시간
    } else {
        // 고기가 얼어있지 않은 경우
        total_time += (B - A) * E;  // A에서 B까지 데우는 시간
    }

    cout << total_time << endl;

    return 0;
}
