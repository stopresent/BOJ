#include <iostream>
using namespace std;

int main() {
    int sum, diff;
    cin >> sum >> diff;

    // 조건 1: (sum + diff)와 (sum - diff)가 둘 다 2로 나누어 떨어져야 함
    if ((sum + diff) % 2 != 0 || (sum - diff) % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    int a = (sum + diff) / 2;
    int b = (sum - diff) / 2;

    // 조건 2: a와 b는 모두 0 이상이어야 함
    if (a < 0 || b < 0) {
        cout << -1 << endl;
    } else {
        cout << a << " " << b << endl;
    }

    return 0;
}
