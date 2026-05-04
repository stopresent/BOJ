#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    bool flag = false;
    while(num > 0)
    {
        if (num % 10 == k) { answer = 1; flag = true; }
        else answer++;
        num /= 10;
    }
    if (!flag) answer = -1;
    return answer;
}