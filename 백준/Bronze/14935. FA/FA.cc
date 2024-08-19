#include <iostream>
#include <string>
#include <set>

using namespace std;

// F(x) 함수 구현
string F(string x) {
    int first_digit = x[0] - '0';  // 첫 번째 자릿수
    int num_digits = x.length();   // 자릿수
    int result = first_digit * num_digits;
    return to_string(result);      // 결과를 문자열로 반환
}

int main() {
    string x;
    cin >> x;

    set<string> seen;  // 이미 나온 값들을 추적하기 위한 집합

    while (true) {
        if (seen.find(x) != seen.end()) {
            // x가 이미 나온 값이라면 FA 수임
            cout << "FA" << endl;
            return 0;
        }
        seen.insert(x);  // 현재 값을 집합에 추가
        x = F(x);  // F(x) 계산
    }
    
    // 이론적으로 이 부분은 도달하지 않지만 구조상 필요함
    cout << "NFA" << endl;
    return 0;
}
