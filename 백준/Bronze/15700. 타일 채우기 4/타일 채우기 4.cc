#include <iostream>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // 벽의 크기는 N * M
    // 2칸을 차지하는 타일의 최대 개수는 N * M // 2
    cout << (N * M) / 2 << endl;

    return 0;
}
