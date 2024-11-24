#include <iostream>
#include <algorithm> // std::gcd 사용
using namespace std;

int main() {
    string input;
    cin >> input;

    // 입력 파싱
    size_t colonPos = input.find(':');
    int n = stoi(input.substr(0, colonPos));
    int m = stoi(input.substr(colonPos + 1));

    // 최대공약수 계산
    int gcd = __gcd(n, m);

    // 약분된 값 출력
    cout << n / gcd << ":" << m / gcd << endl;

    return 0;
}
