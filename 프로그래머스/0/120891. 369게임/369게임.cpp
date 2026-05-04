#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    while (order > 0)
    {
        int a = order % 10;
        if (a == 3 || a == 6 || a == 9) answer++;
        order /= 10;
    }
    return answer;
}