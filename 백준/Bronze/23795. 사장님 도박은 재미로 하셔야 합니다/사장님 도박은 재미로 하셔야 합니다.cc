#include <iostream>
using namespace std;

int main() {
    int bet;
    long long total = 0;  // 총합을 저장할 변수, 오버플로우를 방지하기 위해 long long 사용

    while (true) {
        cin >> bet;
        if (bet == -1) {
            break;  // -1이 입력되면 루프 종료
        }
        total += bet;  // 배팅 금액을 총합에 더함
    }

    cout << total << endl;  // 총합 출력

    return 0;
}
